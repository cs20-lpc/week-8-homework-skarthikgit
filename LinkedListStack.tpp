template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    Node<T> *temp = nullptr;
    while (top) {
        temp = top;
        top = top->next;
        delete temp;
    }
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    if (copyObj.top == nullptr) {
        top = nullptr;
        return;
    }

    top = new Node<T> (copyObj.top->data);
    Node<T> *destPtr = top;
    Node<T> *srcPtr = copyObj.top->next;

    while (srcPtr) {
        destPtr->next = new Node<T>(srcPtr->data);
        destPtr = destPtr->next;
        srcPtr = srcPtr->next;
    }
    
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    if ( isEmpty())
        throw string("peek:error - Stack List is empty");
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if ( isEmpty())
        throw string("pop:error - Stack List is empty");

    Node<T> *currTop = top;
    top = top->next;
    delete currTop;
    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    Node<T> *newNode = new Node<T>(elem);
    newNode->next = top;
    top = newNode;
    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if ( isEmpty())
        throw string("rotate:error - Stack List is empty"); else if (this->length == 1) {
        return;
    }
    else if (dir == Stack<T>::RIGHT) {
        Node<T> *tmpTop = top;
        Node<T> *curr = top->next;

        while (curr->next) {
            curr = curr->next;
        }

        curr->next = tmpTop;
        tmpTop->next = nullptr;

    }
    else if (dir == Stack<T>::LEFT) {
        Node<T> *curr = top;
        while (curr->next->next) {
            curr = curr->next;
        }

        Node<T> *lastNode = curr->next;
        curr->next = nullptr;
        lastNode->next = top;
        top = lastNode;
    }
    else {
        throw string("rotate:error - unknown direction");
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}

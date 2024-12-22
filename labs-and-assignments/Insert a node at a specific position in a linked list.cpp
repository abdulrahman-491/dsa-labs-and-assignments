SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    
    if (llist == nullptr) return llist;
    
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    
    if (llist->next == nullptr)
    {
        node->next = llist;
        llist = node;
        return llist;
    }
    
    SinglyLinkedListNode* temp = llist;
    for (int i = 1; i <= position - 1; i++)
        temp = temp->next;
    
    node->next = temp->next;
    temp->next = node;
    return llist;

}
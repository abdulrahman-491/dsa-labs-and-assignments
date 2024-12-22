    Node * insert(Node * root, int data) {
        
        Node* node = new Node(data);
        if (root == nullptr){ 
            root = node;
            return root;
        }
        
        Node* temp = root;
        while (((temp->right != nullptr) && (data > temp->data)) || ((temp->left != nullptr) && (data <= temp->data)))
        {
            if (data <= temp->data)
                temp = temp->left;
            else 
                temp = temp->right;
        }
        
        if (data <= temp->data)
            temp->left = node;
        else 
            temp->right = node;

        return root;
    }
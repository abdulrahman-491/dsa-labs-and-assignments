	bool checkBST(Node *root, int minLimit, int maxLimit)
    {
        if (root == nullptr) return true;
        
        
        if (checkBST(root->left, minLimit, root->data) && checkBST(root->right, root->data, maxLimit) && (root->data < maxLimit) && (root->data > minLimit))
        {
             return true;
        }
        else
            return false;
           
    }


    bool checkBST(Node* root) {
        
        return checkBST(root, 0, 10000);
            
    }
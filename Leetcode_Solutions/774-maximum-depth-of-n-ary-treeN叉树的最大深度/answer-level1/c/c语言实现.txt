```
int traverse(struct Node* root){
    if (!root->numChildren) return 0;
    int deeps[root->numChildren];
    int maxDeep = 0;
    for (int i = 0; i< root->numChildren; i++){
        deeps[i] = traverse(root->children[i]);
    }
    for (int i = 0; i< root->numChildren; i++){
        if (maxDeep<deeps[i])
            maxDeep = deeps[i];   
    }
    maxDeep += 1;
    return maxDeep;
}

int* maxDepth(struct Node* root) {
    if(!root) return 0;
    int depth = traverse(root) + 1;
    return depth;
}
```

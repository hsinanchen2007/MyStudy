```
struct Node* connect(struct Node* root) {
    if(root == NULL)
        return NULL;

	struct Node *queue[10000] = {0};
    int front = 0, rear = 0;
    queue[root ? rear++ : rear] = root;     //根节点入队

    while(front < rear)
    {
        int size = rear - front;            //当前层次节点个数
        for(int i = 0; i < size; i++)
        {
            if(queue[front]->left)                          //左孩子入队
                queue[rear++] = queue[front]->left;
            if(queue[front]->right)                         //右孩子入队
                queue[rear++] = queue[front]->right;
            
            if(i == size - 1)
                queue[front]->next = NULL;          //如果为当前层次最后一个节点，将其next指向NULL
            else
                queue[front]->next = queue[front + 1];
            front++;
        }
    }
    return root;
}
```

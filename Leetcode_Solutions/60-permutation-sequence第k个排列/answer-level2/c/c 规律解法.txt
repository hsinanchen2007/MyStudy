```
struct Node {
    int val;
    struct Node* next;
};
struct Node* creatNode(int k) {
    struct Node* head = malloc(sizeof(struct Node));
    head->next = NULL;
    struct Node* temp;
    for (int i = k; i > 0; i--) {
        struct Node* mid = malloc(sizeof(struct Node));
        mid->val = i;
        temp = head->next;
        head->next = mid;
        mid->next = temp;
    }
    return head;
}
int deleteNode(struct Node* head, int index) {
    int res;
    struct Node *temp, *mid;
    temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    mid = temp->next;
    res = mid->val;
    temp->next = mid->next;
    free(mid);
    return res;
}
char * getPermutation(int n, int k){
    char* res = malloc(sizeof(char) * (n + 1));
    int count = 0;
    memset(res, 0, sizeof(char) * (n + 1));
    if (n == 0) return res;
    int flag[10] = {0};
    flag[0] = 1;
    for (int i = 1; i < 10; i++) {
        flag[i] = flag[i - 1] * i;
    }
    struct Node* head = creatNode(n);
    int num = n;
    while (k > 1 && num > 1) {
        int temp = (k - 1) / flag[num - 1] + 1;
        k %= flag[num - 1];
        if (k == 0) k = flag[num - 1];
        res[count++] = deleteNode(head, temp) + '0';
        num--;
    }
    while (count < n) {
        res[count++] = deleteNode(head, 1) + '0';
    }
    free(head);
    return res;
}
```

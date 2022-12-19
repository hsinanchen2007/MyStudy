- 用栈来实现： 
- 从右往左遍历数组
- 如果栈为空  ：就赋值为0，并把当前元素压栈
- 如果栈不为空：就依次出栈，找到大于当前元素的值，直到栈为空
```
int* nextLargerNodes(struct ListNode* head, int* returnSize){
    if (head == NULL) return NULL;
    int *ret_arr = (int *)calloc(10240, sizeof(int));
    struct ListNode* p1 = head;
    int i = 0, max = 0, top = -1;
    while (p1) ret_arr[i++] = p1->val, p1 = p1->next;
    int *stack = (int*)calloc(i, sizeof(int));
    * returnSize = i--;               //上面为初始化部分    

    while (i > -1) {
        if (top == -1) { //栈为空
            stack[++top] = ret_arr[i];
            ret_arr[i--] = 0;
        }else{
            while (top > -1 && stack[top] <= ret_arr[i]) --top; //找到最近最大的值
            if (top == -1) { //栈为空
                stack[++top] = ret_arr[i];
                ret_arr[i--] = 0;
            }else{ 
                stack[top+1] = ret_arr[i];//把当前元素入栈
                ret_arr[i--] = stack[top++];
            }
        }
    }
    return ret_arr;
}
```

# 思路：
1）递一下归！！
![image.png](https://pic.leetcode-cn.com/bc26bddc5e109d12585ca9c681273870ef000551b90b89db89865e08b41abcd8-image.png)
# 代码：
```
int* reversePrint(struct ListNode* head, int* returnSize){
    if(head == NULL){
        *returnSize = 0;
        return malloc(sizeof(int) * 10000);
    }
    int *ans = reversePrint(head->next, returnSize);
    ans[(*returnSize)++] = head->val;
    return ans;
}
```

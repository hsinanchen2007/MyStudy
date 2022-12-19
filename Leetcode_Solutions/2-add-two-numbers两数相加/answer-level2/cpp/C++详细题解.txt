### 思路
1. 用queue来做，同位相加
2. 将位数较少的数字在高位补零，使两个数字长度相同
3. 注意进位的话需要在tail添加一个节点。
```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        queue <int> list1;
        queue <int> list2;
        queue <int> ans;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *ex = new ListNode(1);
        int size1 = 0;
        int size2 = 0;
        while(temp1){
            ++ size1;
            temp1 = temp1 -> next;
        }
        while(temp2){
            ++ size2;
            temp2 = temp2 -> next;
        }
        ListNode *head = size1 < size2 ? l2 : l1;
        ListNode *copyhead = head;
        for(int i = size1; i > 0; -- i){
            list1.push(l1 -> val);
            l1 = l1 -> next;
        }
        for(int j = size2; j > 0; -- j){
            list2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int diff = abs(size1 - size2);
        if(size1 > size2)   for(; diff > 0; -- diff)    list2.push(0);
        else    for(; diff > 0; -- diff)    list1.push(0);
        int q = list1.size();
        int flag = 0;
        for(q; q > 0; -- q){
            int sum = list1.front() + list2.front() + flag;
            flag = 0;
            list1.pop();
            list2.pop();
            if(sum > 9){
                sum -= 10;
                flag = 1;
            }
            ans.push(sum);
        }
        for(int len = ans.size() - 1; len > 0; -- len){
            copyhead -> val = ans.front();
            ans.pop();
            copyhead = copyhead -> next;
        }
        copyhead -> val = ans.front();
        if(flag == 1)   copyhead -> next = ex;
        return head;
    }
};
```
### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        string str1 = "";
        string str2 = "";
        while (l1) {
            str1.insert(0, 1, l1->val + '0');
            l1 = l1->next;
        }
        while (l2) {
            str2.insert(0, 1, l2->val + '0');
            l2 = l2->next;
        }

        int flag = 0;
        int result = 0;
        int num2 = 0;
        int num1 = 0;
        int i = str1.size() - 1;
        int j = str2.size() - 1;
        string sum = "";
        for (; i >= 0; i--) {
            num1 = str1[i] - '0';
            if(j >= 0) {
                num2 = str2[j] - '0';
                j--;
            }
            result = num1 + num2 + flag;
            flag = result / 10;
            result = result % 10;
            //printf("--1-->%d, %d\n", flag, result);
            sum.insert(0, 1, result + '0');
            num1 = 0;
            num2 = 0;
        }

        for (; j >= 0; j--) {
            num2 = str2[j] - '0';
            //printf("--3-->%d\n", num2);
            result = num2 + flag;
            flag = result / 10;
            result = result % 10;
            sum.insert(0, 1, result + '0');
        }
        if (flag) {
            sum.insert(0, 1, flag + '0');
        }
        //printf("---->%s\n", sum.c_str());
        ListNode *root = new ListNode(0);
        ListNode *pre = root;
        for (int i = sum.size() - 1; i >= 0; i--) {
            int data = sum[i] - '0';
            ListNode* tmp = new ListNode(data);
            pre->next = tmp;
            pre = tmp;
        }
        return root->next;
    }
};
```
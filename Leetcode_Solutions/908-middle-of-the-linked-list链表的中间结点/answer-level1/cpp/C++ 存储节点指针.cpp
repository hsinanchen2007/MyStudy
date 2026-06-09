![image.png](https://pic.leetcode-cn.com/560015dfccf2f48ad2f443d31affe72e02aba38449b13b29178f4066dac8a571-image.png)
解题思路：用vector保存每个节点的指针，直接返回一半处的指针。
```
       ListNode* middleNode(ListNode* head) {
        vector<ListNode*> middle;
        while (head != 0) {
            middle.push_back(head);
            head = head->next;
        }
        return middle[middle.size()/2];
    }
```



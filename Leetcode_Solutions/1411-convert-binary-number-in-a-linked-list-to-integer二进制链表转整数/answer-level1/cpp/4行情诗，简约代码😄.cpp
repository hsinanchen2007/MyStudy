偏爱**优美**的代码风格~~~
```
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = head->val;
        while(head = head->next)
            res = (res << 1) | head->val;
        return res;
    }
};
```
![微信图片_20200107143627.png](https://pic.leetcode-cn.com/a19b2dbc145c9dea604b238769ae727f8a4d6694287b8b4a62dcacd28a4a0c61-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200107143627.png)

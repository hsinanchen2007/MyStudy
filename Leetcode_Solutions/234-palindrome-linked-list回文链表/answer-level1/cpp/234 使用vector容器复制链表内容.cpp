
### 代码

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head==nullptr || head->next==nullptr)
            return true;
        int i = 0;
        vector<int> list;
        while (head != nullptr) {
            list.push_back(head->val);
            i++;
            head = head->next;
        }
        int length = list.size();
        for (int j=0; j<length/2; j++) {
            if (list[j] != list[length-1-j])
                return false;
        }
        return true;
       
    }
};
```
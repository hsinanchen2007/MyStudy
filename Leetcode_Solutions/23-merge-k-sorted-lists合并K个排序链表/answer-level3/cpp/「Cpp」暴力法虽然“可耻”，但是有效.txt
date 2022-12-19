### 解题思路

思路为：

1. 遍历所有元素，O(n)
2. 排序，O(n log n)
3. 从数组中构建链表 O(n)

不是原地的方法，因此空间复杂度比较高

**注意**测试集里会有`[]`,`[[],[]]`这种专门数据集，因此遍历所有链表得到的数组，需要先判断下大小，如果为0.就直接返回。

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
//构建新的数组        
        vector<int> vec;
        ListNode *head;
        for(int i = 0; i < lists.size(); i++){
            head = lists[i];
            while ( head != nullptr){
                vec.push_back(head->val);
                head=head->next;
            }

        }
//元素为空，后续就没有必要了
        if (vec.size() == 0 ) return nullptr;
//排序，重构链表
        sort(vec.begin(), vec.end());
        ListNode *prev = nullptr, *curr;
        for (int i = vec.size()-1; i >= 0; i--){
            curr = new ListNode(vec[i]);
            curr->next = prev;
            prev = curr;

        }
        return curr;

    }
};
```
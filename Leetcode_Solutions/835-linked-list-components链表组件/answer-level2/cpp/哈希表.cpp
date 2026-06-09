### 解题思路
利用哈希表储存G中的值，节约寻找时间。遍历时附加一个状态值flag，表示前一个结点值是否为G集合中的值，flag由0到1时需要返回结果需要自增。
![捕获.PNG](https://pic.leetcode-cn.com/6d058273ff3f936a347a90ddc631366f1942e8f21e2c33c3daa11b7579269d03-%E6%8D%95%E8%8E%B7.PNG)



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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int, int> umap;
        for(int i = 0; i < G.size(); i++)
            umap[G[i]] = 1;
        int flag = 0;
        int num = 0;
        ListNode* iter = head;
        while(iter != NULL)
        {
            if(umap.find(iter->val) != umap.end() && flag == 0)
            {
                flag = 1;
                num++;
            }
            else if(umap.find(iter->val) == umap.end() && flag == 1)
            {   flag = 0;   }
            iter = iter->next;
        }
        return num;
    }
};
```
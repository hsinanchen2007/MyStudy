### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    struct ListNode {
        int val, k;
        ListNode *next;
        ListNode(int x, int y) : val(x), k(y), next(NULL) {}
    };
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int> > ans;
        if(people.size() == 0) return ans;
        sort(people.begin(), people.end(), cmp);
        ListNode* Head = new ListNode(0, 0);
        Head->next = new ListNode(people[0][0], people[0][1]);
        ListNode* tail = Head->next;
        for(int i=1; i<people.size(); i++){
            int h = people[i][0], k = people[i][1];
            ListNode* cur = new ListNode(h, k);
            ListNode* tmp=Head;
            while(k--){
                tmp = tmp->next;
            }
            cur->next = tmp->next;
            tmp->next = cur;    
        }

        Head = Head->next;
        while(Head){
            vector<int> tmp;
            tmp.push_back(Head->val);
            tmp.push_back(Head->k);
            ans.push_back(tmp);
            Head = Head->next;
        }
        return ans;
    }
    static bool cmp (vector<int> v1, vector<int> v2) { 
        if (v1[0] == v2[0]) return v1[1] < v2[1];
        return v1[0] > v2[0]; 
    }//升序排列
};
```
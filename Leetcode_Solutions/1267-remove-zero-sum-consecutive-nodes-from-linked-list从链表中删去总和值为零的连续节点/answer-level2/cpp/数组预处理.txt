1. 将链表转化为数组，进行预处理；
2. 找到所有可能存在零的区间，然后对这些区间进行排序和合并；
3. 将合并的区间进行预处理，同时进行恢复链表；
```
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
    static bool cmp(pair<int,int> & a,pair<int,int> &b){
        return a.first < b.first;
    }
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<ListNode *> list;
        
        if(!head){
            return head;
        }
        for(ListNode * node = head; node != NULL; node = node->next){
            list.push_back(node);
        }
    
        int n = list.size();
        int sum = 0;
        map<int,vector<int>> same;
        vector<pair<int,int>> range;
        
        /*intial*/
        same[0].push_back(-1);
        for(int i = 0;i < list.size(); ++i){
            sum += list[i]->val;
            same[sum].push_back(i);
        }
        
        /*we get the same sum*/
        for(auto & s : same){
            if(s.second.size() > 1){
                auto it1 = s.second.begin();
                auto it2 = s.second.end()-1;
                range.push_back(make_pair(*it1+1,*it2));
            }
        }
        
        /*we merge the range of zero*/
        sort(range.begin(),range.end(),cmp);
        vector<pair<int,int>> merge;
        for(int i = 0;i < range.size(); ++i){
            if(merge.size() == 0){
                merge.push_back(range[i]);
            }else{
                if(range[i].first > merge.back().second){
                    merge.push_back(range[i]);
                }
            }
        }

        /*now we will link the rest of the node*/
        for(int i = 0;i < merge.size(); ++i){
            for(int j = merge[i].first; j <= merge[i].second; ++j){
                list[j] = NULL;
            }
        }
        ListNode * node = NULL;
        ListNode * curr = NULL;
        for(int i = 0; i < n; ++i){
            if(list[i]){
                if(!node){
                    node = list[i];
                    curr = node;
                }else{
                    curr->next = list[i];
                    curr = curr->next;
                }
            }
        }
        if(curr){
            curr->next = NULL;
        }
        
        return node;
    }
};
```
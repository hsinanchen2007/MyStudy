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
        ListNode* tmp = head;
        int count = 0,flag =0;;
        for(;tmp!=NULL;tmp=tmp->next)
        for(int i=0;i<=(G.size()-1);i++){
            if(tmp->val==G[i]){
                if(tmp->next==NULL)
                count++;
            

                flag=1;
                break;
            }
            else if(i==(G.size()-1)&&flag==1)
                {
                    count++;
                    flag = 0;
                }
            }
            
          return count;  
        }
        
    };
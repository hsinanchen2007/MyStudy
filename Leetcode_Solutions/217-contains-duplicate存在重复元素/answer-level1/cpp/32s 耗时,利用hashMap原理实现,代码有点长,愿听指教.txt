
![image.png](https://pic.leetcode-cn.com/5ba9f966f58203c874de9e359c29b292fae766673c915c7c79cad0e1a2b34e5c-image.png)
```
struct __TTListNode {
     int val;
     int count=0;
     
     __TTListNode *next;
     __TTListNode(int x) : val(x), next(NULL) {
         
     }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        __TTListNode * nodeArrZ[10000]={0};
        for (vector<int>::iterator it=nums.begin(); it!=nums.end(); it++) {
            int index = *it%10000;
            if (*it<0)
                index = -index;
            
            __TTListNode* node =nodeArrZ[index];
            if (node==nullptr) {
                __TTListNode* nodeA = new __TTListNode(*it);
                nodeArrZ[index] = nodeA;
                
            }else{
                
                while (node !=nullptr) {
                    if (node->val == *it) {
                        node->count++;

                        if (node->count>0) 
                            return true;

                        break;
                    }
                    node=node->next;
                }
                __TTListNode *headNode = new __TTListNode(*it);
                headNode->next=nodeArrZ[index];
            }
            
        }
        return false;
    }
};
```
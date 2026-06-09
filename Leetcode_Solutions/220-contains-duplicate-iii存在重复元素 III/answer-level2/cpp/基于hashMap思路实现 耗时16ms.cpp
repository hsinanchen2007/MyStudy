###执行结果
![image.png](https://pic.leetcode-cn.com/a3e2f4070dfed9e4fdb56205b6db79918e6dd0a0a8cf81cdc9cae5204414c6ca-image.png)

### 解题思路
主要思路还是来自hashMap,主要是理解题目废了一些时间,在`t=0`时相当于上一个难度的问题,所以这里区分了一下`t==0和t!=0`的情况

### 代码

```cpp

struct __TTListNode {
     int64_t val;
     int64_t count=0;
     int64_t index;
     __TTListNode *next;
     __TTListNode(int64_t x) : val(x), next(NULL) {
         
     }
     __TTListNode(int64_t x,int64_t y) : val(x), next(NULL) ,index(y) {}
};


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        __TTListNode * nodeArrZ[10000]={0};
        int64_t i=0;
        
        for (vector<int>::iterator it=nums.begin(); it!=nums.end(); it++) {
            int64_t index = 0;
            if (t==0) {
                index = *it%10000;
                index = index < 0 ? -index : index;
            }
            else{
                index = i%10000;
            }
            __TTListNode* head =nodeArrZ[index];
            if (head==nullptr) {
                head = new __TTListNode(*it,i);
                nodeArrZ[index] = head;
                
            }else{
                head = new __TTListNode(*it,i);
                head->next=nodeArrZ[index];
            }
            int64_t flag = (t==0)?0:k;
            int64_t end = (index+flag)%10000;
            int64_t begin = (index-flag)%10000;
            for (int64_t j=begin; j<= end; j++) {
                int64_t __j=j;
                if (j<0)
                    __j= j+10000;

                __TTListNode* tmp_node =nodeArrZ[__j];
                while (tmp_node !=nullptr) {
                    if ((tmp_node->val - head->val) <= t && (tmp_node->val - head->val) >= -t &&
                        head != tmp_node) {
                        return true;
                    }
                    tmp_node=tmp_node->next;
                }
            }

            i++;
        }
        return false;
    }
};
```
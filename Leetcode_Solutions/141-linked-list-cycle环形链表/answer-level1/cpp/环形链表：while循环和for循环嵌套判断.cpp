### 解题思路
while循环和for循环嵌套判断，选中元素，判断和前面的元素是否有相同，一旦相同，返回跳出

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
    bool hasCycle(ListNode *head)
    {
            ListNode *nodeOne =head;
            ListNode *nodeTemp = head;
            int pos = 0 ;
            int nCount = 0;
            bool bIsOK = false;

            while(nodeOne)
            {
                for(int i =  0; i < nCount; i++)
                {
                    if(nodeTemp == nodeOne)
                    {
                        pos = 1;
                        bIsOK = true;
                        break;
                    }
                    nodeTemp = nodeTemp->next;
                }
                nodeTemp = head;
                if(bIsOK) break;
                nodeOne = nodeOne->next;

                nCount++;
            }

            return bIsOK;    
    }
};
```
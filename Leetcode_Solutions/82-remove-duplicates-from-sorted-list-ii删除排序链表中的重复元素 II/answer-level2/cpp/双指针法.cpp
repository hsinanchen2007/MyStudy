大概思路：

为了防止头指针出现重复而要删除头指针的情况，在头指针前面设置一个伪头指针来指向头指针，所以后面就用pre->next来跟now的值进行比较；

一些条件判断：

如果pre->next和now的值相等就将now往后推，直到pre->next和now指向的值不同；

在pre->next跟now指向的值不同的情况下，

如果pre->next的下一个是now，说明pre->next没有出现重复值，直接将pre指针往后推；

如果下一个不是now，说明pre->next跟now之间值pre->next的重复值，直接将now赋值给pre->next以删去重复值
```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 边界判断
        if(!head) return head;
       
    //    伪头部，防止头部出现重复的
        ListNode* result= new ListNode(0);
        result->next= head;
 
        ListNode* pre= result;
        ListNode* now= head;
        while(now){
            if(pre->next->val== now->val){
                now= now->next;
            }
            else{
                // now是pre->next的下一个，直接将pre往后推
                if(pre->next->next== now){
                    pre= pre->next;
                }
                else{
                    // 如果now不是pre->next的下一个，说明之间有重复的，直接将now赋值给pre->next                          
                    pre->next= now;
                }    
            }
        }
        
        // pre->next没到尾部说明尾部出现了重复
        if(pre->next->next)
            pre->next= NULL;
        return result->next;
    }
};
```

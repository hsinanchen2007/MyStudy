```
 /*
 思路：遍历链表,每次遍历查询该节点元素是否在vector中，
 并用lock锁判断是否在组件中，离开组件时组件数加1（另外要考虑最后一个元素的特殊情况）
 总结：较为简单的题目，第一个自己做出来且和题解中思路十分接近的一题，可能是题解中还没有大佬给出新方法
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int res=0;
        ListNode* p=head;
        bool lock=false;        //lock的true和false表示着"在一段组件中"和"不在一段组件中"
        while(p!=NULL)      //遍历链表
        {
            if(!lock)       //当不在组建中
            {
                if(find(G.begin(),G.end(),p->val)!=G.end())  //找到元素，lock标志进入组件，考虑最后一个元素的特殊情况
                {
                    if(p->next==NULL)   ++res;
                    lock=true;
                    p=p->next;
                }
                else p=p->next;     //找不到元素，啥也不干
            }
            else        //当在组件中的时候
            {
                if(find(G.begin(),G.end(),p->val)!=G.end())    //找到元素，考虑最后一个元素的额特殊情况
                {
                    if(p->next==NULL)   ++res;
                    p=p->next;
                }
                else        //找不到元素，lock标志退出组件，此时一份组件已查找完毕
                {
                    lock=false;
                    ++res;
                    p=p->next;
                }
            }
        }
        return res;
    }
};
```

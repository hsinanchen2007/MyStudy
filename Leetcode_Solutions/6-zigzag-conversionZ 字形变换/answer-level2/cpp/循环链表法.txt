### 解题思路
使用循环链表追踪字符对应的行数，生成各行字符串后合并

### 代码

```cpp
class Solution {
public:
    struct ListNode{
        int val;
        ListNode *next;
    };
    string convert(string s, int numRows) {
        ListNode *l,*p,*q;
        l=q=new ListNode;
        l->val=0;
        for(int i=1;i<numRows;++i){
            p=new ListNode; 
            p->val=i; 
            q->next=p;
            q=q->next; 
        }
        for(int i=numRows-2;i>0;--i){
            p=new ListNode; 
            p->val=i; 
            q->next=p;
            q=q->next; 
        }
        q->next=l;
        
        string answer[numRows];
        string ans;
        int m=0;
        for(int j=0;j<s.size();++j){
            answer[m]+=s[j];
            l=l->next;
            m=l->val;
        }
        for(int k=0;k<numRows;++k){
            ans+=answer[k];
        }
        return ans;
    }
};
```
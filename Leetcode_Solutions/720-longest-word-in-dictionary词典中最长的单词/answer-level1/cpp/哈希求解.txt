### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
思路:
1.类似哈希表，将拥有相同长度的单词放到同一个下标的链表里
2.从最大长度开始判断，用judge()函数判断拥有最大长度的单词能否一个一个减少直到长度为1，如果最大长度的有可以的单词，那么只需判断最大长度这个链即可，否则判断小一个数的链子
*/
struct node{
    int len; //头节点的len代表存放的单词的个数
    string val;
    node* next;
    node(int len,string val):len(len), val(val),next(nullptr){}
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        vector<node*> num(31);
        int max=0;
        for(int i=0;i<31;i++)                 //初始化num
            num[i]=new node(0,"");
        for(int i=0;i<words.size();i++)      //构造链表，把具有相同长度的单词放到一起
        {
            node *n=new node(words[i].length(),words[i]);
            node *m=num[words[i].length()];
            m->len++;
            n->next=m->next;
            m->next=n;
            max>words[i].length()?:max=words[i].length();
        }
        vector<string> res;
        for(int i=max;i>=1;i--)               //从最大长度的单词开始判断是否符合题意
        {
            node* temp=num[i];
            temp=temp->next;
            while(temp)
            {
                if(judge(temp->val,num,i-1))
                    res.push_back(temp->val);
                temp=temp->next;
            }
            if(res.size()!=0)
                break;
        }
        sort(res.begin(),res.end());
        return res[0];
    }
    bool judge(string c,vector<node*> num,int length)      //判断函数
    {
        while(length>=1)
        {
            c=c.substr(0,length);
            node* temp=num[length];
            bool j=false;
            temp=temp->next;
            while(temp)
            {
                if(c==temp->val)
                {
                    j=true;
                    break;
                }
                temp=temp->next;
            }
            if(j)
                length--;
            else
                return false;
        }
        return true;
    }
};
```
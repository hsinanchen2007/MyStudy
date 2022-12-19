构建字符串数组的前缀树，然后再把分支数为1的字母输出
```
class Tire{
public:
    Tire *children[26];
    int size;
    bool isend=false;
    Tire()
    {
        size=0;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    } 
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        Tire *root=new Tire();
        for(int i=0;i<strs.size();i++)
        {
            Tire *p=root;
            if(strs[i].empty())return ans;
            for(int j=0;j<strs[i].length();j++)
            {
                if(p->children[strs[i][j]-'a']==NULL)
                {
                    p->children[strs[i][j]-'a']=new Tire();
                    p->size++;
                }
                p=p->children[strs[i][j]-'a'];
            }
            p->isend=true;
        }
        Tire *q=root;
        int k=0;
        while(q->size==1&&q->isend==false)
        {
            for(k=0;k<26;k++)
            {
                if(q->children[k])
                {
                    char temp=k+'a';
                    ans+=temp;
                    break;
                }
            }
            q=q->children[k];
        }
        return ans;
    }
};
```

```
class Solution {
public:
    //字典树是一个多叉树，每一条边表示一个字母，next[i]表示该节点第i+1个字母所表示的边指向哪一个节点
struct TreeNode{
    int next[26];
    int num;//表示以该字母结尾的单词的字母数量
    bool end;
    TreeNode()
    {
        memset(next,0,sizeof(next));
        end=true;
        num=0;
    }
};
    /*
    字典树
    */
    int minimumLengthEncoding(vector<string>& words) {
        TreeNode tn[14000];
        int n=words.size();
        int top=1;
        int res=0;
        for(int i=0;i<n;i++)
        {
            int p=0;
            for(int j=words[i].size()-1;j>=0;j--)
            {
                if(tn[p].next[words[i][j]-'a'])
                {
                    p=tn[p].next[words[i][j]-'a'];
                }
                else
                {
                    tn[p].end=false;
                    tn[p].next[words[i][j]-'a']=top;
                    tn[top].num=tn[p].num+1;
                    p=top;
                    top++;
                }
            }
        }
        for(int i=1;i<top;i++)
            if(tn[i].end)
                res=res+tn[i].num+1;
        return res;
    }
};
```



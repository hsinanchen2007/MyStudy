From Xuebi-God C++


解法：Trie字典树+深度遍历搜索+flag标志是否已经替换

```zephir
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    struct TreeNode
    {
####        bool isword; TreeNode*child[26];
        TreeNode(){isword=false;
                   memset(child,NULL,sizeof(child));}
    };
    TreeNode*root;
    MagicDictionary(){root=new TreeNode();}
    
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(int i=0;i<dict.size();i++)
        {
            TreeNode*p=root;
            for(int j=0;j<dict[i].size();j++)
            {
                int ch1=dict[i][j]-'a';
                if(!p->child[ch1]) p->child[ch1]=new TreeNode();
                p=p->child[ch1];
            }
            p->isword=true;
        }
    }
    bool helper(string word,bool&flag,int level,TreeNode*p)//flag用来记录是否已经取代过一次
    {
        int ch1=word[level]-'a';
        if(level==word.size()-1)//处理到最后一个字母
        {
            if(flag==false)
            {//最后一个字母必须看看那些child[ch1]的，例如hello原本就在字典里有，就返回false。因为没变过字母
                for(int i=0;i<26;i++)
                {
                    if(i!=ch1&&p->child[i]&&p->child[i]->isword)
                        return true;
                }
                return false;
            }
            else
            {//在最后一个字母前已经发生过一次取代，所以现在判断最后一个字母是否存在，且是否为结束
                if(p->child[ch1]&&p->child[ch1]->isword) return true;
                else return false;
            }
        }
        else//处理的不是不是最后一个字母
        {
            if(flag==false)//没有发生过取代
            {//假设在这层发生取代
                for(int i=0;i<26;i++)
                {
                    if(i!=ch1&&p->child[i])
                    {
                        flag=true;
                        if(helper(word,flag,level+1,p->child[i])) return true;
//回复原样，可以想想，剩下的25个child都不行，那么要看看不取代这个字母,能不能继续往下在，既然不取代，flag肯定为false
                        flag=false;
                    }
                }
            }
            //如果到这里，一是原来的else部分（发生过取代），二是可能上面if里面运行完了，25个child都不行，现在看看目前剩下的这一个字母（没有发生取代）
            if(p->child[ch1])
                return helper(word,flag,level+1,p->child[ch1]);
            else
                return false;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        bool flag=false;
        return helper(word,flag,0,root);
    }
};

```
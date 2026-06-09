思路：首先这道题可以通过构造字典树得到题解，由所给的dict构造trie字典树，然后
通过istringstream库函数将整句话分割成一个个字符串word，
将字符串与字典树进行匹配，如果完全符合其前缀，则得到其dict的词根，否则则是word字符串。
```
class Solution {
    struct Trie{//Trie 树构造
        bool isEnd;
        struct Trie*next[26];
    };

public:
    void CreateTrieTree(vector<string>&dict,Trie *pRoot)//构造字典树
    {
        struct Trie* pTemp=NULL;
        int ch=0;
        for(int i=0;i<dict.size();i++)
        {
            pTemp=pRoot;
            for(int j=0;j<dict[i].size();j++)
            {
                ch=dict[i][j]-'a';
                if(NULL==pTemp->next[ch])
                {
                  pTemp->next[ch]=new Trie();
                  pTemp=pTemp->next[ch];
                }
                else pTemp=pTemp->next[ch];
            }
            pTemp->isEnd=true;//标定字符串
        }
    }

      string getString(Trie *pRoot, string src)//对比字典树，得其前缀
      {
      string prefix = "";
      Trie *pTemp = pRoot;
      int ch = 0;

      for(int i = 0; i < src.size(); i++)
      {
        ch = src[i] - 'a';

        if(pTemp->isEnd)//若是词根，则返回其前缀
          return prefix;             
        if(NULL == pTemp->next[ch])//不是，则为原来的字符串
          return src;
        
        prefix += src[i];
        pTemp = pTemp->next[ch];
      }
      return src;
      }

    string replaceWords(vector<string>& dict, string sentence) {

        struct Trie*pRoot=new Trie();//字典树根
        CreateTrieTree(dict,pRoot);
        
        string word,ans="";
        istringstream ss(sentence);//分割句子，ss为一个个字符串
        while (ss>>word)//将ss写入到word中
        {
            ans+=getString(pRoot,word)+" ";
        }
        ans.erase(ans.end()-1);//注意最后一个" "

        return ans;
    }
};
```

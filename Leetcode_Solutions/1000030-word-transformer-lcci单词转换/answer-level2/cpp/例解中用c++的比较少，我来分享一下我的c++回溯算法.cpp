![1584096808(1).png](https://pic.leetcode-cn.com/86255cac707d574d65e8cf958d051afde80ecee92d01e73bfec4a293d53bca40-1584096808\(1\).png)
一开始没有考虑剪枝，导致超过时间限制。增加剪枝之后时间仍然不快，效率的话可能比不过其他的例解，但也不失为一种思路，尤其是回溯的思想我觉得还是很实用并且理解之后也很好用，因为回溯不过是一种模型，而且很适用于很多体型。
**思路**
1.首先用回溯来找到所有的可能，对于beginword，想转换成endword，每次只能从wordlist中找一个与他只相差一个字符的字符串，这样的话，每一步都有很多种可能，对于可能性很多的题，回溯就很好发挥他的作用。
2.由于回溯是深度优先，所以对于每一种可能的情况，他会先顺着这个情况一直添加直到终止条件：wordlist中没有与这个字符串只相差一个字符的字符串了。这时需要判断我们的beginword到底有没有经我们的步骤成功转换成endword，如果没有的话，说明这一种情况是不可行的，也就是说最后的这个字符串是不可取的，这时我们需要进行剪枝。
3.对于剪枝，我们用一个map<string，int>来表示那些不可取的string，当一个string被我们发现是不可取时，那么他对应map里的值我们就将它设为-1，这时我们的每次取字符串时只需要判断一下这个字符串对应表里的值是否为-1，是的话就不取它。
4.如此反复，一条线路不行，我们就换另一条线路，直到所有的可能都被我们找到并判断是否有那么一条线路可行，只要有一条可行，我们就返回这个线路中每一个取过的string，我们在回溯中已经将其放入了vector中。
**代码**
```
class Solution {
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> ans;
        map<string,int> p2;
        if(!fnd(wordList,endWord)) return ans;
        ans.push_back(beginWord);
        if(backs(ans,beginWord,endWord,wordList,p2)) return ans;
        vector<string> skr;
        return skr;
    }
    bool backs(vector<string> &ans,string beginWord,string endWord,vector<string> &wordList,map<string,int> &p2)
    {
        if(beginWord == endWord) return true;
        for(string s:wordList)
        {
            if(check(beginWord,s)&&!fnd(ans,s)&&p2[s]!=-1)
            {
                ans.push_back(s);
                if(backs(ans,s,endWord,wordList,p2)) return true;
                p2[s] = -1;
                ans.erase(ans.end()-1);
            }
        }
        return false;
    }
    bool check(string &a,string &b)
    {
        if(a.size() != b.size()) return false;
        int all = 0;
        for(int n = 0; n < a.size(); n++)
        {
            if(a[n] != b[n])
            {
                all++;
                if(all>1) return false;
            }
        }
        if(all != 1) return false;
        return true;
    }
    bool fnd(vector<string> &ans, string s)
    {
        if(ans.empty()) return false;
        for(string a:ans) 
        {
            if(a == s) return true;
        }
        return false;
    }
};
```

我的分享就到这里了，由于水平有限并且文笔不好，讲的也许不是很清楚，大家有不懂的欢迎评论留言，我看到了会一一认真解答，希望大家都能理解回溯的思想。

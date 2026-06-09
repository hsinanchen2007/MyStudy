![image.png](https://pic.leetcode-cn.com/80b5c2ad6d1c06ca1905b474481ac13a01207be366afbd76b47bf397953a9fc2-image.png)
其实解法蛮简单但是耗时间，但还是AC了哈哈哈
```
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string a="qwertyuiop";
        string b="asdfghjkl";
        string c="zxcvbnm";
        for(int i(0);i<words.size();)
        {
            int pos(0);
            for(int j(0);j<words[i].size();j++)
            {
                if(a.find(words[i][j])!=-1)
                { 
                    if(pos==0)
                    {
                        pos=1;
                        continue;
                    }
                    else
                    { 
                        if(pos!=1)
                        {
                            words.erase(words.begin()+i);
                            i--;
                            break;
                        }
                    } 
                }
                if(b.find(words[i][j])!=-1)
                { 
                    if(pos==0)
                    {
                        pos=2;
                        continue;
                    }
                    else
                    { 
                        if(pos!=2)
                        {
                            words.erase(words.begin()+i);
                            i--;
                            break;
                        }
                    } 
                }
                if(c.find(words[i][j])!=-1)
                { 
                    if(pos==0)
                    {
                        pos=3;
                        continue;
                    }
                    else
                    { 
                        if(pos!=3)
                        {
                            words.erase(words.begin()+i);
                            i--;
                            break;
                        }
                    } 
                }
            }
            i++;
        }
        return words;
    }
};
```

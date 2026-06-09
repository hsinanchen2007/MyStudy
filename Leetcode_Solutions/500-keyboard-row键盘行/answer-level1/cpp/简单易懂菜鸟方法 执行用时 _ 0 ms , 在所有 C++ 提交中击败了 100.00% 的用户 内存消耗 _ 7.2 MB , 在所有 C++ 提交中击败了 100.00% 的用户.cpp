### 解题思路
重新定义一个vector<string>容器v，构建bool类型函数f判断words容器内每个string字符串是否符合题目要求，若符合则将该字符串插入容器v中。

**bool f(string s)功能实现：**
定义三个字符串类型a、b、c，分别存放键盘三行的大小写字符。提取str第一位字符ch，分别在a、b、c中查找ch依次判定第一位字符ch在键盘哪一行。随后对s剩下字符遍历，用相同方法判断剩下字符在键盘的哪一行。如果发现有字符和ch不在同一行，整明str不符合题目要求，返回false。反则取反。

### 代码

```cpp
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        vector<string> v;
        
        for(auto it=words.begin();it!=words.end();it++)
        {
            if(f(*it))
            {
                v.push_back(*it);
            }
        }
        
        return v;

    }
    
    bool f(string str)
    {
        string a="QWERTYUIOPqwertyuiop";
        string b="ASDFGHJKLasdfghjkl";
        string c="ZXCVBNMzxcvbnm";
        
        char ch=str[0];
        int temp;
        
        if(find(a.begin(),a.end(),ch)!=a.end())
        {
            temp=1;
        }
        else if(find(b.begin(),b.end(),ch)!=b.end())
        {
            temp=2;
        }
        else if(find(c.begin(),c.end(),ch)!=c.end())
        {
            temp=3;
        }
        
        for(int i=1;i<str.size();i++)
        {
            if(temp==1)
            {
                if(find(a.begin(),a.end(),str[i])==a.end())
                {
                    return false;
                }
            }
            else if(temp==2)
            {
                if(find(b.begin(),b.end(),str[i])==b.end())
                {
                    return false;
                }
            }
            else if(temp==3)
            {
                if(find(c.begin(),c.end(),str[i])==c.end())
                {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};
```
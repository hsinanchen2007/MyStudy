我的思路是从s中查找是否有wordDict中的字符串，如果有，就把这个字符串的前和后拼接起来，形成新的字符串，再调用自己，最后判断是否所有的字符串都找到了，找到了就说明可以返回true了，找不到就返回false。
```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty())
        {
            return true;
        }

        for(int i = 0; i < wordDict.size(); i++)
        {
            if(s == wordDict[i])
            {
                return true;
            }
            else
            {
                size_t pos = s.find(wordDict[i]);
                if(std::string::npos != pos)
                {
                    std::string strBefore = "";
                    if(pos > 0)
                    { 
                        strBefore = s.substr(0,pos);
                    }
                    std::string strAfter = s.substr(pos+wordDict[i].size());
                    std::string strLeft = strBefore + strAfter;
                    bool ret = wordBreak(strLeft, wordDict);
                    if(true == ret)
                    {
                        return true;
                    } 
                }
            }
        }

        return false;
    }
};
```
但是这里出错了：
"ccbb" ["bc","cb"]

明显的问题是s="ccbb"找到第一个中间的cb后，把前面的c和后面的b链接起来，又是新的cb，但是这种链接时错误的

所以改进的方法就是，不直接拼接前后的字符串，而是将找到的wordDict中的字符串用一个特殊的字符替换掉，比如空格、$符等，然后再前后拼接起来。但是在递归调用判断是否可以返回时，也要判断下是否所有的字符串都已经被替换成了特殊字符了。

代码如下：我用的空格替换的
```

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty())
        {
            return true;
        }

        bool isAllSpace = true;
        for(int sIndex = 0; sIndex < s.length(); sIndex++)
        {
            if(s[sIndex] != ' ')
            {
                isAllSpace = false;
            }
        }

        if(isAllSpace)
        {
            return true;
        }

        for(int i = 0; i < wordDict.size(); i++)
        {
            if(s == wordDict[i])
            {
                return true;
            }
            else
            {
                size_t pos = s.find(wordDict[i]);
                if(std::string::npos != pos)
                {
                    std::string strBefore = "";
                    if(pos > 0)
                    { 
                        strBefore = s.substr(0,pos);
                    }
                    std::string strAfter = s.substr(pos+wordDict[i].size());
                    std::string strLeft = strBefore + " " + strAfter;
                    bool ret = wordBreak(strLeft, wordDict);
                    if(true == ret)
                    {
                        return true;
                    } 
                }
            }
        }

        return false;
    }
};
```
在处理下面的输入时，又超时了：
"bccdbacdbdacddabbaaaadababadad" ["cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa","bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b","bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a","bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb","dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd","cadaa","ddbc","babb"]

超时的原因是因为替换过的字符串，有很多重复的在做同样的事情，如果能把替换后的字符串的判断结果存储下来，然后再实际递归前直接查找下，找到了就直接返回，就可以省去重复操作的过程，所以再修改下程序成下面的样子：
```
class Solution {
private:
    std::map<std::string, bool> m_mapString2Bool;
public:
    Solution()
    {
        m_mapString2Bool.clear();
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty())
        {
            return true;
        }

        bool isAllSpace = true;
        for(int sIndex = 0; sIndex < s.length(); sIndex++)
        {
            if(s[sIndex] != ' ')
            {
                isAllSpace = false;
            }
        }

        if(isAllSpace)
        {
            return true;
        }

        for(int i = 0; i < wordDict.size(); i++)
        {
            if(s == wordDict[i])
            {
                return true;
            }
            else
            {
                size_t pos = s.find(wordDict[i]);
                if(std::string::npos != pos)
                {
                    std::string strBefore = "";
                    if(pos > 0)
                    { 
                        strBefore = s.substr(0,pos);
                    }
                    std::string strAfter = s.substr(pos+wordDict[i].size());
                    std::string strLeft = strBefore + " " + strAfter;
                    std::map<std::string, bool>::iterator it = m_mapString2Bool.find(strLeft);
                    if(it != m_mapString2Bool.end())
                    {
                        return it->second;
                    }
                    bool ret = wordBreak(strLeft, wordDict);
                    if(true == ret)
                    {
                        m_mapString2Bool.insert(std::make_pair(strLeft, true));
                        return true;
                    } 

                    m_mapString2Bool.insert(std::make_pair(strLeft, false));
                }
            }
        }

        return false;
    }
};
```
方法比较笨，时间复杂度和空间复杂度都比较高，还是得看下题解里面大家讨论的方法
![image.png](https://pic.leetcode-cn.com/13bffddb094ad58e9c6f0b903fd84096fe04cfe0848fe3018f1efc730d6419ef-image.png)

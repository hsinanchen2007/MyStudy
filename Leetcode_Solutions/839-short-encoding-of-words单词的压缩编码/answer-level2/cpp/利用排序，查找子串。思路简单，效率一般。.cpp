// 可重复时一定短单词是长单词的后缀，按单词长度从长到短进行编码
如 time,me,bell
先进行排序 time>bell>me
先编码time 为time#
判断bell#是否在编码里，结果是不在，将bell#追加到编码里变成time#bell#
判断me#是否在编码里，结果是在，不对编码进行修改，接着判断下一单词


```
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int length=words.size();
        if(length==0) return 0;
        

        sort(words.begin(),words.end(),mycompare);  // 单词长度从长到短排序
        string code{};  // 存储编码后的字符串
        for(int i=0;i<length;i++)
        {
            string newword { words[i]};
            newword.append("#");        // 单词字符串
            if(code.find(newword)==string::npos)   // 如果不能由现有的编码找出，则加上此单词
            {
                code.append(newword);
            }
        }
        return code.size();
    }
    static bool mycompare(string &a, string &b)
    {
        return a.size()>b.size();
    }
};
```

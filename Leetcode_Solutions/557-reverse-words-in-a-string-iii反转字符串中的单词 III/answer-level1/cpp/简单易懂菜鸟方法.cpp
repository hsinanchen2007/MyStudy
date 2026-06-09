### 解题思路
两个下标变量start、end，start保存每个单词的首字母下标，end保存每个单词后空格的下标。
因为句子首字符为字母，将start初始值设定为0。
用end遍历句子，当s[end]=' '时，[start,end-1]片段就是单词的部分，利用reverse函数对该片段进行反转，接着start移动到end后一位，依次类推，直到end遍历完，将最后一个单词反转。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        
        int start=0;
        
        for(int end=0;end<s.size();end++)
        {
            if(s[end]==' ')
            {
                reverse(s.begin()+start,s.begin()+end);
                start=end+1;
            }
            if(end==s.size()-1)
            {
                reverse(s.begin()+start,s.end());
            }
        }
        
        return s;

    }
};
```
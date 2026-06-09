定义快慢指针slow和fast，一次遍历，当快指针位置为字符时，fast++，遇到空格时，此时遍历过的单词长度为fast-slow，接着跳过所有的空格
当遇到空格之后的第一个字符时，将slow设置为fast，这样会得到每个单词的长度，同样最后一个单词的长度也会得到，输出结果即可

```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.size();
        if(len==0)return len;
        int slow=0;
        int fast=0;
        int res;
        while(fast<len){
            while(fast<len && s[fast]!=' '){
                ++fast;
            }
            res=fast-slow;
            while(fast<len && s[fast]==' '){
                ++fast;
            }
            slow=fast;
        }
        return res;
    }
};
```

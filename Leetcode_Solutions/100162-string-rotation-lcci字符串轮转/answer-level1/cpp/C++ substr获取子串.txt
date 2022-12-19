- 把s2复制一次放在原来的末尾
- 先判断两个字符串长度是否相等，不相等直接返回false
- 再判断是否为空，是就返回true,否就接着判断
- 遍历s3利用substr判断是否有子串
```
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        if(s1.size()==0) return true;
        string s3=s2+s2;
        int l=s1.size();
        for(int i=0;i<s3.size()-l+1;i++)
        {
            string p=s3.substr(i,l);
            if(p==s1)
            {
                return true;
            }
        }
        return false;
    }
};
```

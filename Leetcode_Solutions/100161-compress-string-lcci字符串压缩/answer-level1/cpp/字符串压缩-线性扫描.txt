
### 解题思路
从第2个字符开始比较(如果存在的话)，与前一个字符不同则出现新的字符，更新res；否则字符数递增
### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        string res="";
        res+=S[0];
        int temp=1;
        for(int i=1;i<S.length();++i)
        {
            if(S[i]!=S[i-1])
            {
                res+=to_string(temp);
                temp=0;
                res+=S[i];
            }
            ++temp;
        }
        res+=to_string(temp);
        if(res.size()<S.size())
        {
            return res;
        }
        else return S;
    }
};
```
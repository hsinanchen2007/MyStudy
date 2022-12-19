### 解题思路
用一个int中的每个二进制位来表示字母是否出现，若两个字符串中没有相同的字母，则位与运算为0
### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> len;
        vector<int> charbit;
        int x;
        for(string word:words)
        {
            x=0;
            for(char c:word)
            {
                int tmp=pow(2,c-'a');
                x=x|tmp;
            }
            charbit.push_back(x);
            len.push_back(word.size());
        }
        int ret=0;
        for(int i=0;i<len.size();++i)
        for(int j=i+1;j<len.size();++j)
        if((charbit[i]&charbit[j])==0)
        ret=max(ret,len[i]*len[j]);

        return ret;

    }
};
```
### 解题思路
令`i`为扫描字符串的指针
令`j`为行指针,`sign`为`j`增加的方向
则每次到达开始(`j==0`)或者到达结尾(`j==numRows-1`)的时候,就调换j的方向(`sign=-sign`)
同时第一次在头的时候(`i==0`)不需要改变方向
特殊情况`numRows==1`,直接返回原始的字符串就行

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1)
            return s;
        vector<string> temp(numRows,"");
        int sign=1;
        for(int i=0,j=0;i<n;i++,j+=sign){
            temp[j]+=s[i];
            if(i!=0&&(j==0||j==numRows-1))
                sign=-sign;
        }
        string ans;
        for(auto &t:temp)
            ans+=t;
        return ans;
    }
};
```
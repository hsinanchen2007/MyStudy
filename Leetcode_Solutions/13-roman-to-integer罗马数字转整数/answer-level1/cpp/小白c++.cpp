### 解题思路
用map（关联容器）提供一点一（映射）的hash
思路是看了其他大佬的题解思路了解看明白之后，然后自己实现敲一遍
根据题中的特例，当遍历到罗马数字大数字在小数字的左边时增加一个负号/。也就是s[i]<s[i+1]时。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mmp;
        mmp['I']=1;
        mmp['V']=5;
        mmp['X']=10;
        mmp['L']=50;
        mmp['C']=100;
        mmp['D']=500;
        mmp['M']=1000;
        int sum=0;
        int num=0;
        for(int i=0;i<=s.size()-1;i++)
        {
            if(mmp[s[i]]<mmp[s[i+1]])
            sum+=-mmp[s[i]];
            else
            num+=mmp[s[i]];
        }
         return sum+num;
    }
};
```
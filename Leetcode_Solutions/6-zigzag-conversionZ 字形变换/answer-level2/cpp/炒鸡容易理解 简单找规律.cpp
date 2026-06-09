
1. 首先肯定是逐行输出，那么毫无疑问外层循环的肯定就是numRows，剩下的就是结果行内的问题
2. 行内的话按照下面的公式处理：
![微信截图_20190613111026.png](https://pic.leetcode-cn.com/64a08b39084b07eba51237ffd8061c419c6fe35b19e9bcf778115671905b582a-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190613111026.png)

```
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==0||numRows==1) return s;
        string res;
        int n=2*numRows-2;
        for(int i=0;i<numRows;++i){
            for(int j=0;j<s.size();++j){
                if(j%n==i||j%n==(n-i)) res+=s[j];
            }
        }
        return res;
    }
};
```
容易理解 但是复杂度有点高
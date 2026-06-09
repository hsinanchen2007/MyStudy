### 解题思路
利用ascii码解决，n--是因为由A作为起始位ascii码，当n=1时应该为'A'变成n=0，因为在此基础上加

### 代码

```cpp
class Solution {
public:
    string convertToTitle(int n) {
        if(n<=0) return "";
        string res="";

        while(n>0){
            n--;        //n--是因为由A作为起始位ascii码
            res = res + (char)(n%26 + 'A');
            n = n/26;
        }

        reverse(res.begin(),res.end());
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/86ec00b47a2c3195dc24a43115a978a0ad1d6818fe16ec59eafec8052d138763-image.png)

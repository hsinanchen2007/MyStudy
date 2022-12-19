### 解题思路
从最大的N开始，一直到N/2(不需要到0，到N/4就可以避免冗余了)，将数值转化为二进制字符串，利用string自带find函数来判断是否为子串。
![image.png](https://pic.leetcode-cn.com/51f1e370e056eac969fc114e80ef9338988d53a02bfe38547ab5a010d9d202ba-image.png)

### 代码

```cpp
class Solution {
public:
    bool queryString(string S, int N) {
      string s="";
      for(int i=N;i>N/4;i--)
      {
          s="";
          int temp=i;
          while(temp)
          {
             s.insert(0,1,char(temp%2+'0'));
             temp/=2;
          }
          if(S.find(s)==S.npos) return false;
      }
      return true;
    }
};
```
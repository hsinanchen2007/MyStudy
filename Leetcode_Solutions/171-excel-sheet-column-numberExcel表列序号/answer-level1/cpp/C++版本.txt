### 解题思路

参考 字符串变成整数

### 代码

```cpp
class Solution {
public:
    //AB =1*26+2  
    //31=3*10+1
    int titleToNumber(string s) {
       int sum =0;

       for(int i =0;i<s.size();i++)
       {
            int temp=s[i]-'A'+1; //A=1 B=2.
            sum =sum*26+temp; //加法运算
       }

       return sum; 
    }
};
```
![image.png](https://pic.leetcode-cn.com/6e3e8c34408ad5f4f5b27be6633895f232fc7b9308abb21bddab9d2b7ae196d9-image.png)

### 解题思路
1.首先遍历字符串，将相邻两个字符转换为整数；
2.判断是否符合减法规则，是则将n-m加到ans中，跳过下一个字符；否则直接加m；
![image.png](https://pic.leetcode-cn.com/642ec44aadb66c973402012005e462be185554c7a23b3b3fe206da927276ffd0-image.png)


### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int m,n,ans=0;
        for(int i = 0;i < s.size();i++){
            switch(s[i]){
                case 'I': m = 1; break;
                case 'V': m = 5; break;
                case 'X': m = 10; break;
                case 'L': m = 50; break;
                case 'C': m = 100; break;
                case 'D': m = 500; break;
                case 'M': m = 1000; break;    
            }
            switch(s[i+1]){
                case 'I': n = 1; break;
                case 'V': n = 5; break;
                case 'X': n = 10; break;
                case 'L': n = 50; break;
                case 'C': n = 100; break;
                case 'D': n = 500; break;
                case 'M': n = 1000; break;
                default: n = 0; break;    
            }
            if(n==5*m||n==10*m){
                    ans += n-m;
                    i++;
            }
            else
                ans += m;
        }
    return ans;
    }
};
```
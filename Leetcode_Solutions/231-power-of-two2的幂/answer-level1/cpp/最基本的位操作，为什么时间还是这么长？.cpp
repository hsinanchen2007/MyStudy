### 解题思路
![image.png](https://pic.leetcode-cn.com/0f82a8dfce0e6080eb700aeccec3bbfe8d3b22121565e59d8cd9891fa0d7b78a-image.png)

此处撰写解题思路
先排除非正数，而后判断是不是只有一个1。
### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if((n & (n-1))==0){
            return true;
        }else{
            return false;
        }
    }
};
```
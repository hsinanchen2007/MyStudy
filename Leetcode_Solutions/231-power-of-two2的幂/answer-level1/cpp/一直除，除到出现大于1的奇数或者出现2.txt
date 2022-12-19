### 解题思路
此处撰写解题思路
*![捕获.PNG](https://pic.leetcode-cn.com/c0ae3c55c862c0b4d422e6416abfbdd2b82566a2d144ea8288a6f0cd0b69518d-%E6%8D%95%E8%8E%B7.PNG)*


### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
      if(n==0) return false;
      if(n==1) return true;
      while(n%2==0){
        if(n==2) break;
        n=n/2;
      }
      if(n%2) return false;
      return true;
    }
};
```
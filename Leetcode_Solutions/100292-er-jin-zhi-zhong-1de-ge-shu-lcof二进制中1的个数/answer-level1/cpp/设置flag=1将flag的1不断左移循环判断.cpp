### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
       unsigned int flag=1;
       int count=0;
       while(flag)
       {
           if(n&flag)//两个都是1 
               count++;
           
           flag=flag<<1;//向左移动1位

       }
       return count;
    }
};
```
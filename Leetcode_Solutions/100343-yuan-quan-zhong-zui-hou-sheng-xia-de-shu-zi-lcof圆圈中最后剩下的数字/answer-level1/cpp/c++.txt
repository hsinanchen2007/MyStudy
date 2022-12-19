自己实现超时了，
学习甜姨的解法。。。太妙了

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
       int result = 0;
       for(int i = 2; i <= n; i++)
       {
           result = (result + m) % i;
       }
       return result;
    }
};
```
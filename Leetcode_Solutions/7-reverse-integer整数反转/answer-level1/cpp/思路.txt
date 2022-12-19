### 解题思路
需要注意负数%10,也一直是个负数，所以不用分开考虑正负值
另外如120000，因为一开始res=0,所以后面几个0，等于都是处理了，但是都是+0，所以也不用特殊处理

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
      int res = 0;
      while(x){
        if(res > INT_MAX / 10 || (res == INT_MAX / 10 && x % 10 > 7))
          return 0;
        if(res < INT_MIN / 10 || (res == INT_MIN / 10 && x % 10 < -8))
          return 0;

        res = 10 * res + (x % 10);
        x = x / 10;
      }

      return res;
    }
};
```
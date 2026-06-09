### 解题思路
1.使用牛顿法作为主要方法，可以使用C++库函数解，但不是题目的本意。
2.牛顿法的本质是对一个二次可导函数取切线，并不断逼近零点直到获取零点的值。
3.此处引用马同学的文章来详细解释牛顿法https://www.matongxue.com/madocs/205.html。
### 代码

```cpp
class Solution {
public:
   int mySqrt(int x) {
        if (x == 0) return 0;
        double last=0;
        double res = 1;
        while(res != last){
           last = res;
           res = ( res + x / res )  /2;
        }
        return int(res);
    }
};
```
### 解题思路
![image.png](https://pic.leetcode-cn.com/781490e292a6f6483544460655a4a09d2f3f10663308fdf70adb34b62bc60e13-image.png)


此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        if(n < 0 || n > 100) return 0;
        if(n <= 1) return n;
        
        int a = 0,b = 1,c = 0;
        for(int i = 2; i <= n; i++){
            c = a + b;
            if(c > 1000000007)
                c = c % 1000000007;
            a = b;
            b = c;
        }
        return c;
    }
};
```
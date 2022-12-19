### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/69e43a38f4a55e219b9eeb610d8e87539f0d0842d6fd31b4ca36323e3a4b32de-image.png)

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        //special case: n = -2^32, could let +n -> -;
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (x == -1) return n%2==0? 1:-1;
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1/x;
        if (n > 0) {
            n = -n;
            x = 1/x;
        }
        x = 1/x;
        double numOri = x;
        double res = 1;
        long pow = 0;
        int nextPow = n - pow;

        while(nextPow < -1){
            nextPow = nextPow - pow;
            pow = -1;
            x = numOri;
            bool calculated  = false;
            while ((pow + pow) >= nextPow) {
                calculated = true;
                x = x * x;
                pow = pow + pow;
            }
            res = calculated? res * x: res;
        }

        while (pow >= nextPow) {
            res = res * numOri;
            pow--;
        }

        return res;
    }
};
```
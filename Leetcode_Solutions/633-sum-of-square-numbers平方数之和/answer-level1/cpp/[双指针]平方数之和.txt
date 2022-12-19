令a = 0，b = 根号c + 1. <br>
在a <= b 前提下，如果a方+b方小于c，则将a++，大于则将b++，等于直接返回true. <br>
当不满足a <= b时，则说明没有满足的组合，返回false. <br>

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int a = 0;
        long long int b = sqrt(c)+1;
        while(a <= b) {
            long long int temp = a*a + b*b;
            if(temp < c) {
                a++;
            }
            else if(temp > c) {
                b--;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
```
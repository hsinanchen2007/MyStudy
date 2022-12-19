### 解题思路
1.使用双指针，快慢指针。
2.若快指针遇到快乐数就会等于1并一直在1处等待满指针达到1，返回true
2.若快指针很遇到不是快乐数，慢指针与快指针会有相遇并跳出循环，与1不同会返回false。

### 代码

```cpp
class Solution {
public:

    int bitSquareSum(int n){
        int sum = 0;
        while(n > 0){
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n,fast = n;
        do{
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }while(slow != fast);

        return slow == 1;
    }
};
```
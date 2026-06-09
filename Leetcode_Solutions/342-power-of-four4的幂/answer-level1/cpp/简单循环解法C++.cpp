比较简单的思路，C++用循环解决。Go用位运算解决，不用多说了吧。
```cpp []
class Solution {
public:
    bool isPowerOfFour(int num) {
        while (num  && num % 4 == 0) {
            num /= 4;
        }
        return num == 1;
    }
};
```
```go []
func isPowerOfFour(num int) bool {
    return num > 0 && (num & (num -1) == 0) && (num & 0x55555555 != 0)
}
```

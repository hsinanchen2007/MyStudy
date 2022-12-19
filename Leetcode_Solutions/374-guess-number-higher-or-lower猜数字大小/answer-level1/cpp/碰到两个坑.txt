### 解题思路
1.guess()返回值1和-1的坑
2.超过int的坑
### 代码

```cpp
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long int left = 1;
        long long int right = n;
        long long int curr;
        while(1)
        {
            curr = (left + right)/2;
            if (guess(curr) == 0)
                break;
            if (guess(curr) == 1)
                left = curr+1;
            if (guess(curr) == -1)
                right = curr-1;
        }
        return curr;
    }
};
```
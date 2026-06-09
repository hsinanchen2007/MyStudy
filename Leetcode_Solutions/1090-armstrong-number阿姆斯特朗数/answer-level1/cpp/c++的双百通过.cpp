### 解题思路
思路与官方差不多，感觉自己写复杂了。

### 代码

```cpp
class Solution {
public:
    bool isArmstrong(int N) {
        int len = get_length(N), sum = 0, cmp = N;
        while(len) {
            sum += (int)( pow(N / (int)(pow(10, len - 1)), get_length(cmp)) ) ;
            N %= (int)(pow(10, len - 1)); 
            --len;
        }
        return sum == cmp ? true : false;
    }

    int get_length(int N) {
        int len = 0;
        while(N) {
            N /= 10;
            ++len;
        }
        return len;
    }
};
```
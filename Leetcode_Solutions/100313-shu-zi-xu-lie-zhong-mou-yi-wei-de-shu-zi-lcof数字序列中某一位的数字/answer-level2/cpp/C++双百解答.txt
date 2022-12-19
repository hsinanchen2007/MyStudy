### 解题思路
其实不太想用long long，可惜用int会报错，不知道有没有合适的方式可以避开long long

### 代码

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        if(n<9 && n>=0)
        {
            return n;
        }
        long long long_n=n;
        long long digits=1, step=9, base=0;
        long long left_bound=0;
        long long right_bound=left_bound+digits*step;
        while (long_n>right_bound)
        {
            left_bound=right_bound;
            digits++;
            step=step*10;
            base=base*10+9;
            right_bound=left_bound+digits*step;
        }

        long long quot=(long_n-left_bound)/digits;
        long remains=(long_n-left_bound)%digits;
        if (remains) {
            quot++;
        }

        long target=base+quot;
        if (remains==0)
        {
            remains=digits;
        }
        remains--;
        return to_string(target)[remains]-'0';
    }
};

```
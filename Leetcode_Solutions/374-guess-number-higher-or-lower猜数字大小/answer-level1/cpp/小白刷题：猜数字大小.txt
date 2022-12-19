送分题，二分查找，而且这次不用考虑miss的情况

代码：
```
class Solution {
public:
    int guessNumber(int n) {
        long long start = 1, finish = n;
        while (finish - start > 1) {
            long long middle = (start + finish) / 2;
            if (guess(middle) == 0)
                return middle;
            else if (guess(middle) == 1)
                start = middle;
            else
                finish = middle;
        }
        if (guess(start) == 0)
            return start;
        else
            return finish;
    }
};
```

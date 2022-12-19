思路是先确定一个1的个数，然后用二分去查找这个底数。但是经常越界，不得以加了很多判断条件，结果时间贼慢。

```
class Solution {
public:
    typedef unsigned long long usll;
    usll spow(usll x, usll n, usll num) {
        usll res = 1;
        n >>= 1;
        int maxSize = (int)(to_string(num).size() - to_string(x).size() + 1);
        usll t = x;
        while (n) {
            res += t;
            if (n > 1 && to_string(t).size() > maxSize) {
                return num + 1;
            }
            t = t * x;
            n >>= 1;
        }
        return res;
    }
    
    string smallestGoodBase(string n) {
        usll num = stoll(n);
        usll i = 1;
        usll maxR = num;
        usll res = num;
        while (true) {
            if (maxR <= 2 || spow(2, i, num) > num) {
                break;
            }
            usll l = 1;
            usll r = maxR;

            while (l < r) {
                usll mid = l + ((r-l)>>1);
                usll t = spow(mid, i, num);
                if (t == num) {
                    res = min(mid, res);
                    break;
                } else if (t < num) {
                    l = mid + 1;
                } else {
                    r = mid;
                    maxR = r;
                }
            }
            i = (i<<1) + 1;
        }

        return to_string(res);
    }
};
```
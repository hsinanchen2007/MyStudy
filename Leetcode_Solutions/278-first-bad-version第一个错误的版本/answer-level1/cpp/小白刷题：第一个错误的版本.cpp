送分题，二分查找，注意边界和int范围问题，中间变量全部用long long

代码：
```
class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1))
            return 1;
        else {
            long long begin = 1,end = n;
            while (end - begin > 1) {
                long long temp = end + begin;
                long long middle = temp / 2;
                if (isBadVersion(middle))
                    end = middle;
                else
                    begin = middle;
            }
            return end;
        }
    }
};
```

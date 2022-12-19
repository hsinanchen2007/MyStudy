### 解题思路
二分查找法模板：(永不死循环)
（1）start + 1 < end 不死循环，问题降解为2个数
 (2) mid = start + (end - start)/2; 防止溢出
（3）start(end) = mid; 不用多考虑
（4）最后对 start 和 end 做个判断，根据题目要求看到底数出谁

### 代码

```cpp
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 0) return 0;
        if(n == 1 ){
            if(isBadVersion(n)) {
                return 1;
            } else {
                return 0;
            }
        }
        long start = 1;
        long end = n;
        while (start + 1 < end) {
            long mid = start + (end - start)/2;
            if (isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (isBadVersion(start)) {
            return start;
        } else {
            return end;
        }
    }
};
```
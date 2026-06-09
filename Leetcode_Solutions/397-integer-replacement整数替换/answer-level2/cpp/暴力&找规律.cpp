坑题，贪心地考虑尽量做除法，但是有corner case：留意到4的倍数可以除以两次2，因此有且仅有一种情况是二进制下从低到高第2位为1的奇数要加一。此外还要考虑n==3的时候-1比+1要少。
此外(1111...11)_31-1这个数加1会溢出，所以特判掉 or 开long long.

```c++
class Solution {
public:
  int integerReplacement(int n) {
    int ret = 0;
    if(n == 2147483647) return 32;
    while (n > 1) {
      if (n & 1) {
        if ((n & 2) == 2 && n > 3) n += 1;
        else n--;
        ret++;
      } else {
        n >>= 1;
        ret++;
      }
    }
    return ret;
  }
};
```
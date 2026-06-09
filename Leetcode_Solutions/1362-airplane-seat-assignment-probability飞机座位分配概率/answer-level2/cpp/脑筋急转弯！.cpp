### 解题思路
如果只有一个人 那肯定不会坐错
有两个人 50%的概率会做错
三个人以上 第一个人坐错了 后面的人继续上上上
然后 到了那个被做错的人 他又像是第一个人 坐做错的位子 以此类推一直是二分之一

### 代码

```cpp
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n==1?1:0.5;
    }
};
```
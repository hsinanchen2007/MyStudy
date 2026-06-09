### 解题思路
从数字后面开始处理，因为从前面处理起来不好取前几位。
首先肯定是可以将最后一位去除之后，递归计算剩余的有多少种情况。
另外一个就是看最后两位组成的数字是否在0~25之间，这里有个坑，就是倒数第二位数字不能是0，否则是错误的。

### 代码

```cpp
class Solution {
public:
    int translateNum(int num) {
            if (num < 10) {
        return 1;
    }
    int res = translateNum(num/10);
    int num_22 = num%100;
    int num_2 = (num/10)%10;
    if (num_2 > 0 && num_22 < 26) {
        res += translateNum(num/100);
    }
    return res;
    }
};
```
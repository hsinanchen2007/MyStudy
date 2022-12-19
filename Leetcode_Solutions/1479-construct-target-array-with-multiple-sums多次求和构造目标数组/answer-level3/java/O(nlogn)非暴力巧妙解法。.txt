### 解题思路
找规律可以得知，无论怎么相加怎么变化，数组中的数均为n(l-1)+1的形式，其中n是任意数，l是数组长度，这个自己手算几遍体会一下。再对target数组排序，判断一下相邻两个数的大小情况，满足即可成立。
时间复杂度O(nlogn)
![图片.png](https://pic.leetcode-cn.com/64a58c5a427e15b091b8c0787de14ece7078136a35b941ad2101bbbee6149515-%E5%9B%BE%E7%89%87.png)


PS：通过了所有数据测试不代表完全正确，但我自己测试没有发现有问题，如果发现问题可以在下方评论。
### 代码

```java
class Solution {
    public boolean isPossible(int[] target) {
        int l = target.length;
        if(l == 1 && target[0] == 1)
            return true;
        if(l == 1 && target[0] != 1)
            return false;
        for (int i = 0; i < target.length; i++) {
            if ((target[i] - 1) % (l - 1) != 0)
                return false;
        }
        Arrays.sort(target);
        long ssum = l - 1;
        for (int i = 0; i < target.length; i++) {
            if (target[i] == 1)
                continue;
            else{
                if (target[i] < ssum)
                    return false;
                ssum += target[i] - 1;
            }
        }
        return true;
    }
}
```
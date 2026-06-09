![1583738538(1).jpg](https://pic.leetcode-cn.com/f0c314565c26e75626b03dde63de74a4ba8309b4d04818d9225e71cbb07731eb-1583738538\(1\).jpg)
# 思路
下标：`[0,1,2,3,4,5,6,7,8,9]`
数值：`[1,1,6,5,6,6,1,1,1,1]`

从左往右先找到2种树，即`(1, 6)`。
当end下标为`3`时，遇到了第3种树(`5`)，而第3种树(`5`)左边的树是`6`，将2种树的状态更新为`(6,5)`。
以此类推，当下标为`6`时，遇到了第3种树(`1`)，而第3种树(`1`)左边的树是`6`，将2种树的状态更新为`(6,1)`。

即每次2种树的状态更新为`(第3种树的左边的树, 第3种树)`。
当理解上述思路后，就开始计数**由这2种树**所构成的**连续子数组**。
`(1, 6) -> [1, 1, 6] -> 连续子数组长度3`
`(6, 5) -> [6, 5, 6, 6] -> 连续子数组长度为4`
`(6, 1) -> [6, 6, 1, 1, 1, 1] -> 连续子数组长度为6`
取连续子数组的最长长度作为返回结果，也就是`6`。

# 代码
```java
class Solution {
    public int totalFruit(int[] tree) {
        int res = 0, len = tree.length;
        int one = tree[0], two, begin = 0, end = 1; //2种树的状态(one, two)， one初始化为tree数组的第1个元素
        while (end < len && tree[end] == one)   //寻找two的初始值，以构成初始(one, two)
            ++end;
        if (end == len) return len; //若整个数组的元素都由初始的(one, two)所构成，则直接返回数组长度
        two = tree[end++];  //构成初始的(one, two)
        for (; end < len; ++end) {
            if (one != tree[end] && two != tree[end]) { //遇到了第3种树
                res = Math.max(res, end - begin);   //更新最终返回结果
                one = tree[end - 1];    //(one, two)更新为(第3种树的左边的树, 第3种树)
                two = tree[end];
                begin = end - 1;    //更新由当前(one, two)所构成的连续子数组的左边界
                while (begin > -1 && tree[begin - 1] == one)   //向左寻找由one构成的连续子数组
                    --begin;
            }
        }
        return Math.max(res, end - begin);
    }
}
```

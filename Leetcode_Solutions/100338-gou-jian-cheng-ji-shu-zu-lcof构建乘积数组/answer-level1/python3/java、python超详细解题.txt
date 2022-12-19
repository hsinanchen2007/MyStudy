## 解题分析
题目要求不能使用除法，所以你求出所有的数的乘积，然后再除以每个数构结果集的第一想法就流产了；

这道题就是要求结果数组上的每一个数，都是原数组除了这个位置的数的乘积；

![在这里插入图片描述](https://pic.leetcode-cn.com/825a287e48a91afd584ecab3601661b3152591403cdff05da31c4dcd8805fee9.png)
以第二个节点为例，其实就是这个当前节点元素所有在原数组左边的元素乘积乘以原数组在这个索引右边的元素乘积；

那么我们的做法就是，先把每一个元素的左边的乘积和右边的乘积都算出来，然后新的数组的元素就等于这个元素左边的乘积加上右边的乘积；

如上图中的示例，所有左边的乘积为：
![在这里插入图片描述](https://pic.leetcode-cn.com/612e034dccc9646273db5ad7880f3547ede4daab523ae0f12c0941af8d868dbd.png)
这个数组上所有的位置上的数都是原数组此位置上的书的左边的所有元素的乘积

如上图中的示例，所有右边的乘积为：
![在这里插入图片描述](https://pic.leetcode-cn.com/00a192a9273f662826c005809f5525a4738f1dbb30fe79de3ffcefd47a847a35.png)
这个数组上所有的位置上的数都是原数组此位置上的书的右边的所有元素的乘积，

最后所求数组即使这两个数据的相同位置索引的乘积构成的新数组；

![在这里插入图片描述](https://pic.leetcode-cn.com/cdcce312d7a2a5f4a88e3ccf8481f519f4ed49a33d0b643ff98a42aa741d7feb.png)
然后我们使用累乘，少定义两个数组即可完成最优算法；


## 代码
ps：这里笔者使用的jdk为1.8、Python3.7版本

- java实现
```java
class Solution {
    public int[] constructArr(int[] a) {
        if (Objects.isNull(a) || a.length == 0) {
            return new int[]{};
        }
        int[] res = new int[a.length];
        int left = 1;
        for (int i = 0; i < res.length; i++) {
            res[i] =left;
            left *= a[i];
        }
        int right = 1;
        for (int i = res.length - 1; i >= 0; i--) {
            res[i] *= right;
            right *= a[i];
        }
        return res;
    }
}
```

- Python实现

```python
class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        if a is None or len(a) == 0:
            return []
        res = [None] * len(a)
        left = 1
        for i in range(len(a)):
            res[i] = left
            left *= a[i]
        right = 1
        for i in reversed(range(len(a))):
            res[i] *= right
            right *= a[i]
        return res
```
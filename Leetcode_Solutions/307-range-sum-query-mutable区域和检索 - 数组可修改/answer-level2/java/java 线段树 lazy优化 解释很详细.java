## 代码

> 代码

- 10/10 cases passed (14 ms)
- Your runtime beats 100 % of java submissions
- Your memory usage beats 76.13 % of java submissions (47.1 MB)

```java

class NumArray {
    int[] tree;
    int n;
    public NumArray(int[] nums) {
        if (nums.length > 0) {
            n = nums.length;
            tree = new int[n * 2];
            buildTree(nums);
        }
    }

    private void buildTree(int[] nums) {
        for (int i = n, j = 0;  i < 2 * n; i++,  j++)
            tree[i] = nums[j];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    void update(int pos, int val) {
        pos += n;
        int diff = val - tree[pos];
        //tree[pos] = val;
        while(pos > 0){
            tree[pos] += diff;
            pos /= 2;
        }
    }
    

    public int sumRange(int left, int right) {
        // 找到数组中对应left的index
        left += n;
        // 找到数组中对于right的index
        right += n;
        int sum = 0;
        while (left <= right) {
            // left和right对应的一定是叶子节点
            // left的如果是其父亲的右儿子，right如果是父亲的做儿子
            // 就立刻把自己加上，因为查询区间没有覆盖父亲，只覆盖了自己。
            if ((left % 2) == 1) {
               sum += tree[left];
               left++;
            }
            if ((right % 2) == 0) {
               sum += tree[right];
               right--;
            }
            // 找到left和right的父亲节点
            left /= 2;
            right /= 2;
        }
        return sum;
    }
}
```

## 主要操作

### 建树

使用数组建树

数组长度为N的2倍即可

1:(n-1) 放非叶子节点，n:2n-1放叶子节点(即数据本身)

`注意，非叶子节点个数为(n-1)个，所以 0 位用不到，占位作用。`

```java
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
```

### 更新

先求个更新值和原来值的差值

然后通过 /= 2操作从底至上找到所以的父亲节点并更新，搞定。

### 查询

看注释

### 介绍下lazy思想

> lazy思想主要用于区间更新情况

在此通俗的解释我理解的Lazy意思

比如现在需要对[a,b]区间值进行加c操作，那么就从根节点[1,n]开始调用update函数进行操作

如果刚好执行到一个子节点，它的节点标记为rt，这时`tree[rt].l== a && tree[rt].r == b` 这时我们可以一步更新此时rt节点的sum[rt]的值，`sum[rt] += c* (tree[rt].r - tree[rt].l + 1)`

注意关键的时刻来了，如果此时按照常规的线段树的update操作，这时候还应该更新rt子节点的sum[]值，而Lazy思想恰恰是暂时不更新rt子节点的sum[]值，到此就return，直到下次需要用到rt子节点的值的时候才去更新，这样避免许多可能无用的操作，从而节省时间。

写的话。。等以后吧


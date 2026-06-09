**方法一：暴力循环**
```
class Solution {
    /**
    * 思路：
    * 由题可知为求约瑟夫环剩余数字。
    * (1) 创建 ArrayList 初始化存储 n 个数字。
    * (2) 每次循环移除从当前位置开始的第 m 个数字。
    * (3) 直到 ArrayList 中剩下一个数字返回。
    */
    public int lastRemaining(int n, int m) {
        if (m == 1) {
            return n-1;
        } else if (n == 1) {
            return 0;
        }
        List<Integer> list = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            list.add(i);
        }
        int cut = 0;
        while (n > 1) {
            // 每次要移除数字在 list 中的角标。
            cut = (cut + m - 1) % n;
            list.remove(cut);
            n--;
        }
        return list.get(0);
    }
}
```

**方法二：数学+递归**
```
class Solution {
    /**
    * 思路：
    * 由题构建函数 f(n,m) ，返回值为最终留下元素的序号(表示第几个)。
    *   因为 n 个数字的序列删除一个数之后变成 n - 1 个数字的序列，
    *   所以当 f(n - 1,m) = x 时，f(n,m) = (m + x) % n ，
    *   表示从 x 之后的第 m 个数。
    */
    public int lastRemaining(int n, int m) {
        if (m == 1) {
            return n-1;
        } else if (n == 1) {
            return 0;
        }
        int x = lastRemaining(n-1,m);
        return (m + x) % n;
    }
}
```

**方法三：数学+迭代**
```
class Solution {
    /**
    * 思路：
    * 同方法二，循环迭代得出第 n - 1 次删除后剩余的数字。
    */
    public int lastRemaining(int n, int m) {
        int ans = 0;
        // n为1时候可知ans为0，所以从n为2开始循环迭代删除   。
        for (int i = 2; i <= n; i++) {
            ans = (ans + m) % i;
        }
        return ans;
    }
}
```

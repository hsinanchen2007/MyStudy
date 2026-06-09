### 解题思路
由于n!各排列是有序的，那么我们按照排列的第一个数字对这n!个排列进行分类。
例如n = 3时，那么3！= 6排列可以被分为三类：
1开头、2开头、3开头。每一类的排列个数不难看出就是(n - 1)! = 2! = 2。
那么求第k个排列的问题可以做这样的转换：
    1. 先找出第k个排列的第一个数字是几。
        例如n = 3, k = 5时，由于1和2开头的数字排列共有4种，那么第4个排列落在了数字开头为3的分类上。可以用 5 / 2! = 2来判别第4个排列的开头数字为3。
    2. 然后开头第一个数字确定下来后，其实问题又转为找 (n - 1)!个排列中第k个排列的问题（这里的n -1个数字是将确定下来的第一个数字去除后的数字序列）。k有变化，每次都要更新。
        上面的例子，5 % 2！ = 1，那么代表第4个排列实际上落在了开头数字为3然后1和2排列中的第一个位置。
综上所述，经过多次迭代，每一次都将n个数字第k个排列转为n -1个数字 第k % （n -1）!的问题。
特殊情况：当k % (n - 1)! = 0时要特殊处理，这时要把k的值更新为 (n - 1)!
在代码实现过程中，为了始终保持n - 1个数字始终有序，因为每次去掉的数字有可能是从数字序列的中间去除的，使用了StringBuilder这种数据类型。

### 代码

```java
class Solution {
     public String getPermutation(int n, int k) {
        StringBuilder stringBuilder = new StringBuilder();
        StringBuilder nums = new StringBuilder();
        for (int i = 0; i < n; i++) {
            nums.append(i + 1);
        }
        while (nums.length() > 0){
            int nextN = jie(n - 1);
            int pos = k / nextN;
            int move = k % nextN;
            if (move == 0 && pos != 0)
                pos -= 1;
            stringBuilder.append(nums.charAt(pos));
            nums.deleteCharAt(pos);
            if (move == 0)
                k = nextN;
            else
                k = move;
            n -= 1;
        }
        return stringBuilder.toString();
    }

    private int jie(int num) {
        if (num == 1 || num == 0)
            return 1;
        return jie(num - 1) * num;
    }
}
```
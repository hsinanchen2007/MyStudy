### 解题思路
纯靠移动。
思路：其实将数组移动k次，就是将最后的k位挪到数组最前面
证明：
我们从后面几位开始挪动
条件：k < n
将第倒数第k位上的数挪k位到0的位置，同理挪到k + 1,...n - 1,到1...k - 1，我们得到一个模式： i >> k = (i + k) % n
这个公式可以由数学归纳法得到。
因此我们得到公式： i >> k = (i + k) % n
就可以利用Java数组移动特性，将最后k位先取出来，把数组往后挪，覆盖原有数据。
再将剩余的k位数放入数组前端。
欢迎来我的[博客](http://snowball.show/2020-01-05-rotatearray/)看我其他题的总结。
### 代码

```java
class Solution {
    public void rotate(int[] nums, int k) {
        int[] a = new int[k];
        int len = nums.length;
        k %= len;
        System.arraycopy(nums, len - k, a, 0, k);

        System.arraycopy(nums, 0, nums, k , len - k);
        System.arraycopy(a, 0, nums, 0, k);
    }
}
```
### 写在前面：
如果您觉得写得还可以，那就来关注在下的微信公众号吧“张氏文画”，不光有新鲜的 LeetCode 题解，还有经典的文章及短视频和大家分享，谢谢大家的关注！！！
![qrcode_for_gh_671e52fa1e78_258.jpg](https://pic.leetcode-cn.com/fa6a229fc23d58fb656a375382f96feecd9b6bc043183f36ee0d9ea9ffa3a12e-qrcode_for_gh_671e52fa1e78_258.jpg)

### 思路：

现在数组中有两个数字只出现1次，直接异或一次只能得到这两个数字的异或结果，但光从这个结果肯定无法得到这个两个数字。因此基于single number I 的思路——**数组只能有一个数字出现1次**。

**设题目中这两个只出现1次的数字分别为A和B，如果能将A，B分开到二个数组中，那显然符合“异或”解法的关键点了**。因此这个题目的关键点就是将A，B分开到二个数组中。由于A，B肯定是不相等的，因此在二进制上必定有一位是不同的。**根据这一位是0还是1可以将A，B分开到A组和B组**。而这个数组中其它数字要么就属于A组，要么就属于B组。再对A组和B组分别执行“异或”解法就可以得到A，B了。而要判断A，B在哪一位上不相同，只要根据A异或B的结果就可以知道了，**这个结果在二进制上为1的位就说明A，B在这一位上是不相同的。**

比如

```
int a[] = {1, 1, 3, 5, 2, 2}
```
整个数组异或的结果为3^5，即 **0x0011 ^ 0x0101 = 0x0110**

对0x0110，第1位（由低向高，从0开始）就是1。因此整个数组根据第1位是0还是1分成两组。

    a[0] =1  0x0001  第一组

    a[1] =1  0x0001  第一组

    a[2] =3  0x0011  第二组

    a[3] =5  0x0101  第一组

    a[4] =2  0x0010  第二组

    a[5] =2  0x0010  第二组

第一组有{1,1,5}，第二组有{3,2,3}，然后对这二组分别执行“异或”解法就可以得到5和3了。

### 代码：

时间复杂度O(n)，空间复杂度O(1)

```java
class Solution {
    public int[] singleNumber(int[] nums) {
        int [] res = new int [2];
        if (nums == null || nums.length < 2) {
            return res;
        }
        int xorRes = 0;
        for (int x : nums) {
            xorRes ^= x;
        }
        int temp = 1; // 用来标志第几位是 1
        while (true) {
            if ((xorRes & 1) == 1) {
                break;
            }
            temp = temp << 1;
            xorRes = xorRes >> 1; // 右移，从低到高
        }

        for (int y : nums) {
            if ((y & temp) == 0) { // 对应位是 0
                res[0] ^= y;
            } else {
                res[1] ^= y;
            }
        }
        return res;
    }
}
```

### Result：

Runtime：1ms

Your runtime beats 100% of java submissions.
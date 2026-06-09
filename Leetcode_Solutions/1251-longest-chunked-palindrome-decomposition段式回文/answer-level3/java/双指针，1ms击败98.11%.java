### 解题思路
左右两个指针
1.左边先走找到和右边指针相等的
2.然后右边递减判断相等是否能够覆盖到左指针此次开始的位置
3.如果覆盖到左边此次开始的位置表示可以划分为相同的段
4.如果不能覆盖，左边继续往右走，回到步骤1
时间复杂度O(n)，空间复杂度O(1)
为啥题解里面这么多dp的。
看到好多题解的代码都是用substr判断相等的，测试样例里面如果来个 aaa..(非常多a)aabaaa..(相同多的a)aab那不就退化成O(n^2)了么
不过好像官方测试样例里面确实没有这样的样例。。
### 代码

```java
    class Solution {
        public int longestDecomposition(String text) {
            int i = 0, j = text.length() - 1;
            int ans = 0;
            int i0 = 0, j0 = text.length() - 1, k = 0;
            while (i < j) {
                while (i < j) {
                    if (text.charAt(i++) == text.charAt(j)) {
                        break;
                    }
                }
                k = i--;
                while (i >= i0) {
                    if (text.charAt(j) != text.charAt(i)) {
                        break;
                    }
                    i--;
                    j--;
                }
                if (i < i0) {
                    ans += 2;
                    i0 = k;
                } else {
                    j = j0;
                }
                i = k;
                j0 = j;
            }
            ans = i0 > j0 ? ans : ans + 1;
            return ans;
        }
    }
```
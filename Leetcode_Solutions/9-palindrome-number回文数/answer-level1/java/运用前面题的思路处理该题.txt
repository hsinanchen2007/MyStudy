### 解题思路
![2020-02-25_154550.jpg](https://pic.leetcode-cn.com/dd4d1affcce3d611156a50a51c195742c6619b653aba3def8fed32b5a9746fa6-2020-02-25_154550.jpg)
1.由题意可知，所有的负数都是不满足要求的,遇到负数直接返回。
2.正数的情况，参照前面几道题(第七题，第八题)，可以先将这个正数进行反转，然后直接和原数比较进行返回。
3.反转正数的公式为：res = res * 10 + pop ，其中res为每次操作后的最终结果，pop为对每一位除10取余的结果。
### 复杂度分析
时间复杂度：O(n),n为给定的int类型数的位数
空间复杂度：O(1)
### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int res = 0;
        // 尽量不影响输入参数的值,使用临时变量接收替代。
        int temp = x;
        while(temp != 0) {
            int pop = temp % 10;
            res = res * 10 + pop;
            temp = temp / 10;
        }
        return x == res;
    }
}
```
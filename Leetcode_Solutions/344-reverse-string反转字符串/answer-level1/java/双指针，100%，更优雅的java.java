### 解题思路
1. 仔细读题，理解题目意思后，好简单的题目
2. 没错，双指针解法。
3. 没错，你需要看一下数组是偶数个和奇数个的情况；但是你会发现，无论是奇数个还是偶数个
都符合left <= right；比如【0，1，2，3】，很显然left到1，right到2，下一步就是left > right，循环结束;
如果是【0，1，2】，那么left和right都到1，下一步left > rigth，循环结束;
4. 需要考虑边界吗？这里考虑一个字符，这个循环也适用。那么数组长度为0呢？
emmmmmm......没考虑，直接测试，然后提交，没有问题。。。。。
5. 可以对left++，right--优化，直接写到数组中，是不是更优雅呢？这种做法经常有，你也可以这样。 

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        int  len = s.length, left = 0, right = len - 1;
        while (left <= right) {
            char tmp = s[left]; s[left++] = s[right]; s[right--] = tmp;
            // left++; right--;
        }
    }
}
```
![3.png](https://pic.leetcode-cn.com/1354413c3ee2cefd59e3796bd1a97aac22e4fd83a5110ec6bcb1519822312fbd-3.png)

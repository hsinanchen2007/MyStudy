执行用时 : **10 ms** , 在所有 Java 提交中击败了 **81.60%** 的用户
内存消耗 : **33.1 MB** , 在所有 Java 提交中击败了 **80.34%** 的用户

### 解题思路

- 写题时只想到题目给的是后继规则，搜索超时，所以从后往前破
- 提交后看到评论区里有大神从前向后计算，也是可行的
    - 从前向后的话，各个字母的定义就是
    `a ：以任意字母开头，当前结尾字母是'a'的序列数`
    - 从后向前的话，我的代码里，各个字母的定义就
    `a ：以任意字母结尾，当前开头字母是'a'的序列数`
1. 两种方式中，当前长度为1，所有字母都是初始化为1
2. 接下来都是补充后继/前趋字符
3. 两种方式中，计算加法的次数都是5(相等是必然的)
4. 用减法代替模运算的优化，代码注释中有解释
5. 中间用long，最后转int，**完全是懒得拆开连加号**

### 代码

```java
// 我的代码是反着来的
// 正着来也完完全全可以，两种方式平等
// a前面只可以是e i u
// e前面只可以是a i
// i前面只可以是e o
// o前面只可以是i
// u前面只可以是i o

class Solution {
        public int countVowelPermutation(int n) {
        long M = (int)1e9 + 7;
        // 初始,长度为1,以每一种字母结尾的序列都只有1种
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        while(n > 1) {
            n--;
            long aa = e + i + u;
            long ee = a + i;
            long ii = e + o;
            long uu = o + i;
            // o不会超过M
            o = i;
            
            // 两次加法最多大于2M，不会达到3M，对aa两次判断即可
            a = aa >= M ? aa - M : aa;
            a = a >= M ? a - M : a;
            e = ee >= M ? ee - M : ee;
            i = ii >= M ? ii - M : ii;
            u = uu >= M ? uu - M : uu;
        }

        long ans = a + e + i + o + u;

        // 4次加法，判断4次
        ans = ans >= M ? ans - M : ans;
        ans = ans >= M ? ans - M : ans;
        ans = ans >= M ? ans - M : ans;
        ans = ans >= M ? ans - M : ans;

        return (int)ans;
    }
}
```
### 解题思路

这道题重要是的要先看清题目，抓到重点--**二叉搜索树**，一种树形结构只会有一种可能的数字分布方式。
通过简单观察可以得到`cnt[0] = 1, cnt[1] = 1, cnt[2] = 2`，以root节点为中心，比如n=3时:

>   如果root=1, 左边结点为空，右边为2、3，共cnt[0] * cnt[2]种可能;
    如果root=2, 左边结点为1，右边为3，共cnt[1] * cnt[1]种可能;
    如果root=3, 左边结点为1、2，右边为空，共cnt[2] * cnt[0]种可能;

将上面三种可能的情况加起来，就得到结果5。
通过cnt[0]、cnt[1]、cnt[2]、cnt[3]同理可以得到cnt[4]，......

![图片.png](https://pic.leetcode-cn.com/9bdab17ff4f5914c8af84ec10db1318709f78b72ddcd8e478b9294a3017c2f54-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public int numTrees(int n) {
        int[] cnt = new int[n + 1];
        cnt[0] = 1;
        cnt[1] = 1;
        for (int i = 2; i <= n; i++) {
            cnt[i] = 0;
            for (int j = 0; j < i; j++) {
                cnt[i] += cnt[j] * cnt[i - j - 1];
            }
        }

        return cnt[n];
    }
}
```
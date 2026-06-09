### 解题思路
回溯思路
借鉴题解中大佬一个图： ![image.png](https://pic.leetcode-cn.com/881012c3ca4f061880c37013881b607c787f1096cd072ea29663b0f897853d6f-image.png)


### 代码

```java
class Solution {

    // 存储结果
    List<String> res = new ArrayList<>(10);

    /**
    * 交换法
    **/
    public String[] permutation(String s) {
        String[] sArr = s.split("");
        char[] cArr = new char[sArr.length];
        for (int i = 0; i < sArr.length; i++) {
            cArr[i] = sArr[i].charAt(0);
        }
        dfs(cArr, 0);
        return res.toArray(new String[res.size()]);
    }

    /**
    * 利用深度优先处理
    **/
    private void dfs(char[] sArr, int pos) {
        // 回溯结束条件
        if (pos >= sArr.length) {
            res.add(String.valueOf(sArr));
            return;
        }
        char tmp;
        for (int i = pos, len = sArr.length; i < len; i++) {
            // 如果pos和i之间有字符等于s[i], 则跳过
            if (judge(sArr, pos, i)) continue;
            // 做选择，交换
            tmp = sArr[pos];
            sArr[pos] = sArr[i];
            sArr[i] = tmp;
            // 继续递归
            dfs(sArr, pos + 1);
            // 撤销选择，交换回来
            tmp = sArr[pos];
            sArr[pos] = sArr[i];
            sArr[i] = tmp;
        }
    }

    private boolean judge(char[] sArr, int start, int end) {
        for (int i = start; i < end; i++) {
            if (sArr[i] == sArr[end]) return true;
        }
        return false;
    }

}
```
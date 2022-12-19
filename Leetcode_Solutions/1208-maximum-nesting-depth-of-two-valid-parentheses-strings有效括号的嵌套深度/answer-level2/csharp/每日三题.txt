![1111. 有效括号的嵌套深度.png](https://pic.leetcode-cn.com/1232763753f726c16863a3fea29632ea25b6e57a1acf03a4a5951b48e9458edd-1111.%20%E6%9C%89%E6%95%88%E6%8B%AC%E5%8F%B7%E7%9A%84%E5%B5%8C%E5%A5%97%E6%B7%B1%E5%BA%A6.png)
确保嵌套的括号相邻嵌套层数分到不同组即可保证深度最小，嘴笨，思路说不清，贴了代码就跑
```
public class Solution {
    public int[] MaxDepthAfterSplit(string seq) {
        bool isA = true;
        int len = seq.Length;
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = isA ? 0 : 1;
            if (i < len - 1 && seq[i] == seq[i + 1]) {
                isA = !isA;
            }
        }

        return res;
    }
}
```

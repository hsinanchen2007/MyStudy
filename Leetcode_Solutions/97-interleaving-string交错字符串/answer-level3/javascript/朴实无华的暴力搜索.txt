暴力搜索，从一个空的字符串（cur）开始，每次只能从s1 或者 s2中拿一个字符拼接到cur上
如果最终cur === s3则表示能找到答案
递归的层数为s3的长度，性能应该是堪忧的，不过还是能AC
```
var find = false
var isInterleave = function (s1, s2, s3) {
    find = false
    if (s1 + s2 == s3) return true //两种简单情况过滤掉，DFS不能计算这两种情况
    if (s1.length + s2.length != s3.length) return false

    dfs("", 0, 0, s1, s2, s3)
    return find
};
// i表示s1的下标, j标识s2的下标
function dfs(cur, i, j, s1, s2, s3) {
    if (i + j == s3.length) {
        find = true
        return
    }
    if (find) return // 找到了就直接回去
    if (i < s1.length && s1[i] == s3[i + j]) {
        dfs(cur + s1[i], i + 1, j, s1, s2, s3)
    }

    if (j < s2.length && s2[j] == s3[i + j]) {
        dfs(cur + s2[j], i, j + 1, s1, s2, s3)
    }
}
```

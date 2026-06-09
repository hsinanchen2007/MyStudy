// ### 解法：一行代码

// ```java
 public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return rec2[0] < rec1[2] && rec2[2] > rec1[0] && rec2[1] < rec1[3] && rec2[3] > rec1[1];
    }
// ```

// 思路分析：

// * 要看两个矩阵是否重叠，如果人为地选定一个矩形固定，我们考虑另外一个矩形与其相对位置就可以。
// * 接下来看图，看不重叠的情况与重叠情况，坐标之间有什么关系。

// ![isRectangleOverlap图示.png](https://pic.leetcode-cn.com/191ac08f752bc503ba72bf8c241ab12df167c34bc8a283c19150dc89e3f74769.png)

// * 前四个图，就是四种不交叠的情况，其他的都可以看做这四种的特殊情况。
//     * 矩形2的下底还在矩形1上底的下方（或重合），对应到题目坐标就是`rec2[1] >= rec1[3]`
//     * 矩形2的上底还在矩形1上底的下方（或重合），对应到题目的坐标是`rec2[3] <= rec1[1]`
//     * 矩形2的右边还在矩形1左边的左面（或重合）
//     * 矩形2的左边还在矩形1右边的右面（或重合）
//     * 不交叠情况只要满足其一就可以，所以用逻辑 或 进行连接就行。
// * 后四个图列举了一部分交叠的情况，要同时不满足上述不交叠的情况，所以要用逻辑且链接。`rec2[0] < rec1[2] && rec2[2] > rec1[0] && rec2[1] < rec1[3] && rec2[3] > rec1[1]`

// 运行结果：

// * 执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
// * 内存消耗 :37.3 MB, 在所有 Java 提交中击败了5.49%的用户

// 更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖
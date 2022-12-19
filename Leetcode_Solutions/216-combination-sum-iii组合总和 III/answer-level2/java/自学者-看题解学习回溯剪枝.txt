### 解题思路
* 求和采用减法形式直到自己为0为止
* 当前题目特殊之处是两个参数同时减少，组合少一个，求和减少到另外一个数的求和
* 两个因素影响求和的练习题目
* 之前采用list。remove（list.size()-1)感觉没有堆栈用起来好。
* 参考题解大佬EL1S的答案

### 代码

```java
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class Solution {

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList<>();

        // 根据官方对 Stack 的使用建议，这里将 Deque 对象当做 stack 使用
        // 注意只使用关于栈的接口
        Deque<Integer> path = new ArrayDeque<>();
        backtrack(k, n, 1, path, result);
        return result;
    }

    /**
     * @param k       剩下要找 k 个数
     * @param residue 剩余多少
     * @param start   下一轮搜索的起始元素是多少
     * @param path    深度优先遍历的路径参数（状态变量）
     * @param res     保存结果集的列表
     */
    private void backtrack(int k, int residue, int start, Deque<Integer> path, List<List<Integer>> result) {
        if (k == 0) {
            if (residue == 0) {
                result.add(new ArrayList<>(path));
                return;
            } else {
                return;
            }
        }        
        // 这一步判断可以放到上一层，减少递归深度
        if (residue < 0) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            path.addLast(i);
            backtrack(k - 1, residue - i, i + 1, path, result);
            path.removeLast();
        }
    }
}
```
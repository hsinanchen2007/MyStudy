### 解题思路

利用回溯的解法
1. 先生成 n * n的二维数组，数组元素用 . 来填充
2. 每一轮循环，把Q 依次放在 0 ~ n的位置
3. 判断在每个位置的时候是否满足竖的  和 左 右对角线 没有其他的 Q。若不满足直接跳出 探索下一个位置
4. 找到满足的位置后继续探索下一层。
5. 重复 2-4 知道满足找到最后一行
### 代码

```java
class Solution {
       public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        List<String> path = new ArrayList<>();
        char[][] nums = new char[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(nums[i], '.');
        }
        backtrack(nums,0, ans);
        return ans;
    }

    private void backtrack(char[][] nums, int currRow, List<List<String>> ans) {
        int len = nums.length;
        if (len == currRow) {
            List<String> path2 = new ArrayList<>();
            for (int i = 0; i < len; i++) {
                path2.add(String.valueOf(nums[i]));
            }
            ans.add(path2);
            return;
        }

        for (int col = 0; col < len; col++) {
            //判断这个位置是否合适
            boolean isok = true;
            for (int row = 0; row < currRow; row++) {
                //竖的有Q
                if (nums[row][col] == 'Q') {
                    isok = false;
                    break;
                }
                //判断对角线
                if (col + (currRow - row) < len && nums[row][col + (currRow - row)] == 'Q') {
                    isok = false;
                    break;
                }
                if (col - (currRow - row) >= 0 && nums[row][col - (currRow - row)] == 'Q') {
                    isok = false;
                    break;
                }
            }
            if (!isok) {
                continue;
            }
            //满足条件
            nums[currRow][col] = 'Q';
            backtrack(nums, currRow + 1, ans);
            nums[currRow][col] = '.';
        }
    }
}
```
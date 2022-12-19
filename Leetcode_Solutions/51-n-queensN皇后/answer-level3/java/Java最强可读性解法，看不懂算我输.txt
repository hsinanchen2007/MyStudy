类似递归模板，分四个部分：
1. 终止条件
2. 处理当前层逻辑
3. 递归，调自己
4. 恢复当前层状态

```
public void recursive(int param, int level) {
    // recursive termintor
    if (level > MAX_LEVEL) {
        // process result

        return;
    }

    // process current logic

    // drill down
    recursive(newParam, level + 1);
    // restore current status 

}
```
根据模板对应代码：
```
class Solution {
    List<List<String>> result = new ArrayList<>();
    private int n;
    // 之前皇后所能攻击到的位置
    HashSet cols = new HashSet();
    HashSet pie = new HashSet(); //撇
    HashSet na = new HashSet(); // 捺

    public List<List<String>> solveNQueens(int n) {
        this.n = n;
        recursive(new ArrayList<>(), 0);
        return result;
    }

    private void recursive(List<String> currentQueen, int row) {
        // recursive terminator(终止条件)
        if (currentQueen.size() == n) {
            result.add(new ArrayList<String>(currentQueen));
            return;
        }
        // process courrent logic
        // 遍历列(col)，传入的参数是行(row)
        for (int col = 0; col < n; col++) {
            if (cols.contains(col) || pie.contains(row + col) || na.contains(n + row - col)) 
                continue;// 能被攻击到就跳过本层循环
            cols.add(col);
            pie.add(row + col);
            na.add(n + row - col);

            // col是皇后对应列的位置，生成奇奇怪怪的格式，形如：[".Q..","...Q","Q...","..Q."]
            StringBuilder cur =new StringBuilder("");
            for(int i = 0; i < n; i++) {
                if (i == col) cur.append("Q");
                else cur = cur.append(".");
            }
            currentQueen.add(cur.toString());

            // dill down(下探下一层)
            recursive(currentQueen, row + 1);

            // restore current status (清除老皇后和其势力痕迹)
            cols.remove(col);
            pie.remove(row + col);
            na.remove(n + row - col);
            currentQueen.remove(currentQueen.size() - 1);
        }
    }
}
```

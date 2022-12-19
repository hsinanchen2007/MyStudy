
题目给出的算法结构为
```
class Solution {
    public List<List<String>> solveNQueens(int n) {

    }
}
```
首先题目要求返回的类型为 `List<List<String>>`，那么我们就新建一个 `List<List<String>>` 作为全局变量，最后将其返回。
```
class Solution {
    List<List<String>> res = new ArrayList<>();
    public List<List<String>> solveNQueens(int n) {
        return res;
    }
}
```
再看看返回的结构，`List<List<String>>`。因此我们需要写一个包含 `List<String>` 的辅助函数，并且递归的时候需要知道到了哪一行，加上一些判断条件，此时结构变成了
```
class Solution {
    List<List<String>> res = new ArrayList<>();
    public List<List<String>> solveNQueens(int n) {
        if(n < 1){
            return res;
        }
        List<Integer> list = new ArrayList<>();

        help(0,n,list);
        return res;
    }
    private void help(int row, int n, List<Integer> list){
    

    }
}
```
重点就是如何进行递归。递归的第一步，当然是写递归的终止条件啦，没有终止条件的递归会进入死循环。在本题中，如果row == n，表明这其实是一组解的，因此代码变成下面这个样子
```
class Solution {
    List<List<String>> res = new ArrayList<>();

    public List<List<String>> solveNQueens(int n) {
        if(n < 1){
            return res;
        }
        List<Integer> list = new ArrayList<>();

        help(0,n,list);
        return res;
    }
    private void help(int row, int n, List<Integer> list){
        if(row == n){
            List<String> strList = new ArrayList<>();
            for(Integer num:list){
                char[] t = new char[n];
                Arrays.fill(t,'.');
                t[num] = 'Q';
                strList.add(new String(t));
            }
            res.add(strList);
            return;
        }
    }
}
```
我们要看他是不是N皇后的一组解，对于每一列，我们都尝试一下行不行。如何判断行不行呢？无非就是看对应的列，左斜和右斜上有没有数。如果满足条件就可以将其加入list，进入下一行继续递归，否则此递归流程结束。注意，每次递归结束以后，需要回溯。
```
class Solution {
	List<List<String>> res = new ArrayList<>();

    public List<List<String>> solveNQueens(int n) {
        if(n < 1){
            return res;
        }
        List<Integer> list = new ArrayList<>();

        help(0,n,list);
        return res;
    }
    private void help(int row, int n, List<Integer> list){
        if(row == n){
            List<String> strList = new ArrayList<>();
            for(Integer num:list){
                char[] t = new char[n];
                Arrays.fill(t,'.');
                t[num] = 'Q';
                strList.add(new String(t));
            }
            res.add(strList);
            return;

        }
        //每一列都尝试一下
        for (int col = 0; col < n; col++) {
            //当前列是否合法
            if (!list.contains(col)) {
                //左斜与右协是否哈法
                if(!isDiagonalAttack(list,col)){
                    list.add(col);
                    help(row+1,n,list);
                    //回溯
                    list.remove(list.size()-1);
                }
            }

        }

    }

    private boolean isDiagonalAttack(List<Integer> currentQueen, int i) {
        int currentRow = currentQueen.size();
        int currentCol = i;
        //判断每一行的皇后的情况
        for (int row = 0; row < currentQueen.size(); row++) {
            //左上角的对角线和右上角的对角线，差要么相等，要么互为相反数，直接写成了绝对值
            if (Math.abs(currentRow - row) == Math.abs(currentCol - currentQueen.get(row))) {
                return true;
            }
        }
        return false;
    }
}
```

### 类似题目
[leetcode 39. 组合总和](https://leetcode-cn.com/problems/combination-sum/solution/fei-chang-xiang-xi-de-di-gui-hui-su-tao-lu-by-re-2/)

[leetcode 46. 全排列](https://leetcode-cn.com/problems/permutations/solution/liang-chong-fang-fa-xiang-xi-de-jie-shao-di-gui-gu/)
该题主要用回溯法求解。
这里我用了一维数组来摆放皇后。下面是具体思路。
首先我们要考虑什么情况下能放置皇后。任意两个皇后不能处于同一行，同一列或同一斜线上。
我这里想到用一维数组优化空间。一维数组的下标表示行，元素值表示列。一维数组天然了解决了皇后处于同一行的问题，只要每个元素的值不同
也就解决了处于同一列的问题。然后就剩下处于同一斜线上的问题了。如果 |i-j| != |arr[i] - arr[j]| （行的差的绝对值不等于列的差的绝对值）那就是不处于同一斜线上。
```
class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> allList = new ArrayList<>();
        int[] arr = new int[n];
        putQueen(allList, arr, 0, arr.length);
        return allList;
    }
    
    /**
     * @Description     使用回溯法摆放皇后
     * @param allList   结果集
     * @param arr       放置皇后的数组
     * @param v         第几个皇后
     * @param n         皇后的数量
     */
    private void putQueen(List<List<String>> allList, int[] arr, int v, int n) {
        //放完了全部的皇后
        if (v == n) {
            add(allList, arr);
            return ;
        }

        for (int i = 0; i < n; i++) {
            arr[v] = i;
            if (canPut(arr, v))
                putQueen(allList, arr, v + 1, n);
        }
    }

    /**
     * @Description 判读是否能放置皇后
     * @param arr   放置皇后的数组
     * @param v     第几个皇后
     */
    private boolean canPut(int[] arr, int v) {
        for (int i = 0; i < v; i++) {
            if (arr[i] == arr[v] || Math.abs(i - v) == Math.abs(arr[i] - arr[v]))
                return false;
        }
        return true;
    }

    /**
     * @Description     将正确摆放好的结果添加到结果集中
     * @param allList   结果集
     * @param arr       放置皇后的数组
     */
    private void add(List<List<String>> allList, int[] arr) {
        //数组长度
        int n = arr.length;
        //用二维字符数组存放棋盘
        char[][] chs = new char[n][n];
        
        //初始化棋盘
        for (int i = 0; i < n; i++) {
            Arrays.fill(chs[i], ',');
        }
        
        //根据arr[i]的值摆放皇后的位置
        for (int i = 0; i < n; i++) {
            chs[i][arr[i]] = 'Q';
        }
        
        //将二维数组转化为字符串添加到list集合中
        List<String> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(String.valueOf(chs[i]));
        }
        allList.add(list);
    }
}
```

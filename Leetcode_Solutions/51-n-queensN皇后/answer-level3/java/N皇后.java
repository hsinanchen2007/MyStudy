### 解题思路
首先要了解经典的8皇后问题的思路：
 1. 第一个皇后摆在棋盘的第一行第i列。
 2. 第二个皇后从棋盘的第二行第一列开始放置，每一次放置都要判断与第一个皇后是否能够相互攻击（两个皇后处在同一行或同一列或同一个斜线上）；如果可以则继续第三步。
 3. 继续放第三个皇后，按照第二步的判断条件寻找合适的位置；直到8个皇后摆放完毕，一个正确的解就出来了。
 4. 当得到第一个正确解时，这个解只是第一个皇后放在第一行的某一列的一种解；这时需要回溯将第一个皇后放在某一列的所有解全部找出；
 5. 将第一个皇后放在第一行第i + 1列，然后重复2 3 4步骤，就能将所有结果全部求解出来。
上述思路有两个主要问题需要解决：1. 如果存放每次求解的结果；2. 如何判断一个皇后放的位置与已落点的皇后不会相互攻击。
1. 存放每次求解的结果：
    使用一个一维数组，长度为8，那么数组的下标就代表行，数组的值代表皇后所在的列。这个数组就能存放每次求解的结果。
2. 判断皇后是否相互攻击：
    由于每次都是逐个皇后落位棋盘的，所以皇后肯定不会在同一行上。根据结果的一维数组的特性，判断两个皇后是否在同一列那么只需要判断数组两个下标对应的数组值是否相等即可；
    关于判断两个皇后是否在同一条斜线上，我们首先做这么一个思路转换：将8 x 8的棋盘转换成直角坐标系上的一个矩阵其中 0=< x <8, 0<= y < 8。那么皇后在棋盘上的行列位置可以转为直角坐标系的坐标，因此在同一斜线就代表着两个坐标点的连线一定平行于棋盘的对角线，那么两个坐标点连线的斜率也就始终为1。根据这一特性，如果两个点的行差和列差相等，就认为两个皇后在一条斜线上。
8皇后问题的思路适用于N皇后的问题，所以这题可以直接按照8皇后问题直接求解

### 代码

```java
class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        int[] arr = new int[n];
        getResult(result, 0, n, arr);
        return result;
    }

    /**
     * 将每一次摆放的结果存入到结果集中
     */
    public void addResult(List<List<String>> result, int[] arr) {
        List<String> list = new ArrayList<>();
        //将整数数组结果转为题目要求的结果
        for (int i = 0; i < arr.length; i++) {
            //每一行的皇后存放结果
            char[] chars = new char[arr.length];
            for (int j = 0; j < arr.length; j++) {
                chars[j] = '.';
            }
            //整数数组的值即皇后所在的列，只需要将字符数组的列下标改为Q即可
            chars[arr[i]] = 'Q';
            list.add(String.valueOf(chars));
        }
        result.add(list);
    }

    /**
     * @param n 第n + 1个皇后
     * @return 不在同一列或同一斜线上返回true
     */
    public boolean judge(int n, int[] arr) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == arr[n] || Math.abs(n - i) == Math.abs(arr[i] - arr[n]))
                return false;
        }
        return true;
    }

    /**
     * @param n 第n + 1个皇后
     *          开始摆放皇后的位置，每次摆放的结果都存到整型数组arr中
     */
    public void getResult(List<List<String>> result, int n, int max, int[] arr) {
        if (n == max) {
            addResult(result, arr);
            return;
        }
        for (int i = 0; i < max; i++) {
            //首先将皇后摆在当前行的第一列 （i从0开始）
            arr[n] = i;
            //如果与前面的皇后不冲突，则摆放下一个皇后
            if (judge(n, arr))
                getResult(result, n + 1, max, arr);
            //冲突，则向后挪一列
        }
    }
}
```
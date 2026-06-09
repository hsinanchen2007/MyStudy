### 代码

```java
class Solution {
    int[] visit =  new int[10];
    int[][] arr;
    int m, n;
    int cur = 0;
    public int numberOfPatterns(int m, int n) {
        arr = new int[10][10];
        this.m = m;
        this.n = n;
        arr[1][3] = arr[3][1] = 2;
        arr[1][7] = arr[7][1] = 4;
        arr[4][6] = arr[6][4] = 5;
        arr[7][9] = arr[9][7] = 8;
        arr[2][8] = arr[8][2] = 5;
        arr[3][9] = arr[9][3] = 6;
        arr[1][9] = arr[9][1] = 5;
        arr[3][7] = arr[7][3] = 5;

        int res = 0;
        helper(1, 1);
        res += 4 * cur;
        cur = 0;
        helper(2, 1);
        res += 4 * cur;
        cur = 0;
        helper(5, 1);
        res += cur;
        return res;
    }
    void helper(int index, int length) {
        if (length > n) return;
        if (length >= m) cur ++;
        length ++;
        
        visit[index] = 1;
        for (int i = 1; i <= 9; i++ ){
            if (visit[i] == 0 && (arr[index][i] == 0 || visit[arr[index][i]] == 1 )) {
                helper(i, length);
            }
        }
        visit[index] = 0;
    }
}
```
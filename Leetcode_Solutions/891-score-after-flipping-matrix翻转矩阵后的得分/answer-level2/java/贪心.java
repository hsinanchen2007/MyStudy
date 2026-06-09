### 解题思路
1. 先一行一行遍历，若最高位为0，则这一行反转
2. 然后一列一列遍历，若0的个数多余1的个数，则这一列反转。

### 代码

```java
class Solution {
    public int matrixScore(int[][] A) {
        for (int[] ints : A) {
            if (ints[0] == 0){
                for (int j = 0; j < ints.length; j++) {
                    if (ints[j] == 0)
                        ints[j] = 1;
                    else
                        ints[j] = 0;
                }
            }
        }
        //对每一列 若 0 的个数大于 1 的个数，则反转
        for(int i = 0 ;i < A[0].length;i++){
            if (_0_bigger_than_1(A, i))
                _0_1_reverse(A, i);
        }
        int sum = 0;
        for (int i = 0; i < A.length; i++) {
            int temp = 0;
            for (int j = 0; j < A[i].length; j++) {
                temp = temp * 2 + A[i][j];
            }
            sum += temp;
        }
        return sum;
    }

    private boolean _0_bigger_than_1(int[][] num, int i){
        int num0 = 0;
        int num1 = 0;
        for (int j = 0; j < num.length; j++) {
            if (num[j][i] == 0)
                num0++;
            else
                num1++;
        }
        if (num0 > num1)
            return true;
        return false;
    }

    private void _0_1_reverse(int[][] num, int i){
        for (int j = 0; j < num.length; j++) {
            if (num[j][i] == 0)
                num[j][i] = 1;
            else
                num[j][i] = 0;
        }
    }
}
```
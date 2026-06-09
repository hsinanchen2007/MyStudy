### 解题思路
先求出每行的战斗力，并且放入一个临时数组中。
然后从这个临时数组中找到战斗力最小的索引（如果战斗力相同，则取索引值最小的），找到后，将该索引位置的战斗力置为-1，并且以后使用的时候略过该位置。
循环k次，即可得到战斗力最弱的k行。
注意：查找战斗力最小元素时，最小值初始化为max[0].length+1(每行战斗力最大为max[0].length)

### 代码

```java
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int[] powerA = new int[mat.length];
        for (int i = 0; i < mat.length; i++) {
            int power = 0;
            for (int j = 0; j < mat[i].length; j++) {
                int p = mat[i][j];
                if (p == 0) {
                    break;
                }
                power += p;
            }
            powerA[i] = power;
        }

        int[] result = new int[k];
        for (int x = 0; x < k; x++) {
            int min = mat[0].length +1;
            int index = 0;
            for (int i = 0; i < powerA.length; i++) {
                if (powerA[i] < min && powerA[i] != -1) {
                    min = powerA[i];
                    index = i;
                }
            }
            powerA[index] = -1;
            result[x] = index;
        }
        return result;
    }
}
```
思路：创建一个一维数组，根据条件一，信赖其他人的都排除，将数组对应位置的值设为-1；根据条件二，有人被信赖且他没有信赖其他人，则其被信赖数+1，将数组对应位置的值+1；最后遍历数组，返回值为N-1的索引。

```
class Solution {
   public int findJudge(int N, int[][] trust) {

        int[] trusted = new int[N + 1];
        trusted[0] = -1;
       

        for (int[] tr : trust) {
            trusted[tr[0]] = -1;
            if (trusted[tr[1]] != -1) {
                trusted[tr[1]]++;
            }
        }

        for (int i = 0; i < trusted.length; i++) {
            if (trusted[i] == N - 1 ) {
                return i;
            }
        }

        return N == 1 ? 1 : -1;
    }
}
```

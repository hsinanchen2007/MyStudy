这个是个简单题，代码那么长，合适吗？

```
    public int[] kWeakestRows(int[][] mat, int k) {
        int[][] tmp = new int[mat.length][2];
        for(int i = 0; i < mat.length; i++){
            for(int j = 0; j < mat[0].length; j++){
                tmp[i][0] = i;
                if(mat[i][j] == 1)  tmp[i][1] += 1;
            }
        }
        Arrays.sort(tmp, (o1, o2) -> o1[1] - o2[1]);
        int[] res = new int[k];
        for(int i =0; i < k; i++){
            res[i] = tmp[i][0];
        }
        return res;
    }
```

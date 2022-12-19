### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findCircleNum(int[][] M) {
        int[] parent = new int[M.length];
        Arrays.fill(parent,-1);
        for (int i = 0; i < M.length; i++) {
            for (int j = 0; j < M[i].length; j++) {
                if (M[i][j] == 1 && i != j){
                    union(parent,i,j);
                }
            }
        }
        int cnt = 0;
        for (int i : parent) {
            if (i == -1)
                cnt++;
        }
        return cnt;
    }

    private int find(int[] parent,int i){
        //找i的父辈
        if (parent[i] == -1)
            return i;
        return find(parent,parent[i]);
}

    private void union(int[] parent,int x,int y){
        int i = find(parent, x);
        int j = find(parent, y);
        if (i != j)
            parent[i] = j;
    }
}
```
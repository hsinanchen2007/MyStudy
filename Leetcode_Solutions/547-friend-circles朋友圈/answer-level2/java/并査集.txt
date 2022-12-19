### 解题思路
1. 每个人独自位伍(初始化)
2. 根据关系进行合并队伍
3. 如果自己的队伍编码与自己编码一致，代表一个朋友圈。
4. 最开始统计朋友圈的的数量写法 return (int) Arrays.stream(roots).filter(boy -> roots[boy] == boy).count(); 浪费了大半天时间，stream 在这里会有问题。慎用！

### 代码

```java
class Solution {
    private int[] roots;

    public int findCircleNum(int[][] M) {
        roots = new int[M.length];
        for (int i = 0; i < M.length; i++) {
            roots[i] = i;
        }

        for (int i = 0; i < M.length; i++) {
            for (int j = 0; j < M.length; j++) {
                if (M[i][j] == 1) {
                    union(roots[i], roots[j]);
                }
            }
        }
        int result=0;

        for (int i = 0; i < roots.length; i++) {
            if(roots[i]==i){
                result = result + 1;
            }
        }
        return result;
    }

    private int find(int i) {
        int root = i;
        while (root != roots[root]) {
            root = roots[root];
        }
        while (i != roots[root]) {
            int tmp = roots[i];
            roots[i] = root;
            i = tmp;
        }
        return root;
    }

    private void union(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        roots[pRoot] = qRoot;

    }
}
```
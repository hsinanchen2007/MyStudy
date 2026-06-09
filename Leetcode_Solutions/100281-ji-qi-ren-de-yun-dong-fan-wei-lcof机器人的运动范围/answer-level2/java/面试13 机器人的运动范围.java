### 解题思路
此处撰写解题思路
修改递归为return 1 + core(i + 1, j, m, n, k) + dfs(i, j + 1, m, n, k);
因为是左上角，只用遍历右边和下边就可以了
### 代码

```java
class Solution {
    //DFS递归实现，需要记录访问过的节点，但并不是回溯，只需改变现场，不需要恢复
    public int movingCount(int m, int n, int k) {
        //访问过的节点的标记矩阵
        boolean[][] flag = new boolean[m][n];        
        return core(flag, m, n, k, 0, 0);
    }

    private int core(boolean[][] flag, int m, int n,int k, int i, int j){
        //ij下标不符规则||ij已访问过||不满足数位之和小于k
        if(i<0||j<0||i>=m||j>=n||flag[i][j]==true||digitSum(i,j)>k)
            return 0;
        //改变现场
        flag[i][j] = true;
        //上下左右
        return core(flag, m, n, k, i+1, j)+
        core(flag, m, n, k, i-1, j)+
        core(flag, m, n, k, i, j+1)+
        core(flag, m, n, k, i, j-1)+1;
    }
    
    private int digitSum(int i, int j){
        int res = 0;
        while(i!=0){
            res += i%10;
            i /= 10;
        }
        while(j!=0){
            res += j%10;
            j /= 10;
        }
        return res;
    }
}

```
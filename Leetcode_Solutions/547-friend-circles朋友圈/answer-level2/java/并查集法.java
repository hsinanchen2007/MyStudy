### 解题思路
1. 构建并查集,给parent的每个位置赋初值为该位置索引
2. 进行两层遍历,如果M[i][j]为1,说明i位置和j位置需要进行union操作,如果i和j位置对应根节点相同,则counts--;
3. 最后答案是返回counts

### 代码

```java
/**
 * 复习
 * 并查集
 */
public class Solution {

    // 构建并查集
    private int[] parent;
    private int[] rank;
    private int counts;

    public int findCircleNum(int[][] M) {
        int len = M.length;
        if(len == 0){
            return 0;
        }

        parent = new int[len];
        rank = new int[len];
        // 对M进行遍历
        parent[0] = 0;
        rank[0] = 1;
        counts ++;
        for(int i=1; i<len; i++){
            counts ++;
            parent[i] = i;
            rank[i] = 1;
            // 看看i位置能否跟[0, i-1]这些位置进行union
            for(int j=0; j<i; j++){
                if(M[i][j] == 1){
                    union(i, j);
                }
            }
        }

        return counts;
    }

    // 找到节点对应的根节点
    private int find(int i){
        while(i != parent[i]){
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

    // 进行union操作
    private void union(int i, int j){
        int i_root = find(i);
        int j_root = find(j);

        if(i_root == j_root){
            return;
        }

        if(rank[i_root] == rank[j_root]){
            parent[i_root] = j_root;
            rank[j_root] += 1;
        }
        else if(rank[i_root] > rank[j_root]){
            parent[j_root] = i_root;
        }
        else {
            parent[i_root] = j_root;
        }

        counts --;
    }
}

```
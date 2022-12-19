![image.png](https://pic.leetcode-cn.com/6992a4bf6a9c3f2469e5aa80fd67288544eec47f62b792f4f790850909dae325-image.png)

```
class Solution {
    public int findCircleNum(int[][] M) {
        int i, j, k, next;
        Queue<Integer> queue;
        boolean[] visited;

        if(M.length < 2)
            return M.length;
        queue = new LinkedList<>();
        visited = new boolean[M.length];
        k = 0;
        for(i = 0; i < M.length; i++){
            //从一个为未访问的学生开始
            if(!visited[i]){
                visited[i] = true;
                //BFS搜索所有连接的朋友
                queue.add(i);
                while(!queue.isEmpty()){
                    next = queue.remove();
                    for(j = 0; j < M.length; j++){
                        if(M[next][j] == 1 && !visited[j]){
                            visited[j] = true;;
                            queue.add(j);
                        }
                    }
                }
                //搜索完之后朋友圈数加一
                k++;
            }
        }
        return k;
    }
}
```

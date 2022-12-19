**方法一：深度优先搜索（DFS)**

跳出递归的条件：
- index < 0 || index >=arr.length&nbsp;&nbsp;&nbsp;**return false**
- index 已经是访问过的下标&nbsp;&nbsp;&nbsp;**return false**
- arr[index] == 0&nbsp;&nbsp;&nbsp;**return true**

借助visited布尔数组来存储已经访问过的下标

***执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :48.9 MB, 在所有 Java 提交中击败了100.00%的用户***
  
```
class Solution {
    public boolean canReach(int[] arr, int start) {
        boolean[] visited = new boolean[arr.length];
        return dfs(arr,start,visited);
    }

    public boolean dfs(int[] arr, int index, boolean[] visited){
        if(index<0||index>=arr.length) return false;
        if(visited[index] == true) return false;
        if(arr[index] == 0) return true;
        else{
            visited[index] = true;
            return dfs(arr,index-arr[index],visited) || dfs(arr,index+arr[index],visited);
        }
    }
}
```
---
**方法二：广度优先搜索（BFS)**

思路非常简单，套用bfs模板即可，当下标不越界并且未被访问过就存入队列中

***执行用时 :1 ms, 在所有 Java 提交中击败了56.28%的用户
内存消耗 :48.3 MB, 在所有 Java 提交中击败了100.00%的用户***

```
class Solution {
    public boolean canReach(int[] arr, int start) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[arr.length];

        queue.add(start);
        while (!queue.isEmpty()){
            int size = queue.size();
            for(int i=0; i<size; i++){
                int index = queue.poll();
                if(arr[index] == 0){return true;}
                if(index-arr[index] >= 0 && visited[index-arr[index]] == false){
                    queue.offer(index-arr[index]);
                    visited[index-arr[index]] = true;
                }
                if(index+arr[index] < arr.length && visited[index+arr[index]] == false){
                    queue.offer(index+arr[index]);
                    visited[index+arr[index]] = true;
                }
            }
        }
        return false;
    }
}
```


### 解题思路
从起始状态start开始广度优先搜索，并标记已经访问过的状态，避免重复访问。

### 代码

```java
class Solution {
    public boolean canReach(int[] arr, int start) {
        LinkedList<Integer> queue = new LinkedList<>();
        int n = arr.length;
        queue.add(start);
        boolean[] visited = new boolean[n];
        visited[start] = true;
        int size = 0;
        while(!queue.isEmpty()){
            size = queue.size();
            for(int i = 0;i < size;i++){
                int index = queue.pollFirst();
                if(arr[index] == 0) return true;
                //状态转移
                int index2 = index + arr[index];
                int index3 = index - arr[index];
                //把符合要求的入队列
                if(index2 >= 0 && index2 < n && !visited[index2]){
                     queue.add(index2);
                     visited[index2] = true;
                }
                if(index3 >= 0 && index3 < n && !visited[index3]){
                     queue.add(index3);
                     visited[index3] = true;
                }
                
            }
        }
        return false;
    }
}
```
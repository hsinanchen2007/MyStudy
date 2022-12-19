首先，这是一个典型的宽度优先搜索（BFS）问题，只需要从 start 处遍历，每次遍历只添加两个点（当然，这两个点需要在数组内），然后，如果能遍历到值为0的点则能跳到；否则，会陷入一个循环，这里引入 visited 来记录已经遍历的点，防止程序跳入循环中。

```
class Solution {
    public boolean canReach(int[] arr, int start) {
        LinkedList<Integer> queue = new LinkedList<>();
        queue.add(start);
        
        ArrayList<Integer> visited = new ArrayList<>();
        
        boolean flag = false;
        while(!queue.isEmpty()){
            int count = queue.size();
            while(count-- > 0){
                Integer now = queue.poll();
                if(arr[now] == 0){
                    flag = true;
                    break;
                }
                Integer after = now + arr[now];
                if((after < arr.length) & (!visited.contains(after))){
                    queue.add(now + arr[now]);
                }
                after = now - arr[now];
                if((after >= 0) & (!visited.contains(after))){
                    queue.add(now - arr[now]);
                }
                visited.add(now);
            }
        }
        return flag;
    }
}
```

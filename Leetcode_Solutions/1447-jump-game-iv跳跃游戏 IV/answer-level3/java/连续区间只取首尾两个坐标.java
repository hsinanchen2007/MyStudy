### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minJumps(int[] arr) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        int[] visited = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            if (map.containsKey(arr[i])){
                List<Integer> list = map.get(arr[i]);
                if ((list.get(list.size()-1)) == i-1){
                    list.remove(list.size()-1);
                }
                list.add(i);
            }
            else {
                List<Integer> list = new ArrayList<>();
                list.add(i);
                map.put(arr[i],list);
            }
        }
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        visited[0] = 1;
        int level = 0;
        while (!queue.isEmpty()){
            int len = queue.size();
            while (len-- != 0){
                Integer temp = queue.poll();
                if (temp == arr.length - 1)
                    return level;
                if (temp-1 >= 0 && visited[temp-1] == 0){
                    queue.offer(temp-1);
                    visited[temp-1] = 1;
                }
                if (temp +1 < arr.length && visited[temp+1] == 0){
                    queue.offer(temp+1);
                    visited[temp+1] = 1;
                }
                List<Integer> orDefault = map.getOrDefault(arr[temp], new ArrayList<>());
                for (Integer integer : orDefault) {
                    if (visited[integer] == 0){
                        queue.offer(integer);
                        visited[integer] = 1;
                    }
                }
            }
            ++level;
        }
        return arr.length-1;
    }
}
```
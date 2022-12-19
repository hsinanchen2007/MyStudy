```
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        
        // 用来存入度为0的课
        Queue<Integer> queue = new LinkedList<>();
        
        // 用来存当前课的入度值
        Map<Integer, Integer> indegree = new HashMap<>();
        
        // 暂存返回结果
        List<Integer> list = new ArrayList<>();
        
        // 初始化,计算出每个课的入度，大于0的都放进Map
        for(int[] arr : prerequisites)
        {
            if(indegree.containsKey(arr[0]))
                indegree.put(arr[0], indegree.get(arr[0]) + 1);
            else
                indegree.put(arr[0], 1);
        }
        // map中没有的都是入度为0的，全部入队
        for(int i = 0; i < numCourses; i++)
        {
            if(!indegree.containsKey(i))
                queue.add(i);
        }
        
        // 从队列中出队，出队一个加入List，并且维护map相对应的后续课程的入度值
        while(!queue.isEmpty())
        {
            int course = queue.poll();
            list.add(course);
            
            for(int[] arr : prerequisites)
            {
                if(arr[1] == course)
                {
                    int newIndegree = indegree.get(arr[0]) - 1;
                    if(newIndegree == 0)
                        queue.add(arr[0]);
                    else
                        indegree.put(arr[0], newIndegree);
                }
            }
        }
        
        int[] res = new int[list.size()];
        
        for(int i = 0; i < list.size(); i++)
            res[i] = list.get(i);
        
        // 数组长度如果不等于课程数，说明存在环，输出空数组
        return res.length == numCourses ? res : new int[0];
        
    }
}
```

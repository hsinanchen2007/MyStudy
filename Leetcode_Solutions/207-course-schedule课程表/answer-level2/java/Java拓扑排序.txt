```
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        
        // 定义一个数组来存储课程的入度
        int[] indegree = new int[numCourses];
        
        // 定义一个队列用来排序
        Queue<Integer> queue = new LinkedList<>();
        
        // 初始化所有课程的入度
        for (int[] arr : prerequisites)
            indegree[arr[0]]++;
        
        // 将所有入度为0的课程入队, 然后将入度标记为-1，防止后面重复入队
        for (int i = 0; i < indegree.length; i++)
            if (indegree[i] == 0)
            {
                queue.add(i);
                indegree[i] --;
            }
        
        // 开始出队，每出队一门课，就维护入度数组，然后将所有入度为0的数组入队，然后将入度标记为-1，防止后面重复入队
        while (!queue.isEmpty())
        {
            int course = queue.poll();
            
            for (int[] arr : prerequisites)
                if (arr[1] == course)
                    indegree[arr[0]]--;
            
            for(int i = 0; i < indegree.length; i++)
                if (indegree[i] == 0)
                {
                    queue.add(i);
                    indegree[i] = -1;
                }
            
        }
        
        // 遍历indegree中入度为-1的数量，也就是已经完成的课程数，和numCourses一样就返回true,否则返回false
        int res = 0;
        for(int i = 0; i < indegree.length; i++)
            if (indegree[i] == -1)
                res++;
        
        return res == numCourses ? true : false;
        
    }
}
```

### 解题思路


### 代码

```java
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {//拓扑排序
        if(prerequisites.length==0)
        return true;
        int[] ru = new int[numCourses];//入度数组
        boolean[] visited =new boolean[numCourses];
         Queue<Integer> q = new LinkedList<>();//存入度为0的队列
        for(int i=0;i<prerequisites.length;i++)
        {
            ru[prerequisites[i][1]]++;//初始化入度数组
        }
        addzero(q,ru,visited);//加入入度为空的点
        while(!q.isEmpty())
        {
            int temp = q.poll();
            visited[temp]=true;
            delete(q,ru,temp,prerequisites,visited);//删除该点所有的边，它指向的点入度减一，如果减为零则加入队列
        }
        for(int k : ru)
        if(k!=0)
        return false;
        return true;
    
    }
    public void addzero(Queue<Integer> q,int[] ru,boolean[] visited)
     {
       for(int j=0 ;j<ru.length; j++)
        {
            if(ru[j]==0&&!visited[j])
             q.offer(j);
        }
     }
    public void delete(Queue<Integer> q, int[] ru,int temp,int[][] prerequisites,boolean[] visited)
    {
        for(int i=0;i<prerequisites.length;i++)
        {
            if(prerequisites[i][0]==temp)
            {
                ru[prerequisites[i][1]]--;
                if(ru[prerequisites[i][1]]==0&&!visited[prerequisites[i][1]])
                 q.offer(prerequisites[i][1]);
            }
        }
    }
}
```
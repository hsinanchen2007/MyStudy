```
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if(numCourses <= 0){
            return false;
        }
        int len = prerequisites.length;
        if(len == 0){
            return true;
        }
        
//      生成入度表
        int[] inDegrees = new int[numCourses];
        for(int[] p : prerequisites){
            inDegrees[p[0]]++;
        }
//      使用队列来辅助拓扑排序
        LinkedList<Integer> queue = new LinkedList<Integer>();
        for(int i=0;i<inDegrees.length;i++){
            if(inDegrees[i] == 0){
//              将入度为0的节点入队
                queue.addLast(i);
            }
        }
//      用于存放拓扑排序的结果
        ArrayList<Integer> ret = new ArrayList<Integer>();
//      拓扑排序
        while(!queue.isEmpty()){
            Integer num = queue.removeFirst();
            ret.add(num);
            for(int[] p : prerequisites){
//              获取当前节点的邻边（出度=1）
                if(p[1] == num){
                    inDegrees[p[0]]--;
                    if(inDegrees[p[0]] == 0){
                        queue.addLast(p[0]);
                    }
                }
            }
        }
        return ret.size() == numCourses;
    }
}
```

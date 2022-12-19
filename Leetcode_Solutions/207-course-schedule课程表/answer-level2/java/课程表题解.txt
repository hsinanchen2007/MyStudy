### 解题思路
基本思路：创建一个表示next邻居的邻接表，用于一个点快速找到所有的邻居，创建一个表示入度大小的map，用于存储每轮过后节点剩余的入度大小
每轮用队列将当前入度为0的点存入，将其在邻接表中删除，并将其中存在出度的节点的邻居入度减一，当入度减为0，入队列，直至队列为空，循环停止，
判断当前的邻接表是否还有点，若还有，则错误，否则正确。

### 代码

```java
class Solution {
    
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // 创建出度邻接表
        Map<Integer, List<Integer>>outMap=new HashMap<>();
        // 创建入度的统计表
        Map<Integer, Integer>inMap=new HashMap<>();
        int[] inZer0=new int[numCourses];
        for(int i=0;i<prerequisites.length;i++){
            List<Integer> neighber=null;
            if(!outMap.containsKey(prerequisites[i][0])){
                neighber=new ArrayList<>();
            } else{
                neighber=outMap.get(prerequisites[i][0]);
            }
            neighber.add(prerequisites[i][1]);
            outMap.put(prerequisites[i][0],neighber);
            if(!inMap.containsKey(prerequisites[i][1])){
                inMap.put(prerequisites[i][1],1);
                inZer0[prerequisites[i][1]]=1;
            } else{
                Integer numIn=inMap.get(prerequisites[i][1]);
                inMap.put(prerequisites[i][1],++numIn);
            }
        }
        boolean result=false;
        // 队列暂时存储每轮入度被减为0的点
        Queue<Integer> queue=new LinkedList<>();
        for(int i=0;i<numCourses;i++){
            if(inZer0[i]==0){
                queue.offer(i);
            }
        }
        while(!queue.isEmpty()){
            Integer poll=queue.poll();
            if(outMap.containsKey(poll)){
                for(int i=0;i<outMap.get(poll).size();i++){
                    int inNum=inMap.get(outMap.get(poll).get(i));
                    inNum--;
                    if(inNum==0){
                        queue.offer(outMap.get(poll).get(i));
                    } else{
                        inMap.put(outMap.get(poll).get(i),inNum);
                    }
                }
                outMap.remove(poll);
            }
            
        }
        if(outMap.size()==0){
            return true;
        } 
        return false;
    }  
}
```
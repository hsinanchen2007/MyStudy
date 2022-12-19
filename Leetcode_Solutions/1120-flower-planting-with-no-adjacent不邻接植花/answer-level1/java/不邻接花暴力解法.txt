### 解题思路
就是先初始化图，然后根据每个点的邻居节点情况设置最小花类型，遍历很消耗时间，所以时间复杂度表现较差

### 代码

```java
import java.util.*;

class Solution {
    public int[] gardenNoAdj(int N, int[][] paths) {
        int[] color=new int[N+1];
        Map<Integer,List<Integer>> map=new HashMap<>();
        // 初始化图
        for(int i=0;i<paths.length;i++){
            if(map.get(paths[i][0])==null){
                List<Integer> neighber=new ArrayList<>();
                neighber.add(paths[i][1]);
                map.put(paths[i][0],neighber);
            } else{
                List<Integer> neighber=map.get(paths[i][0]);
                neighber.add(paths[i][1]);
                map.put(paths[i][0],neighber);
            }
            if(map.get(paths[i][1])==null){
                List<Integer> neighber=new ArrayList<>();
                neighber.add(paths[i][0]);
                map.put(paths[i][1],neighber);
            } else{
                List<Integer> neighber=map.get(paths[i][1]);
                neighber.add(paths[i][0]);
                map.put(paths[i][1],neighber);
            }
        }

        for(int i=1;i<N+1;i++){
            List<Integer> neighber=map.get(i);
            // 已经设置过则不再动
            if(color[i]>0){
                continue;
            }
            // 没有邻居则设置为第一种花
            if(neighber==null){
                color[i]=1;
                continue;
            }
            // 否则，设置为邻居没有的最小点
            int[] color4=new int[5];
            for(int j=0;j<neighber.size();j++){
                int index=color[neighber.get(j)];
                color4[index]=1;
            }
            for(int j=1;j<5;j++){
                if(color4[j]==0){
                    color[i]=j;
                    break;
                }
            }
        }
        int[] newArray=new int[N];
        for(int i=1;i<color.length;i++){
            newArray[i-1]=color[i];
        }
        return newArray;

    }
}
```
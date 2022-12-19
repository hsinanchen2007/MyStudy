### 解题思路
基于贪心的拓扑排序，但是该题只需要做判断，所以可以简化处理。7ms

1.记录入栈的总数，总数够numCourses就不成环。
2.用集合记录指向每个节点的全部节点（不需要每次遍历整个prerequisites）

### 代码

```java
import java.util.HashSet;
import java.util.Stack;

//leecode 207课程表

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {


        int []outdegrees=new int[numCourses];//保存每个节点的出度
        HashSet<Integer> hs[]=new HashSet[numCourses];//保存指向某个节点的全部节点
        Stack<Integer> s=new Stack<>();
        int cnt=0;//节点计数

        for (int i=0;i<hs.length;i++)hs[i]=new HashSet<>();//初始化

        for (int []pre:prerequisites){
            outdegrees[pre[0]]++;
            hs[pre[1]].add(pre[0]);
        }


        for (int i=0;i<outdegrees.length;i++){
            if(outdegrees[i]==0){
                s.add(i);
                cnt++;
            }
        }

       while(!s.empty()){
           int temp=s.pop();
        //将指向该节点的全部节点入度-1
           for (Integer j:hs[temp]){
               outdegrees[j]--;
               if(outdegrees[j]==0){
                   s.add(j);
                   cnt++;
               }
           }
           if(cnt==numCourses)return true;
       }
       return false;
    }
}
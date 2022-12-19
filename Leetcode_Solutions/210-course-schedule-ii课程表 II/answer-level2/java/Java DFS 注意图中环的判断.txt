### 解题思路
算法如同官方题解的DFS法。
对每一个点进行DFS，从底层开始放入stack里面。全部放完后逐个出栈即可
注意：DFS算法下，图中环的判断。环即访问到的这个点是上一个点的前序点，故每一层要用同一套记录数组！

### 代码

```java
/*
 * @lc app=leetcode.cn id=210 lang=java
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
    Map<Integer,List> map = new HashMap();
    Stack<Integer> stack = new Stack();
    boolean hasCir = false;

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        boolean[] isSearched = new boolean[numCourses];
        Arrays.fill(isSearched,false);
        boolean[] isSearchedThis = new boolean[numCourses];

        buildTree(prerequisites);
        for(int i=0; i<numCourses; i++)
        {
            Arrays.fill(isSearchedThis,false);
            DFS(i,isSearched,isSearchedThis);
        }

        if(hasCir)
            return new int[0];
        else
        {
            int[] res = new int[numCourses];
            for(int i=0; i<numCourses; i++)
                res[i] = stack.pop();
            return res;
        }

    }

    public void buildTree(int[][] prerequisites)
    {
        for(int i=0; i<prerequisites.length; i++)
        {
            if(map.containsKey(prerequisites[i][1]))
                map.get(prerequisites[i][1]).add(prerequisites[i][0]);
            else
            {
                List<Integer> temp = new ArrayList();
                temp.add(prerequisites[i][0]);
                map.put(prerequisites[i][1],temp);
            }
        }
    }

    public void DFS(int course, boolean[] isSearched, boolean[] isSearchedThis)
    {   
        if(isSearchedThis[course])
        {
            hasCir = true;
            return ;
        }

        if(isSearched[course])
            return ;

        isSearched[course] = true;
        isSearchedThis[course] = true;

        if(!map.containsKey(course))
            stack.push(course);
        else
        {
            for(int i=0; i<map.get(course).size();i++)
            {
                boolean[] temp = Arrays.copyOf(isSearchedThis,isSearchedThis.length);//每一层用同一套记录数组！
                DFS((int)map.get(course).get(i),isSearched,temp);
            }
                
            stack.push(course);
        }
    }
}
// @lc code=end


```
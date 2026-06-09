### 解题思路
设置一个状态数组 unsafe
初始值为0，1代表不安全，2代表安全
对于某次的dfs，用set记录访问过的点，若后续访问的点命中了set，则返回false
同时注意从set中remove添加的元素，这样退栈到上层后，可保证数据不被干扰。

### 代码

```java
class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer> res = new ArrayList<>();
        int N = graph.length;
        //0初始值 1不安全 2安全
        int[] unsafe = new int[N];
        for(int i = 0;i < N;i++){
            Set<Integer> set = new HashSet<>();
            set.add(i);
            if (unsafe[i] == 2 || dfs(i, graph,unsafe,set))
                res.add(i);
        }
        return res;
    }

    private boolean dfs(int i,int[][] graph,int[] unsafe,Set<Integer> set){
        if (unsafe[i] == 1)
            return false;
        if (unsafe[i] == 2)
            return true;
        int[] targets = graph[i];
        if (targets.length == 0)
            return true;
        for (int k = 0; k < targets.length; k++) {
            //对target[k]进行校验
            if (set.contains(targets[k]))
                return false;
            set.add(targets[k]);
            if(!dfs(targets[k], graph,unsafe,set)){
                unsafe[targets[k]] = 1;
                return false;
            }
            else
                unsafe[targets[k]] = 2;
            set.remove(targets[k]);
        }
        return true;
    }
}
```
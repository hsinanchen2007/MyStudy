### 解法一：深度优先搜索
看到题目后，很容易联想到树、图、并查集，自然而然就会采用dfs深度优先搜索。那是否需要构造图呢？事实上循环`for(Employee t : employees)`的内容就是在构造图，本质上使用了邻接表来构造图。通过将id和各个员工的类关联起来，首先解决了查询各员工重要性的问题，更重要的是完成了邻接表构造图，因为每个员工类里存放了直系下属的编号，相当于邻接顶点的编号，即邻接表存放了各自的邻接顶点。然后便可以开始dfs了。
通过深度优先搜索不断深入下属，直至遍历完所有与给定id相连的下属，遍历的过程中计算重要性之和即可。

代码
```java
class Solution {
    private Map<Integer, Employee> map = new HashMap<Integer, Employee>();
    public int getImportance(List<Employee> employees, int id) {
        for(Employee t : employees)
            map.put(t.id, t);
        return dfs(id);
    }
    private int dfs(int i) {
        Employee current = map.get(i);
        int sum = current.importance;
        for(int sub : current.subordinates)
            sum += dfs(sub);
        return sum;
    }
}
```

### 解法二：广度优先搜索
有了dfs，自然也可以尝试广度优先搜索bfs，利用队列，从指定员工开始入队，只要队列不空，就取出队首顶点，并将它的所有邻接顶点（直系下属）入队，不断循环上述操作直至队列为空。这样也可以遍历完所有与给定员工相连的所有下属，并计算出重要性之和。

代码
```java
class Solution {
    private Map<Integer, Employee> map = new HashMap<Integer, Employee>();
    public int getImportance(List<Employee> employees, int id) {
        for(Employee t : employees)
            map.put(t.id, t);
        return bfs(id);
    }
    private int bfs(int s) {
        Queue<Integer> q = new LinkedList<Integer>();
        int sum = 0;
        q.offer(s);
        while(!q.isEmpty())
        {
            int v = q.remove();
            Employee current = map.get(v);
            sum += current.importance;
            for(int sub : current.subordinates)
                q.offer(sub);
        }
        return sum;
    }
}
```
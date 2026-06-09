**Java DFS(深度优先)**
[我的github](https://github.com/epochong)
- LeetCode的坑,将函数名称写成static不然会出现一些奇奇怪怪的错误
- 下面是深度优先算法
```
class Solution {
    public int sum = 0;
    public Map<Integer,Employee> map = new HashMap <>();
    public void DFS(int id) {
        sum += map.get(id).importance;
        //遍历每个直系下属,每次dfs都会继续向下调用下面的直系下属
        for (int i :
                map.get(id).subordinates) {
            DFS(i);
        }
    }
    public int getImportance(List<Employee> employees, int id) {
        if (employees.isEmpty()) {
            return 0;
        }
        //通过id记录对应的Employee方便查找
        for (Employee e :
                employees) {
            map.put(e.id, e);
        }
        DFS(id);
        return sum;
    }
}
```
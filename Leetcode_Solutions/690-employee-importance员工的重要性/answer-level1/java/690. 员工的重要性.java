/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/8
 *
 * 解题思路: 使用hashmap 存储<id,Employee>映射 之后使用队列 或者 递归深度遍历的方式进行子员工的重要性的收集
 *
 * 注意: 本质上是一个树的遍历
 *
 */
```
public class leetcode690 {

    public int getImportance(List<Employee> employees, int id) {
        Queue<Integer> queue = new ArrayDeque<>();
        HashMap<Integer,Employee> hashMap = new HashMap<>();
        int res = 0;

        for(int i = 0;i < employees.size();i++){
            hashMap.put(employees.get(i).id,employees.get(i));
            if(employees.get(i).id == id){
                res += employees.get(i).importance;
                for(int j = 0;j < employees.get(i).subordinates.size();j++){
                    queue.add(employees.get(i).subordinates.get(j));
                }
            }
        }

        while(!queue.isEmpty()){
            int t = queue.poll();
            res += hashMap.get(t).importance;
            if(!hashMap.get(t).subordinates.isEmpty()){
                for(int j = 0;j <hashMap.get(t).subordinates.size();j++){
                    queue.add(hashMap.get(t).subordinates.get(j));
                }
            }
        }

        return res;
    }

    HashMap<Integer,Employee> hashMap = new HashMap<>();
    int res = 0;
    public int getImportance2(List<Employee> employees, int id) {

        Employee root = null;
        for(int i = 0;i < employees.size();i++){
            hashMap.put(employees.get(i).id,employees.get(i));
            if(employees.get(i).id == id){
                root = employees.get(i);
            }
        }
        dfs(root);

        return res;
    }

    public void dfs(Employee root){
        if(root == null) return;
        res += root.importance;
        for(int i = 0; i < root.subordinates.size();i++){
            dfs(hashMap.get(root.subordinates.get(i)));
        }
    }

    public static void main(String[] args) {

    }
}
```
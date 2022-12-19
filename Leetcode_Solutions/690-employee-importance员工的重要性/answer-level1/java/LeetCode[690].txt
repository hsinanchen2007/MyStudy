```
class Solution {
    private Integer bfs(Map<Integer, Employee> employees, int id) {
        Integer sum = 0;
        if (!employees.containsKey(id)) {
            System.out.println("asdfasdfasdfasdf");
            return 0;
        }
        sum += employees.get(id).importance;
        List<Integer> subordinates = employees.get(id).subordinates;
        for (Integer subordinate : subordinates) {
            sum += bfs(employees, subordinate);
        }
        return sum;
    }

    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> mymap = new HashMap<>();
        employees.forEach(x -> {
            mymap.put(x.id, x);
        });
        return bfs(mymap, id);
    }
}

```

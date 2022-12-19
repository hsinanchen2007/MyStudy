
```java
public class Solution {
    private List<List<Integer>> list=new ArrayList<>();
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        if (grid.length==0){
            return list;
        }
        int n=grid.length;
        int m=grid[0].length;
        for (int[] ints : grid) {
            List<Integer> tempList = new ArrayList<>();
            for (int anInt : ints) {
                tempList.add(anInt);
            }
            list.add(tempList);
        }
        for (int i=0;i<k;i++){
            shiftOneTime(grid,m,n);
        }
        return list;
    }
    private void shiftOneTime(int[][] grid,int m,int n){
        for (int i=0;i<list.size();i++){
            if (i==0){
                list.get(i).add(0,list.get(n-1).get(m-1));
                continue;
            }
            list.get(i).add(0,list.get(i-1).get(m));
        }
        for (List<Integer> integers : list) {
            integers.remove(m);
        }
    }
}
```

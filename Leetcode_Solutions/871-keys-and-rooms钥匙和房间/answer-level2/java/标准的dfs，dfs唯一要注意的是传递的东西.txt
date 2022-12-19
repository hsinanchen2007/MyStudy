### 解题思路
标准的dfs，dfs唯一要注意的是传递的东西。

### 代码

```java
class Solution {
public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int size = rooms.size();
        ArrayList<Integer> list = new ArrayList<>();
        list.add(0);
        return myDfs(list,rooms,0,size);
    }


    private boolean myDfs(ArrayList<Integer> list, List<List<Integer>> rooms, int index, int size) {
        if (list.size()==size) return true;
        List<Integer> ll=rooms.get(index);
        // ll.forEach(nn-> System.out.println("n1 = " + nn));
//        list.forEach(nn-> System.out.println("n2 = " + nn));
        for (int i = 0; i < ll.size(); i++) {
            int n=ll.get(i);
//            System.out.println("n = " + n);
            if (!list.contains(n)){
                list.add(n);
                boolean f= myDfs(list,rooms,n,size);
                if(f) return true;
            }
        }
        return false;
    }
}
```
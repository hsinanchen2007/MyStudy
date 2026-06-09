### 解题思路
刚学了bfs,写一下自己踩的坑
1. 获取queue.size()，不要再循环中获取
2. 结束条件是s ==0

### 代码

```java
class Solution {
    public int numSquares(int n) {
         ArrayList<Integer> mlist = new ArrayList<>();
       Queue<Integer> queue = new LinkedList<>();
       Set<Integer> set = new HashSet<>();
       int step = 0;
       int m = (int) (Math.sqrt(n) + 1);
       for (int i = 1; i < m; i++) {
           mlist.add(i*i);
       }
    
       queue.add(n);
       set.add(n);
       while (!queue.isEmpty()){
           int len = queue.size();
           step++;
           for (int i = 0; i <len; i++) {
               int next = queue.remove();
               for (Integer ml:mlist) {
                   int s = next - ml;
                   if(s == 0) return step;
                   if(s <0) break;


                   if (set.add(s)) queue.add(s);
               }
           }

       }
       return -1;


    }
}
```
### 解题思路
如果都没有人坐就是2*n；
一行一行的看，把所有的位置存在 Map<Integer, List<Integer>> map中，
遍历map，就是遍历每一行的列位置。
列如果是2——5 则减一
列如果的6——9 减一
如果前两个都减一了，则要判断是否4——7位置被占用没有
### 代码

```java
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
 int[][] copySeates=reservedSeats;
        int sum=2*n;
       Map<Integer, List<Integer>> map=new HashMap<>();
        for (int i = 0; i < copySeates.length; i++) {
            List<Integer> myList =map.get(copySeates[i][0]);
            if (myList==null)
            {
                myList=new ArrayList<>();
                map.put(copySeates[i][0],myList);
            }
            myList.add(copySeates[i][1]);
        }
//        map.computeIfAbsent(copySeates[i][0], k -> new ArrayList<>()).add(copySeates[i][1]);
        for (Map.Entry<Integer, List<Integer>> map1:map.entrySet())
        {
            List<Integer> cols = map1.getValue();
            int valid=2;
            for (int i = 2; i <=5 ; i++) {
                if (cols.contains(i))
                {
                    valid--;
                    break;
                }
            }

            for (int i = 6; i <=9 ; i++) {
                if (cols.contains(i))
                {
                    valid--;
                    break;
                }
            }
            if (valid == 0){
                valid = 1;
                for (int i = 4; i <= 7; i++) {
                    if (cols.contains(i)) {
                        valid--;
                        break;
                    }
                }
            }
            sum-=2-valid;
        }
        return sum;
    }
}
```
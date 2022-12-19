```
代码块
public int countNegatives(int[][] grid) {
        //遍历，没其他思路。
        int count = 0;
        for(int[] gridR : grid){
            for(int gridCell : gridR){
                if(gridCell < 0){
                    count ++;
                }
            }
        }
        return count;
    }
```


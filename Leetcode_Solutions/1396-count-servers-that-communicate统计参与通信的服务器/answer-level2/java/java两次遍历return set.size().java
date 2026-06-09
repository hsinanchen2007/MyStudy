```java
    public int countServers(int[][] grid) {
        if (grid==null)return 0;

        Set<String> set=new HashSet<>();

        for (int rowIndex = 0; rowIndex < grid.length; rowIndex++) {
            int[] row = grid[rowIndex];

            String first=null;
            int count=0;
            for (int columnIndex = 0; columnIndex < row.length; columnIndex++) {
                if (row[columnIndex]==1){
                    if (count==0){
                        first=rowIndex+","+columnIndex;
                        count=1;
                    }else{
                        set.add(rowIndex+","+columnIndex);
                        count++;
                    }
                }
            }
            if (count>1) set.add(first);
        }

        for (int columnIndex=0;columnIndex<grid[0].length;columnIndex++){


            String first=null;
            int count=0;

            for (int rowIndex=0;rowIndex<grid.length;rowIndex++){
                if (grid[rowIndex][columnIndex]==1){
                    if (count==0){
                        first=rowIndex+","+columnIndex;
                        count++;
                    }else{
                        set.add(rowIndex+","+columnIndex);
                        count++;
                    }
                }
            }
            if (count>1)set.add(first);
        }

        return set.size();
    }
```

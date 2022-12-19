```
public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list=new ArrayList<List<Integer>>();
        for(int i=0;i<numRows;i++){
            List<Integer> subList=new ArrayList<Integer>();
            if(i<2) {//前两行
                for (int j = 0; j <= i; j++) {
                    subList.add(1);
                }
                list.add(subList);
            }else{
                subList.add(1);
                for(int j=1;j<i;j++){
                    Integer twoSum=list.get(i-1).get(j-1)+list.get(i-1).get(j);
                    subList.add(twoSum);
                }
                subList.add(1);
                list.add(subList);
            }
        }
        return list;
    }
```

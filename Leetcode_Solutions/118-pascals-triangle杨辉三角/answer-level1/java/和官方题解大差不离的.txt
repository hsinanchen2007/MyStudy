```
   public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> lists = new ArrayList<>();

        if (numRows <= 0)
            return lists;

        for (int i=0; i<numRows;i++){
            List<Integer> list = new ArrayList<>();

            if (i == 0){
                list.add(1);
                lists.add(list);
            }
            else {
                list.add(1);
                for (int j=0;j<=lists.get(i-1).size()-2;j++){
                    list.add(lists.get(i-1).get(j) + lists.get(i-1).get(j+1));
                }
                list.add(1);
                lists.add(list);
            }
        }

        return lists;
    }
```

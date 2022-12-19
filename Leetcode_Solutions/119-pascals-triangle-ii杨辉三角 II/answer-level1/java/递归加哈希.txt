Map<Integer,List<Integer>> map = new HashMap<>();
    public List<Integer> getRow(int rowIndex){
        List <Integer> dp = new ArrayList<>();
        if (rowIndex ==0 ){
             dp.add(1);
             return dp;
        }
        if (map.containsKey(rowIndex)){
            return map.get(rowIndex);
        }
        dp.add(1);
        for (int i = 1 ;i <= rowIndex-1;i++) {
            dp.add(getRow(rowIndex-1).get(i-1)+getRow(rowIndex-1).get(i));
        }
        dp.add(1);
        map.put(rowIndex,dp);
        return dp;
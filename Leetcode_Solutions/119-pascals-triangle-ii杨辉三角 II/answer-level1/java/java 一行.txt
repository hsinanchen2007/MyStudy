    public List<Integer> getRow(int rowIndex) {
        rowIndex++;
        if(rowIndex == 0) return new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        list.add(1);
        if(rowIndex == 1) return list;
        for(int i = 1;i < rowIndex;++i){
            list.add(1);
            for(int j = i - 1;j >= 0;--j){
                list.set(j, list.get(j) + (j-1>=0? list.get(j-1) : 0));
            }
        }
        return list;
    }
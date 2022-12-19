public boolean checkIfExist(int[] arr) {
        if(arr == null || arr.length <= 1)
            return false;
        
        Map<Integer, Integer> map = new HashMap<Integer, Integer>(arr.length << 1);
        for(int x : arr){
            if(map.containsKey(x)){
                return true;
            }else{
                map.put(x<<1, x);
                if(x%2 == 0){
                    map.put(x>>1, x);
                }
            }
        }
        
        return false;
    }
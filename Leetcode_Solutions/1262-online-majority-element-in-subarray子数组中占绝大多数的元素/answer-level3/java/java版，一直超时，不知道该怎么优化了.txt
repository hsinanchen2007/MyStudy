class MajorityChecker {

    private int[] array;
    public MajorityChecker(int[] arr) {
        this.array = Arrays.copyOfRange(arr,0,arr.length+1);
    }
    
    public int query(int left, int right, int threshold) {
        Map<Integer, Integer> map = new HashMap<>();
        int count  = 0;
        int key = 0;

        for (int i = left;i<=right;i++){
            int val = array[i];
            if (!map.containsKey(val)){
                map.put(val, 1);
            }else {
                map.put(val, map.get(val)+1);
            }
            if (map.get(val)>count){
                count = map.get(val);
                key = val;
            }
        }

        if (count>=threshold){
            return key;
        }

        return -1;
    }
}

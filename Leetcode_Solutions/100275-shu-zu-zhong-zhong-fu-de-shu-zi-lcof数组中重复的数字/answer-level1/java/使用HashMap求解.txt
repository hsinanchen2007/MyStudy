 public static int findRepeatNumber(int[] nums) {

        Map map = new HashMap();
        for (int num : nums) {
           if(map.get(num)!=null){
               map.put(num,(int)map.get(num)+1);
           }else {
               map.put(num,1);
           }
        }
        for (Object num: map.keySet()) {
           if((int)map.get(num)>1){
                return (int)num;
            }
        }
        return 0;
    }
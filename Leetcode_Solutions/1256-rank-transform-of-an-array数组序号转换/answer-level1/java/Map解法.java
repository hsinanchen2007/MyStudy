class Solution {
    public int[] arrayRankTransform(int[] arr) {
        if (arr == null || arr.length < 1) {
            return arr;
        }
        
        int[] outPut = new int[arr.length];
        int[] originInfo = arr.clone();
        Arrays.sort(arr);
        int position =1;
        Map<Integer, Integer> numMaps = new HashMap<Integer, Integer>(arr.length);
        for(int item:arr){
            if(!numMaps.containsKey(item)){
                numMaps.put(item, position);
                position++;
            }
        }
        int outPositon = 0;
        for(int item:originInfo){
            outPut[outPositon++] = numMaps.get(item);
        }
        return outPut;
    }
}
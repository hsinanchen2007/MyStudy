class Solution {
    public int findLucky(int[] arr) {
        Arrays.sort(arr);
        int last = arr.length - 1;
        int luckNum = arr[last];
        int same = 1;
        for(int i = last-1 ; i >= 0 ; i--){
            if(arr[i] == luckNum){
                same++;
            }else{
                if(same == luckNum){
                    return same;
                }else{
                    same = 1;
                    luckNum = arr[i];
                }
            }
        }
        if(same == luckNum){
            return same;
        }
        return -1;

    }
}
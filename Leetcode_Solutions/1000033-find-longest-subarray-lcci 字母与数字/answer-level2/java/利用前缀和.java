class Solution {
    public String[] findLongestSubarray(String[] array) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int l = -1;
        int len = 0;
        int sum = 0;
        map.put(0, -1);
        for(int i = 0; i < array.length; ++i){
            char c = ' ';
            for(char ch:array[i].toCharArray())
                c = ch;
            if(c >= '0' && c <= '9'){
                sum--;
            }else{
                sum++;
            }
            if(!map.containsKey(sum)){
                map.put(sum, i);
            }else{
                if(i - map.get(sum) > len){
                    l = map.get(sum);
                    len = i - l;
                }
            }
        }
        String[] res = new String[len];
        for(int i = 1; i <= len; ++i){
            res[i-1] = array[i+l];
        }
        return res;
    }
}
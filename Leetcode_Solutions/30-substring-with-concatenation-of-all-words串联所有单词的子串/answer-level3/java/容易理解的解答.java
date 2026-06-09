class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        
        List<Integer> list = new ArrayList<Integer>();
        if(words.length == 0 || s.isEmpty() ){
            return list;
        }
        int word_len = words[0].length();
        int length =  word_len * words.length;
        int left = 0 ;
        int right = length;
        while(right <= s.length()){
            String str = s.substring(left,right);
            for(int i = 0 ; i < words.length; i ++){
                int temp = str.indexOf(words[i]);
                 while(temp % word_len != 0){
                    if(temp < 0){
                        break;
                    }
                    temp = str.indexOf(words[i],temp + 1);
                }
                if(temp < 0) {
                    left++;
                    right++;
                    break;
                }
                if(temp == 0 ){
                    str = str.substring(word_len);
                }else{
                    str = str.substring(0,temp) + str.substring(temp + word_len);
                }
            }
            if(str.isEmpty()){
                list.add(left);
                left++;
                right++;
            }
        }
        return list;
    }     
}
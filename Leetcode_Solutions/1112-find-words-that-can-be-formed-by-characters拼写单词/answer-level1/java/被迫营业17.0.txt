class Solution {
        public int countCharacters(String[] words, String chars) {
              int ans =0;
        char [] ch = chars.toCharArray();
        int [] temp = new int[26];
        for (char c : ch
             ) {
            temp[c-'a']++;
        }
        for (String str : words
             ) {
            char [] ch1 = str.toCharArray();
            int count=0;
            int [] temp2 = temp.clone();
            for (char a: ch1
                 ) {
                if(temp2[a-'a']-->0){
                    count++;
                }
            }
            if(count==str.length()){
                ans+=count;
            }

        }
        return ans;
        }
}
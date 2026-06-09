```
class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
         int[] lic = new int[26];   //记录licensePlate中字母的个数;
        for (char c : licensePlate.toCharArray()) {
            if(c<='z'&&c>='a') {
                lic[c - 'a']++;
            } if(c<='Z'&&c>='A'){
                lic[c-'A']++;
            }
        }
        int len = Integer.MAX_VALUE;
        String ans = "";
        for (String w : words) {  //遍历words;
            int[] temp = new int[26];  //记录words中每个字符串的字母个数;
            for (char c : w.toCharArray()) {
                if(c<='z'&&c>='a') {
                    temp[c - 'a']++;
                } if(c<='Z'&&c>='A'){
                    temp[c-'A']++;
                }
            }
            boolean boo=is(temp,lic);  //如果是完整词
            if(boo==true){
                if(w.length()<len){    //就记录长度和字符串内容,找到最短完整词;
                    len=w.length();
                    ans=w;
                }
            }
        }
            return ans;
    }
    private boolean is(int[] a1, int[] a2) {     //判断words中每个字符串是不是完整词
        for (int i = 0; i < 26; i++) {
            if (a1[i] < a2[i]) {
                return false;
            }
        }
        return true;
    }
}

```

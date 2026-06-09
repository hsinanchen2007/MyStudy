```
class Solution {
    public boolean canPermutePalindrome(String s) {
        int count = 0;
        char[] chars = s.toCharArray();
        int[] dic = new int[128];
        for(int i=0;i<chars.length;i++){
            if((dic[chars[i]]++&1)==1){ // 判断当前元素是否出现偶数个
                dic[chars[i]]=0;
                count--;
            }else{
                count++;
            }
        }
        return count<=1;
    }
}
```

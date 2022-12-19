用二进制的一位表示某一个字母是否出现过，0表示没出现，1表示出现。"abcd"二进制表示00000000 00000000 00000000 00001111、"bc"二进制表示00000000 00000000 00000000 00000110。当两个字符串没有相同的字母时，二进制数与的结果为0。
```
class Solution {
    public int maxProduct(String[] words) {
        int wlength = words.length;
        int[] arr = new int[wlength];
        for(int i = 0; i < wlength; ++i){
            int length = words[i].length();
            for(int j = 0; j < length; ++j){
                arr[i] |= 1 << (words[i].charAt(j) - 'a');
            }
        }
        int ans = 0;
        for(int i = 0; i < wlength; ++i){
            for(int j = i + 1; j < wlength; ++j){
                if((arr[i] & arr[j]) == 0){
                    int k = words[i].length() * words[j].length();
                    ans = ans < k ? k : ans;
                }
            }
        }
        return ans;
    }
}
```

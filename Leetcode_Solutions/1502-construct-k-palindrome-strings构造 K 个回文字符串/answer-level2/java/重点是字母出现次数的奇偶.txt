如果一个字母出现的次数是偶数次，那么它可以参与到一个回文。
如果一个字母出现的次数是奇数次，那么他可以作为一个回文的中心，因此要求出现奇数次的字母最多只能有k个。

那么用一个大小为26的array来记录字母出现的次数。奇数次+1，偶数次-1。
最后再来个forloop统计有多少个字母出现了奇数次。搞定
```java
class Solution {
    public boolean canConstruct(String s, int k) {
        if(s.length() < k) return false;
        if(s.length() == k) return true;
        int[] char_array = new int[26];
        for(int i = 0; i < s.length(); i++){
            int temp = s.charAt(i) - 'a';
            if(char_array[temp] == 0){
                char_array[temp] += 1;
            }else{
                char_array[temp] -= 1;
            }
        }
        for(int i = 0; i < 26; i++){
            if(char_array[i] == 1){
                k--;
            }
        }
        return k >= 0 ? true : false;
    }
}
```

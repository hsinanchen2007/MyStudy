### 解题思路
用桶排序思想，因为包含大小写字母，所以平常的25个大小的数组不合适，A-a=32，所以用25+32=57 我这直接60，肯定够用

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int len = s.length();
        int total = 0;
        int cnt[] = new int[60];
        Set<Character> set = new HashSet<>();
        for(int i = 0; i < len; i++){
            cnt[s.charAt(i)-'A']++;
            set.add(s.charAt(i));
        }
        for(Character c: set){
            int ct = cnt[c-'A'];
            if(ct % 2 == 0){
                total += ct;
            }else{
                if(ct == 1){
                    continue;
                }
                ct = ct - 1;
                total += ct;
            } 
        }
        return total == len ? total : total + 1;
    }
}
```
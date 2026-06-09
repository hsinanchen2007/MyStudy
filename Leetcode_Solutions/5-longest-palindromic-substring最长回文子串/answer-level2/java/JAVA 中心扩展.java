 执行用时 : 11 ms , 在所有 Java 提交中击败了 93.57% 的用户 内存消耗 : 36.2 MB , 在所有 Java 提交中击败了 91.21% 的用户

```
class Solution {
    //center_c 为是否以char（一个字符）为中心，为0表示两个字符间为中心（中心为i+0.5） 为1表示以某一个字符为中心
    private int center_length(String s,int i,int center_c) {
        int count = 0;
        if(center_c == 0) {
            int j = i+1;
            while(i>=0 && j<s.length() && s.charAt(i) == s.charAt(j)  ) {
                count += 2;
                i--;
                j++;
            }
            return count;
        }
        if(center_c == 1) {
            count = 1;
            int k = i+1;
            int j = i-1;
            while(j>=0 && k<s.length() && s.charAt(j) == s.charAt(k)) {
                count += 2;
                j--;
                k++;
            }
            return count;
        }
        return 0;
    }
    public String longestPalindrome(String s) {
        int max = 0;
        int max_index = 0;
        int max_flag = 0;
        int is_change = 0;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i<s.length(); i++) {
            int length_1 = center_length(s,i,0);
            int length_2 = center_length(s,i,1);
            if(length_1==0 && length_2==0) continue;
            if(length_1>length_2) {
                if(length_1>max) {
                    max = length_1;
                    max_index = i;
                    max_flag = 0;
                    is_change = 1;
                }
                else continue;
            }
            if(length_2>length_1) {
                if(length_2>max) {
                    max = length_2;
                    max_index = i;
                    max_flag = 1;
                    is_change = 1;
                }
            }
        }
        if(max_flag == 0 && is_change == 1) {
            //长度为偶数
            int j = max_index-(max)/2 + 1;
            for(int n = 0;n<max; n++) {
                sb.append(s.charAt(j));
                j++;
            }
            is_change = 0;
        }
        if(max_flag == 1 && is_change == 1) {
            //长度为奇数
            int j = max_index-(max-1)/2;
            for(int n = 0; n<max; n++) {
                sb.append(s.charAt(j));
                j++;
            }
            is_change = 0;
        }
        return sb.toString();
    }
}
```

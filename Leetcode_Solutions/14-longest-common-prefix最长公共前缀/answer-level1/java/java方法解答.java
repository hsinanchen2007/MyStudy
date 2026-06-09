方法一 暴力匹配 2ms 只击败了不到39%
```
class Solution {
    StringBuilder sb = new StringBuilder();
    public String longestCommonPrefix(String[] strs) {
        // 特殊case
        if(strs == null || strs.length == 0) return "";
        // 如果只有一个元素，直接返回该元素
        if(strs.length == 1) return strs[0];
        String str1 = strs[0];
        // 取第一个元素假设是公共前缀
        for(int i=0;i<str1.length();i++) {
            sb.append(str1.charAt(i));
        }
        // 对数组中的每个元素挨个求公共前缀
        for(int i=1;i<strs.length;i++) {
            String temp = strs[i];
            // 如果有空的，直接返回空
            if(temp.equals("")) {
                sb.delete(0,sb.length());
                break;
            }
            // 如果比公共前缀端，先进行截取
            if(sb.length() > temp.length()) {
                sb.delete(temp.length(),sb.length());
            }
            int len = sb.length() <= temp.length() ? sb.length() : temp.length();
            int k = 0;
            for(;k<len;k++) {
                if(sb.charAt(k) == temp.charAt(k)) {
                    continue;
                }else {
                    sb.delete(k,sb.length());
                    break;
                }
            }
        }
        return sb.toString();
    }
}
```
方法二 分治思想，每次分成两部分求解公共前缀，1ms，击败了80.46%
```
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs == null || strs.length == 0) return "";
        return divideConquer(strs, 0, strs.length - 1);
    }
    // 分治思想
    public String divideConquer(String[] strs, int start, int end) {
        if(start == end) {
            return strs[start];
        }

        int mid = start + (end - start) / 2;
        String str1 = divideConquer(strs, start, mid);
        String str2 = divideConquer(strs, mid+1, end);
        return commonPrefix(str1, str2);
    }

    public String commonPrefix(String str1, String str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        int len = len1 <= len2 ? len1 : len2;
        int i = 0;
        for(; i < len; i++) {
            if(str1.charAt(i) != str2.charAt(i)) {
                break;
            }
        }
        return str1.substring(0, i);
    }
}
```

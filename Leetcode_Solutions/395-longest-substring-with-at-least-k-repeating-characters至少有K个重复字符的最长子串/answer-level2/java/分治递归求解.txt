执行用时 :0 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :33.9 MB, 在所有 java 提交中击败了95.28%的用户
```
class Solution {
    public int longestSubstring(String s, int k) { 
        if(s.length() < 1 || k < 1 || k > s.length())
            return 0;
        int len = s.length();
        if(k < 2)
            return len;
        return getResult(s.toCharArray(), 0, len-1, k);
    }
    public int getResult(char[] chs, int start, int end, int k){
        if((end - start + 1) < k)
            return 0;
        int[] count = new int[26];
        for(int i = start; i <= end; i++){
            int index = chs[i] - 'a';
            count[index]++;
        }
        while((end - start + 1) >= k && count[chs[start]-'a'] < k){
            start++;
        }
        while((end - start + 1) >= k && count[chs[end]-'a'] < k){
            end--;
        }
        if((end - start + 1) < k)
            return 0;
        int index = -1;
        for(int i = start; i <= end; i++){
            if(count[chs[i] - 'a'] < k){
                index = i;
                break;
            }
        }
        if(index == -1){
            return end - start + 1;
        }
        return Math.max(getResult(chs, start, index-1, k),getResult(chs, index+1, end, k));
    }
}
```


class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) return "";
        String prefix = strs[0];
        
        for(int i = 1; i < strs.length; i++)
            
            while(strs[i].indexOf(prefix) != 0){   //子字符串prefix第一次出现的地方 //！=0去除字符串空的情况
                prefix = prefix.substring(0,prefix.length() - 1);  //一直减掉strs[i]字符串直到与子字符串相等
                if(prefix.isEmpty()) return "";
            }
        return prefix;
        
    }
}
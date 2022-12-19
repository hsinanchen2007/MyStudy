class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs == null || strs.length == 0) return "";
        int num = strs.length;
        boolean ret = false; // 返回标识
        int i;
        
        for(i = 0; i < strs[0].length(); i++)
        {
            char tmp = strs[0].charAt(i); // 取字符
            for(int j = 1; j < num; j++)
            {
                // 字符长度太小已经没法比较了吗？
                if(strs[j].length() <= i)
                {
                    ret = true;
                    break;
                }
                if(tmp == strs[j].charAt(i));
                else
                {
                    ret = true;
                    break;
                }
            }
            if(ret) break;
        }
        return strs[0].substring(0, i);
    }
}
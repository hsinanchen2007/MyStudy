解题思路：变位词只要保证两个字符串的长度一致，并且每个字符出现的次数一致，即互为变位词。题目又保证了字符串中都为小写字母，          那么，我们可以用一个大小为26的数组存这些字符出现的次数，如果两个字符串得到的数组完全一致，那么互为变位词。 
```
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int len = strs.length;
        //标志已经放到结果集中的字符串
        boolean[] vis = new boolean[len];
        
        List<List<String>> ans = new ArrayList<>();
        int[] count = null;
        for (int i = 0; i < len; ++i) {
            //如果已经加到结果集中，跳过
            if (vis[i])
                continue;
            //第i个字符串的长度，如果两个字符串的长度不一致，那么其实不用比较也知道不可能互为变位词。
            int lenI = strs[i].length();
            //将第i个字符串转为数组
            count = count(strs[i]);
            //存放第i个字符串和第i个字符串的变位词
            List<String> list = new ArrayList<>();
            list.add(strs[i]);
            //从当前的下一个索引开始，因为之前的肯定都已经加到结果集中了
            for (int j = i + 1; j < len; ++j) {
                //如果已经加到结果集中， 或者 两个字符串的长度不一致，直接跳过
                if (vis[j] || strs[j].length() != lenI)
                    continue;
                //如果两个字符串互为变位词，那么加到结果集中
                if (isEquals(strs[j], count)) {
                    vis[j] = true;
                    list.add(strs[j]);
                }
            }
            
            ans.add(list);
        }
        
        return ans;
    }
    
    //判断两个字符串是否互为变位词。若两个字符串转成的数组相同，那么一个是另一个的变位词。
    private boolean isEquals(String str, int[] count) {
        return Arrays.equals(count, count(str));
    }
    
    //因为题目保证字符串中只有小写字母，所以我们可以创建一个数组，大小为26->对应26个字母，数组中记录每个字符(字母)出现的次数
    private int[] count(String str) {
        int[] count = new int[26];
        for (char c : str.toCharArray())
            count[c - 'a']++;
        
        return count;
    }
}
```

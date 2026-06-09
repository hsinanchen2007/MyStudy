# 想法
异位词的Key是相同的字母和计数组成，Value是异位词的List，用哈希表解决
# 算法
1. 对每个单词构造字母和字母计数的Key
2. Key相同的单词加入HashMap的value(List)
3. 遍历输入的单词数组，重复2
# 复杂度
- 时间复杂度：O(n*m), n为输入字符串数组长度，m为字符串平均长度
- 空间复杂度：O(n)
# 代码
```
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        Map<String, List<String>> map = new HashMap<>();
        for (String s : strs) {
            String counterStr = buildCounter(s);
            List<String> list = map.get(counterStr);
            if (list == null) {
                list = new ArrayList<>();
                map.put(counterStr, list);
            }
            list.add(s);
        }
        
        for (List<String> v : map.values()) {
            res.add(v);
        }
        
        return res;
        
    }
    
    private String buildCounter(String str) {
        int[] counter = new int[26];
        Arrays.fill(counter, 0);
        for (char ch : str.toCharArray()) {
            counter[ch - 'a'] += 1;
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            sb.append('a' + i).append(counter[i]);
        }
        
        return sb.toString();
    } 
}
```


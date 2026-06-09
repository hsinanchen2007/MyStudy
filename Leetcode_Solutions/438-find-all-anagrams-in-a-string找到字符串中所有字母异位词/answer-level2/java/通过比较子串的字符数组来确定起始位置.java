方法中大量用到了排序和遍历，因此时间复杂度很高，虽然程序比较简单思路清晰但是不推荐在时间复杂度要求高的程序中使用。
```
class Solution {
    // s 从当前字母开始截取 p 长度的子串，并和 p 进行比较
    public List<Integer> findAnagrams(String s, String p) {    
        char[] pArray = p.toCharArray();
        ArrayList<Integer> ret = new ArrayList<>();
        Arrays.sort(pArray);
        // s 取 p 长度的子串的起始位置
        int length = s.length() - pArray.length + 1;
        for (int i = 0; i < length; i++) {
            // 截取 p 长度的子串并转换为字符数组
            char[] subArray = s.substring(i, i + pArray.length).toCharArray();
            // 对子串字符数组排序
            Arrays.sort(subArray);
            // 比较 p 的字符数组和子串的字符数组
            boolean equals = Arrays.equals(pArray, subArray);
            // 相等添加起始位置到结果集中
            if (equals) {
                ret.add(i);
            }
        }
        return ret;
        
    }
}
```

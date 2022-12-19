class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuffer s = new StringBuffer();
<!-- 利用set不能添加重复集合这一特性 -->
        HashSet<Character> set = new HashSet<>();
        int j = 0;
        outer:
        while(true){
<!-- 循环遍历数组得到字符串 -->
            for(String str:strs){
<!-- 如果索引不超过每一个字符串的长度把对应的字符加入set集合 -->
                if(j < str.length()){
                set.add(str.charAt(j));
                }
<!-- 如果超过字符串的长度就跳出while循环 -->
                else{
                    break outer;
            }
        }
<!-- 如果set集合的长度是1就说明了改索引位置的字符是符合要求的 -->
            if(set.size() == 1){
<!-- 符合要求的加入的s结果字符缓冲区 -->
                s.append(strs[0].charAt(j++));
<!-- 清理 set集合，以备下次使用 -->
                set.clear();
            }
<!-- 如果set的集合长度不是1，就说明该索引位置的字母不是一个字母，不符合要求。直接跳出循环 -->
            else{
                break outer;
            }
        } 
        return s.toString();  
    } 
}
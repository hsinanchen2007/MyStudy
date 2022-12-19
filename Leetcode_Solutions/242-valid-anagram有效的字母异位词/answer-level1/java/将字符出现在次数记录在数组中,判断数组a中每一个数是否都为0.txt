class Solution {
    public boolean isAnagram(String s, String t) {
        // 将字符出现在次数记录在数组中
        int[] a=new int[26];
        // 遍历
        for(char sh:s.toCharArray()){
            a[sh - 'a']++;
        }
        for(char th:t.toCharArray()){
            a[th - 'a']--;
        }
        // 判断数组a中每一个数是否都为0
        for(int ah:a){
            if(ah != 0){
                return false;
            }
        }
        return true;
    }
}
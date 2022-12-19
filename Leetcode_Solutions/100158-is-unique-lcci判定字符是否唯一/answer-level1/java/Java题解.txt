class Solution {
    public boolean isUnique(String astr) {
        char[] c = astr.toCharArray();
        // 一遍for循环，判断每个字符下标是否是，字符串中和自己相等最后的下标
        for(int i=0;i<c.length;i++){
            if(i!=astr.lastIndexOf(c[i])){
                return false;
            }
        }
        return true;
    }
}
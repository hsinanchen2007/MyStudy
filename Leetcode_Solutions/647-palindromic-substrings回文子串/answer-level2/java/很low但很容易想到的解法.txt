1，从第一个字符开始遍历，遍历时找到相同的字符，则截取这一段子字符串，通过两两对比判断是否是回文
要注意初始回文数就复制为s.length()
速度很慢，基本上是O(n3)的水平
2，速度快的解法，相对好理解的，是一样从头开始遍历，期间由遍历的字符为中心向两边扩展判断是否为回文
这种解法利用了两两比较减少完全遍历耗时的特性，时间复杂度是O(n2)

class Solution {
    public int countSubstrings(String s) {
        if(s==null) {
            return 0;
        }
        //单个字符就是一个回文,所以肯定有字符长度个回文
        int result = s.length();
        
        for(int i=0;i<s.length();i++) {
            //从当前字符开始寻找可能的子字符串
            for(int j=i+1;j<s.length();j++) {
                //出现与当前字符相同的字符，才有可能是回文
                //System.out.print("i=" + i + " ,j=" + j + '\n');
                if(s.charAt(i)==s.charAt(j) && checkIfPalindromic(s.substring(i,j+1))) {
                    result++;
                }
            }
        }
        
        return result;
    }
    
    //通过前后两两比较，判断是不是回文
    private boolean checkIfPalindromic(String str) {
        for(int i=0;i<str.length()/2;i++) {
            if(str.charAt(i)!=str.charAt(str.length()-i-1)) {
                return false;
            }
        }
        return true;
    }
}
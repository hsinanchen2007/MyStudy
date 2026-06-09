class Solution {
    public int longestPalindrome(String s) {
        int[] count = new int[128];  // 把所有字符存储在一个int数组里面
        char[] chars = s.toCharArray();
        for(int i=0;i<chars.length;i++){
            count[chars[i]]++;
        }
        int res=0;
        for(int i=0;i<127;i++){
            if(count[i]%2==0){  // 当前字符出现个数为偶数时
                res+=count[i];
            }else if(count[i]%2==1 && res%2==0){  // 当前字符出现个数为奇数时，且目前总长度为偶数
                res+=count[i];
            }else{
                res+=count[i]/2*2;  // 当前字符出现个数为奇数时
            }
        }
        return res;
    }
}
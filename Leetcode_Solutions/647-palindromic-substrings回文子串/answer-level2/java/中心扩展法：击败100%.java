执行用时 :1 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :34.3 MB, 在所有 java 提交中击败了92.34%的用户
```
class Solution {
    public int countSubstrings(String s) {
        if(s == null || s.equals(""))
            return 0;
        char[] ch = s.toCharArray();
        int sum = ch.length;
        for(int i = 0; i < ch.length; i++){
            sum += getSum(ch,i,i+1);
            sum += getSum(ch,i-1,i+1);
        }
        return sum;
    }
    public int getSum(char[] ch, int start, int end){
        if(start < 0 || end > ch.length-1)
            return 0;
        int count = 0;
        while(start >= 0 && end < ch.length){
            if(ch[start--] == ch[end++]){
                count++;
            }
            else{
                return count;
            }
        }
        return count;
    }
}
```

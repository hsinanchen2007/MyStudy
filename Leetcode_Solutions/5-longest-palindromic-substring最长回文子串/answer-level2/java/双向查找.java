### 解题思路
依次设定每个字符为中心，往两边去试探是否相同。
要考虑是奇数回文串的情况，和偶数回文的情况。 
start=i-(len-1)/2 
这里之所以要减1，是因为如果是偶数回文的话，不减1找到的起始位置是错误的。如 aa 的 起始位置会被计算从-1。而奇数回文的话，(int)(len-1)/2=(int)(len/2)

### 代码

```java
class Solution {
   public String longestPalindrome(String s) {
        if(s.length()==1||s.length()==0){
            return s;
        }
        char[] chars=s.toCharArray();
        int start=0,end=0;
        int max=-1;
        for (int i=0;i<chars.length;i++) {
            int f=i,l=i;
            int len = cal(chars,i,i);//奇数回文串
            int len2 = cal(chars,i,i+1);//偶数回文串
            len=Math.max(len,len2);
            if(max<len){
                max=len;
                //如果是偶数回文的话，需要减1才能找到正确的位置,
                //奇数回文 是否减1，除2后取整 两者没有差别
                start=i-(len-1)/2;
            }
        }
        return String.valueOf(chars,start,max);
    }
    private int cal(char[] chars,int left,int right){
        while (left>-1 && right<chars.length&&chars[left] == chars[right]) {
            right++;
            left--;
        }
        return right-left-1;
    }
}
```
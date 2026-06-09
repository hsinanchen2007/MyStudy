### 解题思路
思路是将字符串反转后，对比两个字符串的是否一致
如 aacecaaa s 反转后得到 aaacecaa s1
设[0,n)为判断 字符串的0~n
第一次判断 s[0,length-0)是否等于 s1[0+0,length]
第二次判断 s[0,length-1)是否等于 s1[0+1,length]

第N次判断  s[0,length-n-1]是否等于 s1[n-1,length]
因为是两个等长的数组判断，只需要一次循环即可判断出结果
复杂度O(n*n)

### 代码

```java
class Solution {
    public String shortestPalindrome(String s) {
        if(s.length()==1||s.length()==0){
            return s;
        }
        char[] chars=s.toCharArray();
        char[] reverse = new char[chars.length];
        for (int i=0; i<chars.length; i++)
            reverse[chars.length-i-1] = chars[i];
        
        for (int i=0; i<s.length(); i++){
            if(eq(chars,reverse,chars.length-i)){
                return String.valueOf(reverse,0,i)+s;
            }
        }
        return s;
    }

    private boolean eq(char[] chars,char[] otherchars,int length){
        for(int i=0;i<length;i++){
            if(chars[i]!=otherchars[otherchars.length-length+i]){
                return false;
            }
        }
        return true;
    }
}
```
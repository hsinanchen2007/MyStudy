# 思路1 拆东墙补西墙

- 原字符串`S = A1,A2,A3•••Aj,•••An`
- `P = A1•••Aj`是回文
- `Aj+1 ••• An` 逆序添加到S串前, 变成 `S'= An, An-1, ••• Aj+1, Aj, ••• A3, A2, A1`
- 验证S'是否为回文串, 验证是否为回文串, 通过中心扩展法实现(只需验证一个中心), 这个时间复杂度为O(N)

# 思路1 Java Code

```
class Solution {
    
    public String shortestPalindrome(String s) {
        
        int strLen = s.length();
        if(isPalindrome(s, strLen/2, strLen/2) || isPalindrome(s, strLen/2, strLen/2+1)){
            return s;
        }
        
        String palindrome = "";
        int cutLen = 1;
        while(cutLen <= strLen){
            StringBuilder sb = new StringBuilder();
            for(int cur = strLen -1; cur >= strLen - cutLen; cur--){
                sb.append(s.charAt(cur));
            }
            sb.append(s);
            
            int tmpLen = sb.length()-1;
            int start = tmpLen/2;
            int end = tmpLen%2 == 0 ? tmpLen/2 : tmpLen/2+1;
            
            if(isPalindrome(sb.toString(), start, end)){
                palindrome = sb.toString();
                break;
            }
            cutLen++;
        }
        
        return palindrome;
    }
    
    public boolean isPalindrome(String s, int start, int end){
        while(start >= 0 && end < s.length() && s.charAt(start) == s.charAt(end)){
            start -= 1;
            end += 1;
        }
        return (end - start - 1) >= s.length();
    }
    
}
```
# 思路1 的问题

当原字符串S很长时, 1.从尾部依次取字符, 2.拼接到S之前, 3.验证, 对于每一个字符的拼接都需要验证, 效率十分低. 测试用例非常长时, 超时. 

# 思路2 最长回文前缀

- 依次验证以`A1`开始, 以`Ai(i = 1,2,3,4•••n-1)`结束的子串`P`是否为回文串(注意, 回文的第一个字符是固定的)
- 如是, 试图更新回文串长度`maxLen`
- 若回文串为整个字符串`S`, 则直接返回
- 若回文串为`S`的子串, 截取`P`之后的`T = Ai+1 ••• An`. 反转子串T, T'.
- `T'+S`即为最短回文串

# 思路2 Java Code

``` java
class Solution {
    
    public String shortestPalindrome(String s) {
        int len = s.length();
        // 回文子串长度
        int maxLen = 0;
        
        for(int i = len-1; i >= 0; i--){
            // 回文串总是从第0个字符开始依次验证
            boolean ispal = isPalindrome(s, len, 0, i);
            // 只有找到回文串并且最新回文串比maxLen还长时, 更新maxLen. 表示找到了新的更长回文串
            if(ispal && (i+1) > maxLen){
                maxLen = i+1;
            }
        }
        // 如果回文子串即S串本身, 返回S
        if(maxLen >= len) return s;
        
        // 截取回文串之后的子串T, 反转T为T', T'+ S即为最短回文串
        StringBuilder sb = new StringBuilder();
        sb.append(new StringBuilder(s.substring(maxLen,len)).reverse()).append(s);
        
        return sb.toString();
    }
    
    public boolean isPalindrome(String s, int s_len, int start, int end){
        while(start < s_len && end >= 0 && s.charAt(start) == s.charAt(end)){
            start += 1;
            end -= 1;
        }
        return start >= end;
    }
    
}
```
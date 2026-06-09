### 解题思路
挨个处理非定义字符并添加到StringBuilder
注意StringBuilder对象的reverse方法是in-place的

注意最后的结果转换为String再比较，不要用StringBuilder比较
时间复杂度O(n)，用时8ms

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        if (s == null || s.equals("")){
            return true;
        }else{
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < s.length(); i++){
                if((s.charAt(i) >= 'a' && s.charAt(i) <= 'z')
                ||(s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')
                ||(s.charAt(i) >= '0' && s.charAt(i) <= '9')){
                    stringBuilder.append(String.valueOf(s.charAt(i)).toLowerCase());
                }
            }
            String raw = stringBuilder.toString();
            String reverse = stringBuilder.reverse().toString();
            if(raw.equals(reverse)){
                return true;
            }
            return false;
        }
    }
}
```
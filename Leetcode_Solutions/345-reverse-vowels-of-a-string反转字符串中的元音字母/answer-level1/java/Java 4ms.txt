### 解题思路
类似快排的思想

### 代码

```java
class Solution {
    public String reverseVowels(String s) {
        //a e i o u
        int left = 0, right = s.length()-1;
        StringBuilder sb = new StringBuilder(s);
        while(left<right){
            while(left<right && !check(sb.charAt(right))){
                right--;
            }
            while(left<right && !check(sb.charAt(left))){
                left++;
            }
            if(left<right){
                char c = sb.charAt(left);
                sb.setCharAt(left++,sb.charAt(right));
                sb.setCharAt(right--,c);
            }
        }
        return sb.toString();
    }
    public boolean check(char c){
        switch(c){
            case 'a': return true;
            case 'e': return true;
            case 'i': return true;
            case 'o': return true;
            case 'u': return true;
            case 'A': return true;
            case 'E': return true;
            case 'I': return true;
            case 'O': return true;
            case 'U': return true;
            default: return false;
        }
    }
}
```
### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isStrobogrammatic(String num) {
        HashMap<Character, Character> map = new HashMap<>();
        map.put('6', '9');
        map.put('9', '6');
        map.put('8', '8');
        map.put('1', '1');
        map.put('0', '0');
        int start = 0, end = num.length() - 1;
        while(start<end) {
            if(map.get(num.charAt(start))==null || map.get(num.charAt(end))==null) {
                return false;
                
            } else if(map.get(num.charAt(start))!=num.charAt(end)) {
                return false;
            }
            start++;
            end--;
        }
        if(start==end) {
            if(num.charAt(start)!='1' && num.charAt(start)!='8' && num.charAt(start)!='0' ) return false;
        }
        return true;
    }
}
```

用时和内存都是100%，还不错
### 解题思路
在结果字符串最后两个字符不一样的情况下，添加三个字符中剩余次数最多的；
在结果字符串最后两个字符一样的情况下，添加与最后字符不一样的另外两个字符中剩余次数较多的。

### 代码

```java
class Solution {
    private Map<Character, Integer> char2num;
    
    private char nextChar(char exclude) {
        char next;
        if (exclude == 'a') {
            next = char2num.get('b') > char2num.get('c') ? 'b' : 'c';
        }
        else if (exclude == 'b') {
            next = char2num.get('a') > char2num.get('c') ? 'a' : 'c';
        }
        else if (exclude == 'c') {
            next = char2num.get('a') > char2num.get('b') ? 'a' : 'b';
        }
        else {
            next = char2num.get('a') > char2num.get('b') ? 'a' : 'b';
            next = char2num.get(next) > char2num.get('c') ? next : 'c';
        }
        return next;
    }
    
    public String longestDiverseString(int a, int b, int c) {
        char2num = new HashMap<>();
        char2num.put('a', a);
        char2num.put('b', b);
        char2num.put('c', c);
        
        StringBuilder result = new StringBuilder(a + b + c);
        
        while (char2num.get('a') != 0 || char2num.get('b') != 0 || char2num.get('c') != 0) {
            int L = result.length();
            char next;
            if (L < 2 || result.charAt(L - 1) != result.charAt(L - 2)) {
                next = nextChar(' ');
            }
            else {
                next = nextChar(result.charAt(L - 1));     
            }
            if (char2num.get(next) <= 0) {
                break;
            }
            char2num.put(next, char2num.get(next) - 1);
            result.append(next);
        }
        
        return result.toString();
        
    }
}
```
### 解题思路
当前元素代表的值如果大于后面一个元素的值，那么就应该是 + ，当前元素代表的值如果小于后面一个元素的值，那么就应该是 -。所有元素遍历完后，加上最后一个元素的值就ok了。

### 代码

```java
class Solution {
    public int romanToInt(String s) {
      int sum = 0;
        int i1 = get(s.charAt(0));
        for (int i =1;i<s.length();i++){
            int i2 = get(s.charAt(i));
            sum = i1<i2? sum -i1: sum+i1;
            i1 = i2;
        }
        sum += i1;
        return sum;
    }
    
    private int get(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }


}
```
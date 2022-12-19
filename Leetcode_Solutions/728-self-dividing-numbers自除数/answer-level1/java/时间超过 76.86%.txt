### 解题思路
此处撰写解题思路
把 n 每一位摘出来比较

### 代码

```java
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> res = new ArrayList<>();
        for (int n = left; n < right + 1; n++) {
            if (selfDividing(n)) res.add(n);
        }
        return res;
    }

    //n化作字符串
    /*
    public boolean selfDividing (int n) {
        String s = String.valueOf(n);
        for (int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if ( c =='0' || (n % (c-'0') > 0) ) return false;
        }
        return true;
    }
    */

    // n = n/10 拆分
   
    public boolean selfDividing (int n) {
        int on = n;
        int mod = 0;
        while (n > 0) {
            mod = n%10;
            if ( mod == 0 || on % mod > 0) return false;
            n = n /10;
        }
        return true;
    }
    
}
 
```
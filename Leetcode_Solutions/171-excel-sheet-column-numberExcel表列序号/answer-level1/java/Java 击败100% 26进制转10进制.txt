
```
class Solution {
    public int titleToNumber(String s) {
        int res = 0;
        for(int i=0; i<s.length(); i++){
            //'@'的ascii是64, 'A'的ascii是65, 使用'@'的小优势是不用再+1了
            res = res * 26 + (s.charAt(i) - '@');
        }
        return res;
    }
}
```
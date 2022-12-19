

## 一个略愚蠢的解法
```java
class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1) return s;
        char[] ch = s.toCharArray();
        
        String res = "";
        String ret = "";
        for(int row = 0; row < numRows; row ++){
            res = "";
            for(int i = 0; i * (2 * numRows - 2) + row < ch.length; i ++){
                res += ch[i * (2 * numRows - 2) + row];
                
                if(row != 0 && row != numRows - 1 && (i + 1) * (2 * numRows - 2) - row < ch.length){
                    res += ch[(i + 1) * (2 * numRows - 2) - row];
                }
            }
            ret += res;
        }
        
        return ret;
        
        
    }
}
```
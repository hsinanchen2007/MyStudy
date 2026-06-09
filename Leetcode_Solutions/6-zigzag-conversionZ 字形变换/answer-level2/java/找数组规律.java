### 解题思路
此处撰写解题思路
找规律第一行和最后一行是只有mod = 2 *( numRows -1);的数往上加就行
其他行还要加上一个2 *( numRows -1 - 当时行数)的位置，这些行有两个
### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
         if (numRows == 1){
            return s;
        }
        StringBuffer sb = new StringBuffer();
        int mod = 2 *( numRows -1);
        for(int i =0 ;i<s.length();){
            sb.append(s.charAt(i));
            i+=mod;
        }
        for(int j = 1; j<numRows-1;j++){
            int mod1 = 2*(numRows-1-j);
            for(int i =j ;i< s.length(); i+=mod){
                sb.append(s.charAt(i));
                if(i+mod1 < s.length()){
                    sb.append(s.charAt(i+mod1));
                }
            }
        }
         for(int i =numRows-1 ;i<s.length();){
            sb.append(s.charAt(i));
            i+=mod;
        }
        return sb.toString();
    }
}
```
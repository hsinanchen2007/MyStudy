### 解题思路
常规解法。观察示例形状找规律。
*记得初始化StringBuilder数组。

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        StringBuilder[] sb = new StringBuilder[numRows] ;
        for(int i = 0 ; i < numRows ; i++){
            sb[i] = new StringBuilder() ;
        }
        char[] ss = s.toCharArray() ;
        int len = ss.length , i = 0 ;
        while(i < len){
            for(int j = 0 ; j < numRows ; j++){
                if(i < len){
                    sb[j].append(ss[i++]) ;
                }else{
                    break ;
                }
            }
            for(int j = numRows - 2 ; j >= 1 ; j--){
                if(i < len){
                    sb[j].append(ss[i++]) ;
                }else{
                    break ;
                }
            }
        }
        StringBuilder ans = new StringBuilder() ;
        for(StringBuilder sbb:sb){
            ans.append(sbb) ;
        }
        return ans.toString() ;
    }
}
```
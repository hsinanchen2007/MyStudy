### 解题思路
    把字符串的一竖列和一斜排看作一组，分行运算，所要返回的字符串为str，传入的字符串为s，则每一行下竖排间隔为numRows
```
竖排间隔:(numRows-2)*2+1+1  //这里的numRows-2为除了第一行和最后一行以外其他行
斜排位置：int plus = (i==0||i==numRows-1)?0:((numRows-i-2)*2+1+1); //i为所在行号

```


空间复杂度应该是O(n)吧？为什么占用内存这么大。。

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        if(numRows==1){
            return s;
        }
        int len = s.length();
        StringBuilder str = new StringBuilder();
        
        for(int i=0;i<numRows;i++){
            //遍历数组
            int plus = (i==0||i==numRows-1)?0:((numRows-i-2)*2+1+1);
            int pos = i;
            while(pos<len){
                str.append(s.charAt(pos));
                if(plus!=0&&(pos+plus)<len){
                    str.append(s.charAt(pos+plus));
                }
                pos = pos + (numRows-2)*2+1+1;
            }
        }
        return str.toString();
    }
}
```
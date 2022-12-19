### 解题思路
此处撰写解题思路
注意在List里放入StringBuilder作为动态二维数组使用。
### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        ArrayList<StringBuilder> row=new ArrayList<>();
        int currows=0;
        boolean flag=false;
        if(numRows==1) return s;
        for(int i=0;i<Math.min(numRows,s.length());i++){
            row.add(new StringBuilder());
        }
        for(char c:s.toCharArray()){
            row.get(currows).append(c);
            if(currows==0||numRows-currows==1)flag=!flag;
            currows+=flag?1:-1;
        }
        StringBuilder sb=new StringBuilder();
        for(StringBuilder ch:row){
            sb.append(ch);
        }
        return sb.toString();
    }
}
```
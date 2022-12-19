### 解题思路
此处撰写解题思路
千万别学，我发出来留个纪念
PS.题目没有说字符串包含标点符号啊！
### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        if(numRows==1)return s;
        StringBuffer ret=new StringBuffer();
        char[][] sTable=new char[s.length()][numRows];
        int index=0;
            
        for(int i=0;i<s.length();i++){
            for(int j=0;j<numRows;j++){
                sTable[i][j]='0';
                if(index>=s.length()) continue;
                if(i%(numRows-1)!=0){
                    if((j+1)==(numRows-(i%(numRows-1)))){
                        sTable[i][j]=s.charAt(index);
                        index++;
                    }
                }else{
                    sTable[i][j]=s.charAt(index);
                    index++;
                }
            }
        }
        for(int x=0;x<numRows;x++){
            for(int y=0;y<s.length();y++){
                 if(sTable[y][x]!='0')ret.append(sTable[y][x]);
            }
        }
        return ret.toString();
    }
}
```
### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
            String[][] size=new String[numRows][s.length()/numRows*numRows];
            String[] ss=s.split("");
            if(s.length()<=numRows){
                return s;
            }
            //行
            int row=0;
            //列
            int col=0;
            //行+1  标识
            boolean flag=true;
            for(int i=0;i<s.length();i++){
                size[row][col]=ss[i];
                //如果行数小于总行数则+1
                if(row<numRows&&flag==true){
                     row++;
                }
                //如果加完后为行数，修改变量和加列标识
                if(row==numRows&&flag==true){
                    flag=false;
                    row--;
                }
                //进行列+1，此处需判断行-1
                if(!flag){
                  col++;
                  if(row!=0){
                  row--;
                  }
                }
                if(row==0&&!flag){
                    flag=true;
                }

                
            }
            StringBuffer sb=new StringBuffer();
            for(int i=0;i<size.length;i++){
                for(int j=0;j<size[i].length;j++){
                    if(size[i][j]!=null){
                    sb.append(size[i][j]);
                    }
                }
            }
            return sb.toString();

    }
}
```
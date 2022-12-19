### 解题思路
构造出一个二维的数组,确定二维数组的两个维度大小，就可以进行z型数据的转换输出，但是此算法会存在大量的空字符判断处理，空间复杂度有待提高；构造出二维数组之后，判断斜对角上的左下角元素是否存在了，Z边上的上一个元素是否存在，根据这两种情况就可以将字符串填充到二维数组当中。

### 代码

```java
class Solution {


    public String convert(String s, int numRows) {
        int rowIndex=numRows-1;
        if(rowIndex==0){
            return s;
        }

        //如果为空，则直接返回
        if(s==null||"".equals(s)){
            return "";
        }

        int colIndex=s.length()/2+numRows;
        //实例化数组
        char arry[][]=new char[numRows][colIndex];
        //给数组赋值
        int count=0;
        for(int x=0;x<colIndex;x++){
            for(int y=0;y<=rowIndex;y++){
                //怎么赋值处理
                //上一个元素必须有值才行,没有值则跳过不赋值处理
                if(x%rowIndex==0){
                    if(y-1>=0) {
                        if (arry[y - 1][x] == '\u0000') {
                            continue;
                        } else {
                            if (count < s.length()) {
                                char temp = s.charAt(count++);
                                arry[y][x] = temp;
                                continue;
                            }
                        }
                    }else{
                        if (count < s.length()) {
                            char temp = s.charAt(count++);
                            arry[y][x] = temp;
                            continue;
                        }
                    }
                }
                //左下角元素必须有值,没有值则跳过不赋值处理
                if(y+x%rowIndex==rowIndex){
                    if(y+1<=rowIndex&&x-1>=0) {
                        if (arry[y + 1][x - 1] == '\u0000') {
                            continue;
                        } else {
                            if (count < s.length()) {
                                char temp = s.charAt(count++);
                                arry[y][x] = temp;
                                continue;
                            }
                        }
                    }else{
                        if (count < s.length()) {
                            char temp = s.charAt(count++);
                            arry[y][x] = temp;
                            continue;
                        }
                    }
                }
                //左下角元素必须有值,没有值则跳过不赋值处理
                if(y+x==rowIndex){
                    if(y+1<=rowIndex&&x-1>=0) {
                        if (arry[y + 1][x - 1] == '\u0000') {
                            continue;
                        } else {
                            if (count < s.length()) {
                                char temp = s.charAt(count++);
                                arry[y][x] = temp;
                                continue;
                            }
                        }
                    }else{
                        if (count < s.length()) {
                            char temp = s.charAt(count++);
                            arry[y][x] = temp;
                            continue;
                        }
                    }
                }


            }
        }
        //遍历char数组，重新取出数据，拼接成新的数据
        StringBuffer sbResult=new StringBuffer("");
        for(int a=0;a<arry.length;a++){
            for(int b=0;b<arry[a].length;b++){
                if(arry[a][b]=='\u0000') {
                    continue;
                }
                sbResult.append(arry[a][b]);
            }
        }
        return sbResult.toString().trim();
    }


    
}

```
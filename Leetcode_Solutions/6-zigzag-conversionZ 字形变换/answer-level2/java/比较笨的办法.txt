### 解题思路
将字符按要求组成数组，再循环数据处理，这个方法有点笨。
先计算有多少列，参见函数calcol
如下图,假设数据有8个字符，6个字符做为一组。组成数组也是用这个方法，不停的将列及行进行移动
1     7
2   6 8
3 5
4

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        String result = "";
        if (s.length() < 3 || numRows <= 1)return s;

        int totalcol = calcol(s,numRows);
        String[][] a = new String[numRows][totalcol];
        int rowconsult = -1;int col = 0;
        int temrow = 0;
        for (int i=0 ; i < s.length() ; i++){
            //行的坐标变化
            //假设行数为5 ，则以9为除数，i为被除数，如果余数大于4则加1，否则则-1

            temrow = i % (numRows * 2 -2);

            if ((temrow > 0 && temrow < numRows ) || i == 0){
                rowconsult += 1;
            }else {
                rowconsult -= 1;
            }

            if(temrow >= numRows || (temrow == 0 & i !=0)){
                col = col + 1 ;
            }
            //System.out.println("no --->" +  i +" x-->" + rowconsult + " Y-->" + col + " value =" + s.substring(i,i+1) + " temp=" + temrow);

            a[ rowconsult][ col ] = s.substring(i,i+1);
        }

        for(int x = 0; x < numRows ; x ++){
            for (int y = 0 ; y < totalcol ; y ++){
                if (null != a[x][y]){
                    result = result + a[x][y];
                }
            }
        }
        return result;
    }


    protected   int calcol(String s,int row){
        //
        int tmp = s.length() / (row  * 2 -2 );

        if(tmp == 0){
            return  s.length() % row  + 1;
        }
        int tmp2 = s.length() % (row  * 2 -2 );
        return (tmp * (row - 1) +  (tmp2 / row == 0 ? 1 : (tmp2 % row  + 1))) + 1;
    }
}
```
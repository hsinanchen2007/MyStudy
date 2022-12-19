```
class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1) return s;
        if(numRows == 0) return null;
        if(s.length() <= numRows) return s;
        int c = (numRows-1)*(s.length()/(numRows + numRows-2) +1);
        //从第二列开始 有numRows-2列是只有一个元素的
        //将中间那些只有一个元素的列看为一个整体 周期为numRows-1 
        //numRows为4时 周期为3单体个数为2（2，3）--- (5,6)
        //numRows为3时 周期为2单体个数为1 （2） --- （4）
        //其余正常列 均放numRows个元素
        //从第0列开始算 x = 1~numRows-2 + k*(numRows-1)
        //即x%(numRows-1) 范围从1至numRows-2
        StringBuilder sb = new StringBuilder();
        char[][] arr = new char[numRows][c];
        for(int i = 0; i<numRows; i++) {
            for(int j = 0; j<c; j++) {
                arr[i][j] = '*';
            }
        }
        int count = 0;
        for(int j = 0; j<c && count<s.length(); j++) {
            if( (j%(numRows-1))>=1 && (j%(numRows-1))<=(numRows-2) && count<s.length() ) {
                //每一列放一个元素
                arr[numRows-1-j%(numRows-1)][j] = s.charAt(count++);
                continue;
            }
            else {
                //该列元素放满
                for(int k = 0; k<numRows && count<s.length(); k++) {
                    arr[k][j] = s.charAt(count++);
                }
                continue;
            }
        }
        for(int i = 0; i<numRows; i++) {
            for(int j = 0; j<c; j++) {
                if(arr[i][j]!='*') sb.append(arr[i][j]);
            }
        }
        return sb.toString();
    }
}
```

### 解题思路
此处撰写解题思路
空间复杂度O（n²）
时间复杂度O（n²）
思路：用二维数组arr存储 字符串s 中字符的下标index,
之后遍历二维数组arr构造字符串ans
不足之处，还望指正，谢谢！
### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
      int len = s.length();
        String ans = "";
        if(len==0||s.equals("")){
            return ans;
        }else if(len<numRows||numRows==1){
            return s;
        }else if(numRows==2){

            for(int i=0;i<len;i=i+2){
                ans += s.charAt(i);
            }
            for(int j=1;j<len;j=j+2){
                ans += s.charAt(j);
            }
            return ans;
        }
        int col = (len/numRows)*2+numRows,index = 1,row_index = 0;
        int[][] arr = new int[numRows][col];
        for(int i=0;i<col;i++){
            if(row_index==0){
                while (row_index!=numRows&&index<=len){
                    arr[row_index++][i] = index++;
                }
            }else if(row_index==numRows){
                while (row_index!=-1&&index<=len){
                    if(row_index==numRows){
                        --row_index;
                        arr[row_index--][i] = 0;
                    }else if(row_index==0){
                        arr[row_index--][i] = 0;
                    }else {
                        arr[row_index--][i] = index++;
                    }
                }
                row_index = 0;
            }
            if(index>len){
                break;
            }
        }
        for (int i=0;i<numRows;i++){
            for(int j=0;j<col;j++){
                if(ans.length()==len){
                    break;
                }
                if(arr[i][j]==0){
                    continue;
                }else {
                    ans += s.charAt(arr[i][j]-1);
                }
            }
        }
        return ans;
    }


}
```
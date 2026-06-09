执行结果：
通过
显示详情
执行用时 :
28 ms
, 在所有 Java 提交中击败了
65.91%
的用户
内存消耗 :
46.4 MB
, 在所有 Java 提交中击败了
81.00%
的用户
```
class Solution {
    int max = 0;
    public int maximalRectangle(char[][] matrix) {
        int x=matrix.length;
        if(x==0)return 0;
        int y = matrix[0].length;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                 cal(matrix,x,y,i,j);
            }
        }
        return max;
    }
    private void cal(char[][] matrix, int x, int y,int i,int j){
        int cj=y;
         
        for(int ii=i;ii<x;ii++){
           for(int jj=j;jj<cj;jj++){
                if(matrix[ii][jj]=='0'){
                    if(jj<cj){
                        int val = (jj-j)*(ii-i+1);
                        if(val>max){
                            max=val;
                        }
                        cj=jj;
                    }
                    break;
                }
                 if(jj==cj-1){
                    int val = (cj-j)*(ii-i+1);
                    if(val>max){
                        max=val;
                    } 
                }
            }
           
            if(ii==i-1){
                int val = (cj-j)*(ii-i+1);
                if(val>max){
                    max=val;
                } 
            }
        }
    }
}
```

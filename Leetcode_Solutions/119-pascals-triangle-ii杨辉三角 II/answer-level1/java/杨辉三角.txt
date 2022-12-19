### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        ArrayList<Integer> list=new ArrayList<>();
         int [][]num=new int[rowIndex+1][rowIndex+1];
         int x=0;
         for(int i=0;i<=rowIndex;i++){
             num[i][0]=1;
             num[i][x++]=1;
         }
         for(int i=2;i<rowIndex+1;i++){
             for(int j=1;j<rowIndex+1;j++){
             if(num[i][j]!=1){
                 num[i][j]=num[i-1][j]+num[i-1][j-1];
             }
         }
         }
         for(int j=0;j<=rowIndex;j++)
         list.add(num[rowIndex][j]);
      return list;
    }
}
```
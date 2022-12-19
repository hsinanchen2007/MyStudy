#### - 从左到右递归试法，先行后列，满足条件就记录在record数组中

```java
class Solution {
    public List<List<String>> solveNQueens(int n) {
   List<List<String>> list = new ArrayList<>();
        back(0,list,n,new int[n]);
        return list;
    }
    //record数组记录每一行哪个位置插入皇后
    //i为行，j为列
    public void back(int i,List<List<String>> lists,int n,int record[]){//record也可以是二维数组记录位置
        if(i == n){
            print(lists,record);//打印函数
            return;
        }
        for(int j = 0;j<n;j++){
            if(isValid(record,i,j)){//该位置是否满足条件（不同行，不同列，不同斜线）
                record[i] = j;
                back(i+1,lists,n,record);
            }
        }
    }

    private boolean isValid(int[] record, int i, int j) {
        for(int k=0;k<i;k++){
            if(j==record[k]||Math.abs(i-k)==Math.abs(record[k]-j)){//斜率不为1或者-1
                return false;
            }
        }
        return true;
    }

    private void print(List<List<String>> list,int record[]){//record中记录的皇后位置还原
        List<String> strings = new ArrayList<>();
        for(int i = 0;i<record.length;i++){
            //int j = record[i];
            StringBuilder stringBuilder = new StringBuilder();
            for(int j = 0;j<record.length;j++){
                if(j == record[i]){
                    stringBuilder.append("Q");
                }else{
                    stringBuilder.append(".");
                }
            }
            strings.add(stringBuilder.toString());
            
        }
        list.add(strings);
    }
}
```
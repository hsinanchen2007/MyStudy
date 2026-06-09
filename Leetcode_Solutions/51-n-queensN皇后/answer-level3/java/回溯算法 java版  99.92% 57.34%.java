### 解题思路
用四个boolean数组表示行/列/主对角线/次对角线上是否存在Q皇后
1. 遍历行，若行中有Q，则继续处理下一行
2. 若行中没有Q，则遍历列，列中已有Q则继续处理下一列；列中有Q但主/次对角线存在Q，则继续处理下一列；列中无Q且主/次对角线无Q则放入Q，此时判断是否到了最后一行，如果是就加入结果集，否则继续处理下一行
3. 如果处理完一行的每一列，这一行仍然没有Q，则回溯

### 代码

```java
class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result=new ArrayList<>();
        
        //n<1时，返回[[]]
        if(n<1){
            result.add(new ArrayList<String>());
            return result;
        }
        
        //棋盘初始化，不摆放皇后
        char[][] queues=new char[n][n];
        for(char[] ch:queues){
            Arrays.fill(ch,'.');
        }
        
        boolean[] used1=new boolean[n];//记录行中是否已存在Q
        boolean[] used2=new boolean[n];//记录列中是否已存在Q
        boolean[] used3=new boolean[2*n-1];//记录副对角线上是否已存在Q,i+j在0~2*n-2之间
        boolean[] used4=new boolean[2*n+1];//记录主对角线上是否已存在Q，i-j在-n~n之间+n则在0~2*n之间
        
        
        
        helper(queues,result,0,n,used1,used2,used3,used4);
        return result;
    }
    
    public void helper(char[][] queues,List<List<String>> result,int row,int num,boolean[] used1,boolean[] used2,boolean[] used3,boolean[] used4){
        //如果每行都正确摆放了Q，则加入结果集
        if(row==num&&used1[num-1]){
            List<String> temp=new ArrayList<>();
            for(char[] chs:queues){
                temp.add(new String(chs));
            }
            result.add(new ArrayList<String>(temp));
            return;
        }
        
        //遍历列
        for(int j=0;j<num;j++){
            if(used2[j]||used3[j+row]||used4[row-j+num]){
                if(j==num-1) return;//如果某一行的每一列都无法填值，说明无结果
                continue;
            }else{
                queues[row][j]='Q';
                used1[row]=true;
                used2[j]=true;
                used3[row+j]=true;
                used4[row-j+num]=true;
                
                helper(queues,result,row+1,num,used1,used2,used3,used4);
                
                queues[row][j]='.';
                used1[row]=false;
                used2[j]=false;
                used3[row+j]=false;
                used4[row-j+num]=false;
            }
        }
    }
}
```
执行用时 :20 ms, 在所有 Java 提交中击败了6.35%的用户
内存消耗 :45.2 MB, 在所有 Java 提交中击败了67.62%的用户

分3个场景
- 行不重复
- 列不重复
- 3*3不重复

都统一调用一个子函数，入参为列表，在子函数中列表转set，如果大小相等，这代表没有重复元素
```
class Solution {
    public boolean isValidSudoku(char[][] board) {
        List<Character> alist=new LinkedList<Character>();
        Boolean flag=true;
        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                    alist.add(board[i][j]);
                }
            }
            flag=calculate(alist);
            alist.clear();
            if(!flag){
                return flag;
            } 
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    alist.add(board[i][j]);
                }
            }
            flag=calculate(alist);
            alist.clear();
            if(!flag){
                return flag;
            } 
        }
        int i=0; //大数独实际行索引
        int j=0; //大数独实际列索引
        while(i<9 && j<9){
            if(board[i][j]!='.'){
             alist.add(board[i][j]);
            }

            if((i+1)%3==0 &&  (j+1)%3==0){
                flag=calculate(alist);
                alist.clear();
                if(!flag){
                    return flag;
                }
                //注意点，如果到了3*3子数独边界，需要对i和j进行特别处理,以便当i=j=2后,跳过了i=0,j=3的数独等   
                if(i!=8){
                    i++;
                    j=j-2;   //注意点 bug  不能是 j=0; 否则死循环；考虑 第一排第2个子数独，本来要后面计算第2排第2个，却会错误计算为第1排第2个
                }else if(i==8){
                    i=0;
                    j++;
                }
            }else{  //如果当前索引不是在子数独右下角元素
                if((i+1)%3==0){
                    i=i-2;  //不能是i=0;考虑 第2排第2个子数独 ，会计算错误
                    j++; 
                }else{
                    i++;    
                }

            }
            
        }      
        return true;
    }
    
    private Boolean calculate(List<Character> calList){
        Set result = new HashSet(calList);
        return result.size()==calList.size();
    }
}
```

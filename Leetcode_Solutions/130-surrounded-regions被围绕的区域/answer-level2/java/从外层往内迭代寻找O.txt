执行结果：
通过
显示详情
执行用时 :
49 ms
, 在所有 Java 提交中击败了
5.04%
的用户
内存消耗 :
49.5 MB
, 在所有 Java 提交中击败了
42.91%
的用户
```
class Solution {
    Set<String> set = new HashSet<>();
    public void solve(char[][] board) {
        int x = board.length;
        if(x==0)return ;
        int y = board[0].length;
       
        //find o out side;
       
        for(int j=0; j<y; j++){
            if(board[0][j]=='O'){
                set.add(0+"-"+j);
            }
            if(board[x-1][j]=='O'){
                set.add((x-1)+"-"+j);
            }
        }
        for(int i=0; i<x; i++){
            if(board[i][0]=='O'){
                set.add(i+"-"+0);
            }
            if(board[i][y-1]=='O'){
                set.add((i)+"-"+(y-1));
            }
        }
        pro(set,board,x,y);
        for(int i=0; i<x; i++){
             for(int j=0; j<y; j++){
                 if(!set.contains(i+"-"+j)){
                     board[i][j]='X';
                 }
             }
         }
    }
    private void pro(Set<String> set1,char[][] board,int x,int y){
        Set<String> set2 = new HashSet<>();
        for(String s:set1){
            String[] ss=s.split("-");
            set2.addAll(get(board,Integer.parseInt(ss[0]),Integer.parseInt(ss[1]),x,y));
        }
        if(set2.isEmpty()){
            return;
        }else{
            set.addAll(set2);
            pro(set2,board,x,y);
        }
    }
    private Set<String> get(char[][] board, int i, int j,int x, int y){
        Set<String> set1 = new HashSet<>();
        
        if(i-1>=0&&board[i-1][j]=='O'){
            if(!set.contains((i-1)+"-"+j)){
                set1.add((i-1)+"-"+j);
            }
        }
        if(i+1<x&&board[i+1][j]=='O'){
            if(!set.contains((i+1)+"-"+j)){
                set1.add((i+1)+"-"+j);
            }
        }
        if(j-1>=0&&board[i][j-1]=='O'){
            if(!set.contains((i)+"-"+(j-1))){
                set1.add((i)+"-"+(j-1));
            }
        }
        if(j+1<y&&board[i][j+1]=='O'){
            if(!set.contains((i)+"-"+(j+1))){
                set1.add((i)+"-"+(j+1));
            }
        }
         return set1;
    }
}
```

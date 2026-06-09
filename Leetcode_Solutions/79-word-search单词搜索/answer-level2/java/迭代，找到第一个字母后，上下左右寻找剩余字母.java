执行结果：
通过
显示详情
执行用时 :
160 ms
, 在所有 Java 提交中击败了
5.05%
的用户
内存消耗 :
60.3 MB
, 在所有 Java 提交中击败了
10.33%
的用户
```
class Solution {
    public boolean exist(char[][] board, String word) {
        int k = word.length();
        if(k==0)return true;
        char f = word.charAt(0);
        if(word.length()>k*board[0].length)return false;
        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[0].length; j++){
                if(board[i][j]==f){
                    if(1==word.length())return true;
                    Set<String> used = new HashSet<String>();
                    StringBuffer sb = new StringBuffer();
                    sb.append(i);
                    sb.append("_");
                    sb.append(j);
                    used.add(sb.toString());
                    if(check(word,i,j,board,1,used)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
    private boolean check(String word,int i,int j,char[][] cs, int s,Set<String> used){
        if(s==word.length())return true;
        char cur = word.charAt(s);
        //up
        if(i-1>=0&&!used.contains((i-1)+"_"+j)){
            if(cs[i-1][j]==cur){
                Set<String> ss = new HashSet<String>();
                ss.addAll(used);
                StringBuffer sb = new StringBuffer();
                    sb.append(i-1);
                    sb.append("_");
                    sb.append(j);
                    ss.add(sb.toString());
                if(check(word,i-1,j,cs,s+1,ss)){
                    return true;
                }
            }
        }
        //down
        if(i+1<cs.length&&!used.contains((i+1)+"_"+j)){
            if(cs[i+1][j]==cur){
                 Set<String> ss = new HashSet<String>();
                ss.addAll(used);
                StringBuffer sb = new StringBuffer();
                    sb.append(i+1);
                    sb.append("_");
                    sb.append(j);
                    ss.add(sb.toString());
                if(check(word,i+1,j,cs,s+1,ss)){
                    return true;
                }
            }
        }
        //left
        if(j-1>=0&&!used.contains((i)+"_"+(j-1))){
            if(cs[i][j-1]==cur){
                 Set<String> ss = new HashSet<String>();
                ss.addAll(used);
                StringBuffer sb = new StringBuffer();
                    sb.append(i);
                    sb.append("_");
                    sb.append(j-1);
                    ss.add(sb.toString());
                if(check(word,i,j-1,cs,s+1,ss)){
                    return true;
                }
            }
        }
        //right
        if(j+1<cs[0].length&&!used.contains((i)+"_"+(j+1))){
            if(cs[i][j+1]==cur){
                 Set<String> ss = new HashSet<String>();
                ss.addAll(used);
                StringBuffer sb = new StringBuffer();
                    sb.append(i);
                    sb.append("_");
                    sb.append(j+1);
                    ss.add(sb.toString());
                if(check(word,i,j+1,cs,s+1,ss)){
                    return true;
                }
            }
        }
        return false;
        
    }
}
```

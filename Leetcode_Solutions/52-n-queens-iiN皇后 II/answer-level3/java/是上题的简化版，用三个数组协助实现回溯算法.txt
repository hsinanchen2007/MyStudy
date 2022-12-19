执行结果：
通过
显示详情
执行用时 :
4 ms
, 在所有 Java 提交中击败了
60.44%
的用户
内存消耗 :
33.8 MB
, 在所有 Java 提交中击败了
51.88%
的用户
```
class Solution {
    int res=0;
    public int totalNQueens(int n) {
        if(n==0)return 0;
        int[] hill = new int[2*n-1];
        int[] dale = new int[2*n-1];
        int[] lines = new int[n];
        backtrack(0,n,hill,dale,lines);
        return res;
    }
    
    private void backtrack(int cur,int n, int[] hill, int[] dale, int[] lines){
        if(cur==n){
            res++;
            return;
        }
        for(int i=0; i<n;i++){
            if(!beAttacked(cur,i,n,hill,dale,lines)){
                put(cur,i,n,hill,dale,lines);
                backtrack(cur+1,n,hill,dale,lines);
                remove(cur,i,n,hill,dale,lines);
            }
        }
    }
    private void put(int cur, int l,int n, int[] hill, int[] dale, int[] lines){
        lines[l]=1;
        hill[cur+l]=1;
        dale[cur-l+n-1]=1;
    }
    private void remove(int cur, int l, int n,int[] hill, int[] dale, int[] lines){
        lines[l]=0;
        hill[cur+l]=0;
        dale[cur-l+n-1]=0;
    }
    private boolean beAttacked(int cur, int l, int n,int[] hill, int[] dale, int[] lines){
        if(lines[l]==1||hill[cur+l]==1||dale[cur-l+n-1]==1){
            return true;
        }else{
            return false;
        }
    }
}
```

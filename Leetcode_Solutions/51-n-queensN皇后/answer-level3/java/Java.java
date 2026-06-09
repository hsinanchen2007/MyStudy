N皇后可以说是非常经典的回溯算法例题，看到这输出要求我想还是先用数组存储solution比较简单一点。
```
public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        int[] queens = new int[n];
        for(int i = 0;i<n;i++) queens[i] = -1;
        backTrack(res,n,queens,0);
        return res;
    }
    
    private static void backTrack(List<List<String>> res, int n, int[] queens,int index){
        if(index == n){
            List<String> temp = new ArrayList<>();
            for(int queen:queens){
                StringBuffer sb = new StringBuffer();
                for(int i = 0;i<n;i++){
                    if(i == queen) sb.append('Q');
                    else sb.append('.');
                }
                temp.add(sb.toString());
            }
            res.add(temp);
            return;
        }
        
        for(int i = 0; i<n;i++){
            queens[index] = i;
            if(goodQueens(index,queens)){
                backTrack(res,n,queens,index+1);
            }else queens[index] = -1;
        }
    }
    
    private static boolean goodQueens(int index, int[] queens){
        for(int i = 0;i<index;i++){
            if(queens[i] == queens[index] || i+queens[i]==index+queens[index] || i-queens[i] == index-queens[index]){
                return false;
            }
        }
        return true;
    }
```
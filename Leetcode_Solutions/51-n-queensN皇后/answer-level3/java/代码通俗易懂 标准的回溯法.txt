```
public  List<List<String>> solveNQueens(int n) {
        boolean[] rowUsed = new boolean[n];
        boolean[] colUsed = new boolean[n];
        //主对角线 i>=j时 [i-j] i<j时 [j-i+n-1]
        boolean[] zhuxieUsed = new boolean[2*n-1];
        //次对角线 [i+j]
        boolean[] fuxieUsed = new boolean[2*n-1];
        List<List<String>> result = new ArrayList<>();
        List<String> list = new ArrayList<>();
        solveBack(zhuxieUsed,fuxieUsed,rowUsed,colUsed,n,result,list);
        return result;
    }

    private  void solveBack(boolean[] zhuxieUsed,boolean[] fuxieUsed,boolean[] rowUsed, boolean[] colUsed, int n, List<List<String>> result, List<String> list) {
        if (list.size() == n) {
            result.add(new ArrayList<>(list));
        }else {
            for (int i = 0;i<n;i++){
                if (i == list.size()){
                    for (int j = 0;j<n;j++){
                        boolean canUse;
                        if (i >=j){
                            canUse = rowUsed[i] || colUsed[j] || zhuxieUsed[i-j]|| fuxieUsed[i+j];
                        }else {
                            canUse = rowUsed[i] || colUsed[j] || zhuxieUsed[j-i+n-1] || fuxieUsed[i+j];
                        }
                        if (!canUse){
                            list.add(putString(j,n));
                            rowUsed[i] = true;
                            colUsed[j] = true;
                            if (i >=j){
                                zhuxieUsed[i-j] = true;
                            }else {
                                zhuxieUsed[j-i+n-1] = true;
                            }
                            fuxieUsed[i+j] = true;
                            solveBack(zhuxieUsed,fuxieUsed,rowUsed,colUsed,n,result,list);
                            list.remove(list.size()-1);
                            rowUsed[i] = false;
                            colUsed[j] = false;
                            if (i >=j){
                                zhuxieUsed[i-j] = false;
                            }else {
                                zhuxieUsed[j-i+n-1] = false;
                            }
                            fuxieUsed[i+j] = false;
                        }
                    }
                }



            }
        }
    }

    private  String putString(int index,int n){
        StringBuilder sb = new StringBuilder();
        for (int i = 0;i<n;i++){
            if (i == index){
                sb.append("Q");
            }else {
                sb.append(".");
            }
        }
        return sb.toString();
    }
```

对每个皇后，记录离国王这八个放心的最近的皇后。
这个代码复杂了些，复杂度是O(M)，M为皇后的个数。
```
    private void init(int[][] resTmp, int i) {
        for (int j = 0; j < resTmp.length; j++) {
            for (int k = 0; k < resTmp[0].length; k++) {
                resTmp[j][k]=i;
            }
        }
    }

    public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
        int[] minDistance=new int[8];
        Arrays.fill(minDistance, Integer.MAX_VALUE);
        int tX=king[0];
        int tY=king[1];
        int[][] resTmp=new int[8][2];
        init(resTmp,-1);
        for (int[] queen:queens){
            int qX=queen[0];
            int qY=queen[1];
            if(tX==qX){
                int diff=tY-qY;
                getRes(resTmp,minDistance,diff<0?0:1,Math.abs(diff),queen);
            }else if(tY==qY){
                int diff=tX-qX;
                getRes(resTmp,minDistance,diff<0?2:3,Math.abs(diff),queen);
            }else {
                int diffX=tX-qX;
                int diffY=tY-qY;
                if(diffX==diffY){
                    getRes(resTmp,minDistance,diffX<0?4:5,Math.abs(diffX),queen);
                }else if(diffX==-diffY){
                    getRes(resTmp,minDistance,diffX<0?6:7,Math.abs(diffX),queen);
                }
            }
        }
        List<List<Integer>> res=new ArrayList<>();
        for (int[] t:resTmp){
            if(t[0]!=-1){
                List<Integer> list=new ArrayList<>(2);
                list.add(t[0]);
                list.add(t[1]);
                res.add(list);
            }
        }
        return res;
    }

    private void getRes(int[][] res, int[] minDistance, int i, int diff, int[] queen) {
        if(minDistance[i]>diff){
            minDistance[i]=diff;
            res[i][0]=queen[0];
            res[i][1]=queen[1];
        }
    }
```

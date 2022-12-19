    public int minSwapsCouples(int[] row) {
        int res = 0;

        int pairs = row.length/2 ;
        int[] ids = new int[row.length];
        Arrays.fill(ids,-1);

        //固定小的为idx，大的为value
        for (int i = 0; i < pairs; i++) {
            int a = row[2*i];
            int b = row[2*i+1];
            if (Math.min(a,b)%2 ==1|| Math.abs(a-b) != 1){
                ids[Math.min(a,b)] = Math.max(a,b);
            }
        }

        //如果都是-1说明都已经牵手，直接返回
        int j = 0;
        for (; j < ids.length; j++) {
            if (ids[j]!=-1){
                break;
            }
        }
        if (j == ids.length) return 0;

        //
        for (int i = 0; i < ids.length-1; i++) {
            //-1的说明已经牵手或者没有出现，ids[i] = i+1 说明已经调整到位， 都是直接跳过
            if (ids[i] == -1 || ids[i] == i+1) continue;

            if (ids[i] != i+1){ //没有牵手的请调整
                makeRight(i,ids);
                res++;
            }

        }

        return res;

    }


    /*  实现如下逻辑, 还是idx小于value的规则， 确实有点绕，小心写就是...
          0  1  3   -->    0   1  2  3
          4  2  5          1  -1  4  5
     */
    private void makeRight(int i, int[] ids1) {
        int newIdx = ids1[i];
        int oldValue = ids1[i+1];
        int oldIdx = i+1;

        ids1[i] = i+1;
        if (ids1[oldIdx]< newIdx){
            ids1[oldValue] = newIdx;
        } else {
            ids1[newIdx] = oldValue;
        }
        ids1[oldIdx] = -1;
    }


![Screenshot from 2019-07-18 15-36-31.png](https://pic.leetcode-cn.com/85b23bc33ce9bf5b07a03a6553136f9b9bb1fc7c373f76e41dfa3f6add4f346d-Screenshot%20from%202019-07-18%2015-36-31.png)

单纯就是固定下idx，然后贪心就好，这题并查集咋做我得去查查....
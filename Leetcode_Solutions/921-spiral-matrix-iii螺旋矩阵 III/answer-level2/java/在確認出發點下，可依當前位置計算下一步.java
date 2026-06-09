### 解题思路
假設 R 和 C 無限大，在已知出發點(r0,c0)，任選一個點，其下一步皆是已知的。
例如在 5x5 的範圍內，`O`為出發點，任一點的方向皆為已知，如下:
```text
> > > > >
^ > > > >
^ ^ O v v
^ < < < v
< < < < v
```
令出發點為(r0,c0), 當前點為(rIx,cIx) 判定其方向的邏輯如下:
- 取 `|rIx-r0|` 和 `|cIx-c0|` 的最大值 `dst0`，代表離出發點距離
- 在出發點右側，方向向下的條件: 
    1: `cIx>r0` (在出發點右側) 
    2: `dst0==cIx-c0`(`cIx-c0>=|rIx-r0|`)
    3: `rIx-r0!=dst0`(不為最下點，該點方向為向左)
- 在出發點下方，方向向左的條件: 
    1: `rIx>r0` (出發點下方)
    2: `dst0==rIx-r0`(`rIx-r0>=|cIx-c0|`)
    3: `c0-cIx!=dst0`(不為最左點，該點方向為向上)
- 在出發點左側，方向向上的條件:
    1: `cIx<c0` (在出發點左側)
    2: `dst0==c0-cIx`(`c0-cIx>=|rIx-r0|`)
    3: `r0-rIx!=dst0`(不為最上點，該點方向為向右)
- 在出發點上方，方向向右的條件:
    1: `rIx<r0` (出發點上方)
    2: `dst0==r0-rIx`(`r0-rIx>=|cIx-c0|`)
    3: 最右點(`cIx-c0==dst0`)還是向右，所以`出發點右側，方向向下`還須加條件 4
- 在出發點右側，方向向下的條件:
    4: `r0-rIx!=dst0`(避免在出發點上方，在最右點(`cIx-c0==dst0`)該點方向被轉下)

我們可以依上述邏輯，依序取出下一點，若該點在指定的範圍內，將其加入清單中。

### 代码

```java
class Solution {
    int[] nxtCell(int rIx, int cIx, int r0, int c0){
        //若為出發點，直接回傳右側點
        if(rIx==r0&&cIx==c0) return new int[]{r0,c0+1};
        int dst0 = Math.max(Math.abs(rIx-r0),Math.abs(cIx-c0));
        if(cIx>c0 && dst0==cIx-c0 && rIx-r0!=dst0 && r0-rIx!=dst0){//出發點右側，方向向下
            return new int[]{rIx+1,cIx};
        }else if(rIx>r0 && dst0==rIx-r0 && c0-cIx!=dst0){//出發點下方，方向向左
            return new int[]{rIx,cIx-1};
        }else if(cIx<c0 && dst0==c0-cIx && r0-rIx!=dst0){//出發點左側，方向向上
            return new int[]{rIx-1,cIx};
        }else if(rIx<r0 && dst0==r0-rIx){//出發點上方，方向向右
            return new int[]{rIx,cIx+1};
        }
        return null;
    }
    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
        int ttl=R*C;
        List<int[]> ansAL=new ArrayList<>();
        int[] cur=new int[]{r0,c0};
        ansAL.add(cur);
        while(ansAL.size()<ttl){
            cur=nxtCell(cur[0],cur[1],r0,c0);
            if(0<=cur[0]&&cur[0]<R&&0<=cur[1]&&cur[1]<C){
                //該點符合預期範圍，加入清單中
                ansAL.add(cur);
            }
        }
        return ansAL.toArray(new int[ansAL.size()][2]);
    }
}
```
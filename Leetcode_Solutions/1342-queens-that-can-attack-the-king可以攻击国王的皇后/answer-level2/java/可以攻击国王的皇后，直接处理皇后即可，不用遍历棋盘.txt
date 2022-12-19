### 解题思路
可攻击国王的皇后有8个方向：上、下、左、右、左上、右上、左下、右下，这种皇后和国王在坐标上的关系是x坐标相同或y坐标相同或者x、y坐标差值绝对值相等。所以直接根据皇后的坐标可判断是否可攻击国王，再在8个方向上取离国王最近的皇后即可。

草稿型代码，可再优化下空间复杂度

### 代码

```java
class Solution {
    public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
        int[][] eqs=new int[8][2];//上、下、左、右、左上、右上、左下、右下 最多8个
        for(int i=0;i<8;i++){
            eqs[i][0]=-1;
            eqs[i][1]=-1;
        }
        for(int i=0;i<queens.length;i++){
            int[] q=queens[i];
            if(q[0]==king[0]&&q[1]<king[1]){//上
                eqs[0][0]=king[0];
                eqs[0][1]=Math.max(q[1],eqs[0][1]);
                continue;
            }
            if(q[0]==king[0]&&q[1]>king[1]){//下
                eqs[1][0]=king[0];
                eqs[1][1]=eqs[1][1]==-1?q[1]:Math.min(q[1],eqs[1][1]);
                continue;
            }
            if(q[1]==king[1]&&q[0]<king[0]){//左
                eqs[2][1]=king[1];
                eqs[2][0]=Math.max(q[0],eqs[2][0]);
                continue;
            }
            if(q[1]==king[1]&&q[0]>king[0]){//右
                eqs[3][1]=king[1];
                eqs[3][0]=eqs[3][0]==-1?q[0]:Math.min(q[0],eqs[3][0]);
                continue;
            }
            if(Math.abs(q[0]-king[0])==Math.abs(q[1]-king[1])){//对角方向
                if(q[0]<king[0]&&q[1]<king[1]){//左上
                    eqs[4][0]=Math.max(q[0],eqs[4][0]);
                    eqs[4][1]=Math.max(q[1],eqs[4][1]);
                }
                if(q[0]>king[0]&&q[1]<king[1]){//右上
                    eqs[5][0]=eqs[5][0]==-1?q[0]:Math.min(q[0],eqs[5][0]);
                    eqs[5][1]=Math.max(q[1],eqs[5][1]);
                }
                if(q[0]<king[0]&&q[1]>king[1]){//左下
                    eqs[6][0]=Math.max(q[0],eqs[6][0]);
                    eqs[6][1]=eqs[6][1]==-1?q[1]:Math.min(q[1],eqs[6][1]);
                }
                if(q[0]>king[0]&&q[1]>king[1]){//右下
                    eqs[7][0]=eqs[7][0]==-1?q[0]:Math.min(q[0],eqs[7][0]);
                    eqs[7][1]=eqs[7][1]==-1?q[1]:Math.min(q[1],eqs[7][1]);
                }
            }
        }
        List<List<Integer>> ans=new ArrayList();
        for(int i=0;i<8;i++){
            if(eqs[i][0]!=-1){
                List<Integer> a=new ArrayList();
                a.add(eqs[i][0]);
                a.add(eqs[i][1]);
                ans.add(a);
            }
        }
        return ans;
    }
}
```
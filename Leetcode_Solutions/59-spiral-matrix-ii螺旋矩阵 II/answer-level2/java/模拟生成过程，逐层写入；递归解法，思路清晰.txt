![11.bmp](https://pic.leetcode-cn.com/ca1d81544d1f4862ef91080db3c6aa523493e0d50d56b6bfbe97e00350f39a7c-11.bmp)

n=4和n=5的两种情况，可以看出可以逐层填数，递归终止条件是1核和4核两种

![22.bmp](https://pic.leetcode-cn.com/023ac7c427df8bdc5c1ecf1a20f1c33a947819778a6a9bb6333c5e59c9218ba9-22.bmp)

坐标的走法是顺时针，n=5时，最外层一段走4个，然后换方向；找规律写出坐标映射就行。


![33.bmp](https://pic.leetcode-cn.com/6a767c391c567bbec5978594a3ea4b9771a8611e845fa5345a1dd786675e5cfa-33.bmp)

运行速度还可以




```
class Solution {
    private int[][] ans;
    private int n;

    private void insert(int init, int layer){
        // 1核，4核的结束条件
        if(init == n*n + 1) return;
        if(init == n*n){
            ans[layer][layer] = init;
            return;
        }
        // 一圈要放 (n - 2*layer)*4 - 4个数
        // 这圈的边长是n - 2*layer，可以放4个(n-2*layer)-1
        int i = init;
        int x = layer, y = layer;
        for(int j = 0; j < (n-2*layer)-1; ++j){
            ans[x][y++] = i++;
        }
        for(int j = 0; j < (n-2*layer)-1; ++j){
            ans[x++][y] = i++;
        }
        for(int j = 0; j < (n-2*layer)-1; ++j){
            ans[x][y--] = i++;
        }
        for(int j = 0; j < (n-2*layer)-1; ++j){
            ans[x--][y] = i++;
        }
        insert(i, layer+1);
    }

    public int[][] generateMatrix(int n) {
        if(n==1) return new int[][]{{1}};
        this.ans = new int[n][n];
        this.n = n;
        insert(1, 0);
        return ans;
    }
}
```

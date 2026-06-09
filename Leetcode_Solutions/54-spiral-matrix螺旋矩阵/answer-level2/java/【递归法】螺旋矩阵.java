思路：
1、使用递归思想，每次顺时针走一个h*w矩阵的最外圈。
2、递归结束条件是h==1或w==1。如下h=1，w=1只需顺时针旋转一下就OK。
![image.png](https://pic.leetcode-cn.com/251307025d92f2c36c3736da62893d12dbb61a4a5ea2631db9279bce51f6a6be-image.png)

3、四边用四个循环走完，四个循环内各自处理的方块如下所示：
![image.png](https://pic.leetcode-cn.com/e24dd1372f1a6f788e192e8a41a96df3097dd118ad2789ffd9066546ae2f958b-image.png)

4、递归结束时只剩最后一行或者一列，如果使用同样代码，会导致来回重复。因此单独处理，判断如果h==1则从左到右，如果w==1，则自上而下顺序加入列表。

5、下一轮递归，因为四周已处理过，减去上下左右的边，后待处理的矩阵w和高h都变小2。
![image.png](https://pic.leetcode-cn.com/32390ad7cda36ef25276d06e8f51708985fa76f944e5e0a1f0ba78124821d2fb-image.png)

6、每一轮的四角定位可由当前轮的宽w和高h，与矩阵自身的宽n和高m，经平均值计算公式获取。
7、对于递归中不变的占内存的参数，使用公共变量代替，以减少内存的损耗
```
class Solution {
    private static List<Integer> ans;
    private static int[][] myMatrix;

    public static List<Integer> spiralOrder(int[][] matrix) {
        int h = matrix.length;
        int w = 0;
        if(h>0){
            w = matrix[0].length;
        }
        ans = new ArrayList<>();
        myMatrix = matrix;
        getEdge(w, h, h, w);
        return ans;
    }

    public static void getEdge(int w, int h, int m, int n){
        if(w==0||h==0){
            return;
        }
        int i_start = (m-h)/2;
        int i_end = (m+h)/2;
        int j_start = (n-w)/2;
        int j_end = (n+w)/2;
        if(w==1 || h==1){
            if(h==1){
                int middle = m/2;
                for(int j=j_start;j<j_end;j++){
                    ans.add(myMatrix[middle][j]);
                }
            }else{
                int middle = n/2;
                for(int i=i_start;i<i_end;i++){
                    ans.add(myMatrix[i][middle]);
                }
            }
            return;
        }
        for(int j=j_start;j<j_end-1;j++){
            ans.add(myMatrix[i_start][j]);
        }
        for(int i=i_start;i<i_end-1;i++){
            ans.add(myMatrix[i][j_end-1]);
        }
        for(int j=j_end-1;j>j_start;j--){
            ans.add(myMatrix[i_end-1][j]);
        }
        for(int i=i_end-1;i>i_start;i--){
            ans.add(myMatrix[i][j_start]);
        }
        getEdge(w-2, h-2, m, n);
    }
}
```


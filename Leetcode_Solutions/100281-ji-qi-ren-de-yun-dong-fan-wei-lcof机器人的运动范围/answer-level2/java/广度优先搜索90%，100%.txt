思路写在注释中，然后如果需要提交请自行去掉static，main函数
```
package leetCodeTest;

public class Solution {
    public static void main(String[] args) {
        int m = 3, n = 1, k = 0;
        int i = movingCount(m, n, k);
        System.out.println("i = " + i);
    }
    private static int count = 0;//用来存储机器人行动的距离

    /**
     * 思路：
     * 首先根据题意需要一个计算行坐标和列坐标的数位之和的方法，
     * 然后由于该题需要知道机器人的行走情况，所以可以得知我们
     * 需要遍历所有机器人有可能走过的点，由此可以得知我们需要
     * 一个二维数组存储所有的点，然后对这个二维数组进行广度优
     * 先搜索，并且按照题目要求过滤掉不能走的点，即可得到最佳的结果。
     * @param m
     * @param n
     * @param k
     * @return
     */
    public static int movingCount(int m, int n, int k) {
        int[][] ma = new int[m][n];//使用m,n构造二维数组
        coun(ma,0,0,k);//调用广度优先搜索的函数
        return count;
    }

    /**
     * 广度优先搜索的函数
     * @param nums
     * @param i
     * @param j
     * @param k
     * @return
     */
    public static int coun(int[][] nums,int i,int j,int k){
        //如果行列坐标超限或者当前位置为一或者行坐标和列坐标的数位之和大于k就退出递归
        if (i>=nums.length||j>=nums[0].length|| !sumcount(i,j,k) || nums[i][j]==1){
            return 0;
        }else {
            count = count + 1;
            nums[i][j] = 1;
        }
        //分别搜索下侧与右侧（因为从左上角开始所以只搜索右侧和下侧即可得到所有结果）
        coun(nums, i+1, j, k);
        coun(nums, i, j+1, k);
        return 0;
    }

    /**
     * 此函数用于判断当前位置的行坐标和列坐标的数位之和是否小于等于k
     * @param a
     * @param b
     * @param k
     * @return
     */
    public static boolean sumcount(int a,int b,int k){
        int count = 0;
        while (a != 0 || b != 0){
            count += a%10;
            a = a/10;
            count += b%10;
            b = b/10;
        }
        return count <= k;
    }
}

```

/**
 * Project:
 * Author : zhaozhen
 * Email  : 2399144252@qq.com
 * Date   : 2019/8/26
 *
 * 解题思路：不多讲 并查集
 */

```
public class leetcode547 {


    final int MAX = 256;
    int[] bin = new int[MAX];

    /**
     * 初始化 默认每一个的root都是自己 独立成为一个集合
     */
    public void init(){
        for(int  i = 1; i < MAX ; i++){
            bin[i] = i;
        }
    }

    /**
     * 查找跟老大根节点
     * @param x
     * @return
     */
    public int findroot(int x){

        int i = x;
        while(bin[i] != i){
            i = bin[i];
        }

        //路径压缩算法
        int j = x;
        while(bin[j] != i){
            int t = bin[j];
            bin[j] = i;
            j = t;
        }
        return i;
    }

    /**
     * 将两个节点合并为同一个节点 随机定义一个老大root (y的老大)
     * @param x
     * @param y
     */
    public void merge(int x , int y){
        int x_root = findroot(x);
        int y_root = findroot(y);
        if(x_root != y_root){
            bin[x_root] = bin[y_root];
        }
    }

    public int findCircleNum(int[][] M) {
        //初始化
        init();
        for(int i = 0; i < M.length; i++){
            for(int  j = i + 1; j < M.length;j++){
                if(M[i][j] == 1){
                    merge(j + 1,i + 1);
                }
            }
        }

        int count = 0;
        for(int i = 1; i < M.length + 1 ; i ++){
            if(bin[i] == i){
                count ++;
            }
        }
        return count;
    }

    //[[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]
    public static void main(String[] args) {
        leetcode547 leetcode547 = new leetcode547();
        leetcode547.findCircleNum(new int[][]{{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}});
    }
}
```

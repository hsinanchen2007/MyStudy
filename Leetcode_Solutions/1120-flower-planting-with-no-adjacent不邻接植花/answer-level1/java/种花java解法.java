首先给大家看一下执行的结果：
        执行用时 :16 ms, 在所有 Java 提交中击败了94.89% 的用户
        内存消耗 :54.5 MB, 在所有 Java 提交中击败了100.00%的用户
具体思路是这样的：
        如果没有花园是想通的，那么我们每一个花园种第一种花即可。
        我们创建一个长度为N+1的result数组（是的，我用的是N+1），每个元素是长度为五的数组，其中0号元素记录有多少个花园相邻，123号元素存放相邻的花园，4号元素来放需要种植的花的种类（用1、2、3、4表示）。
        下一步来遍历paths数组，没遍历一次，把相互相邻的两个花园记录到result数组中
        完了之后来遍历result数组种花，每次种花都从1到4依次查询，看有没有相邻的花园已经种了
        种完花就可以返回结果了。
具体代码如下，可能有点乱：
```
 class Solution {
    public int[] gardenNoAdj(int N, int[][] paths) {
         if (paths.length==0){//如果没有花园相通
            int []result=new int[N];
            for (int i = 0; i <N; i++) {
                result[i]=1;
            }
        }
        int [][]result =new int[N+1][5];//每个位置维持一个5个长度的数组，第一个位置存放有多少个相邻花园，最后一个位置放花的种类
        for (int i = 0; i <paths.length; i++) {//先遍历 ，把相邻位置放进去
            result[paths[i][0]][0]++;//增加一个相邻花园
            result[paths[i][1]][0]++;//增加一个相邻花园
            result[paths[i][0]][ result[paths[i][0]][0]]=paths[i][1];//把相邻花园放进去
            result[paths[i][1]][ result[paths[i][1]][0]]=paths[i][0];//把相邻花园放进去
        }
        for (int i = 1; i <=N; i++) {//遍历每一个花园
            for (int j = 1; j <=4 ; j++) {//遍历决定放哪一种花
                int k=0;//定义在外面，好判断进行到哪了
                for (k = 1; k <4 ; k++) {//看这个花有没有相邻花园使用
                    if(result[result[i][k]][4]==j)break;//
                }
                if (k==4){
                    result[i][4]=j;
                    break;
                }
            }
        }
        int []result2=new int[N];//真正的结果
        for (int i = 0; i <N; i++) {
            result2[i]=result[i+1][4];
        }
        return result2;   
    }
}
```


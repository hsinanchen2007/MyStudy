表面积表面积，顾名思义，表层的面积。 我这个思路用左面积+右面积+上下面积来解。

大家脑子里想象一个[[1,2]]的模型 (虽然题目要求是N*N网格,我的思路适用于(x*y)网格,更具有普遍性),然后我们假设自己是一个小乌龟位于(0,0)左边的位置，从模型的左视图开始往右边爬,目的地是刚好爬过模型到达模型(0,1)右边的位置.爬过的路径就是包含顶部面积的左右面积。因为grid(0,0)=1,所以第一步小乌龟从左到右向上爬1个单位,因为grid(0,1)=2,乌龟还需爬(2-1)=1个单位才能到达(0,1)的顶部,之后再从(0,1)爬下来,爬行2个单位,这样从左到右一共爬了4个单位,4正是左右表面积。如下图所示方便理解。
![131585109318_.pic.jpg](https://pic.leetcode-cn.com/814779be7e26f47cc7d344f18c101b38dd36fb61dfde2da742611cb89c05f316-131585109318_.pic.jpg)
![141585109319_.pic.jpg](https://pic.leetcode-cn.com/a31dab94fc36ac312d9bae49634af745da6e356ab8ca090cc5787a66436e107b-141585109319_.pic.jpg)
然后乌龟再从后往前爬,得到前后的表面积。

更普遍的是,比如我们爬的路径是(0,0)->(0,1)->(0,2)->...->(0,grid[0].length()-1).


然后瞬间移动到(1,0),接着(1,0)->(1,1)->....(1,grid[1].length()-1).

一直这样循环遍历，到(grid.length()-1,0)->.....(grid.length().grid(i).length()-1).

这样小乌龟就爬遍了从左右+顶部。

再接着从(0,0)开始,从后往前爬. (0,0)->(1,0)->...(grid.length-1,0)......这样得到的是前后+顶部。

高度差就是爬过得单位表面积的个数(除顶部)

我们先不管顶部,只记录左右和前后表面积,在循环遍历中记录grid(i,j)!=0的个数就是顶部表面积。
```
class Solution {
    public int surfaceArea(int[][] grid) {
        int zuodaoyou=0,shangdaoxia=0,yigongjige=0;//从左到右，从上到下（从后到前）,///一共几个顶部面积

//从左到右爬
        for (int i = 0;i<grid.length;++i){
            for (int j=0;j<grid[0].length;++j){
                if (grid[i][j]!=0)yigongjige++;//记录顶部面积
                if (j==0){//从底部刚开始爬
                    zuodaoyou+=grid[i][j];
                    if(j==grid[0].length-1){
                        zuodaoyou+=grid[i][j];
                    }
                }else {//站在一定的高度接着爬一个高度差
                    zuodaoyou+=Math.abs(grid[i][j]-grid[i][j-1]);
                    if(j==grid[0].length-1){
                        zuodaoyou+=grid[i][j];
                    }
                }

            }
        }
//从后到前爬（这里偷懒直接复制从左到右爬，由于是N*N的,所以直接调换成grid(j,i)即可）
        for (int i = 0;i<grid.length;++i){
            for (int j=0;j<grid[0].length;++j){
                if (j==0){//从底部刚开始爬
                    shangdaoxia+=grid[j][i];
                    if(j==grid[0].length-1){
                        zuodaoyou+=grid[j][i];
                    }
                }else {//站在一定的高度接着爬一个高度差
                    shangdaoxia+=Math.abs(grid[j][i]-grid[j-1][i]);
                    if(j==grid.length-1){
                        zuodaoyou+=grid[j][i];
                    }
                }
            }
        }
        return zuodaoyou+shangdaoxia+2*yigongjige;//两倍别忘了底部面积
    }
}
```

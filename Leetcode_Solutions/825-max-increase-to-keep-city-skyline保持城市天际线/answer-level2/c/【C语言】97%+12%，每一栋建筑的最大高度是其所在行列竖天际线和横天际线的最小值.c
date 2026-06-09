### 解题思路
1.思路：
（1）先用遍历的方法，求出各列和各行的最大值。
（2）再次遍历整个数组：每一栋建筑的最大高度是其所在行列竖天际线和横天际线的最小值。
2.corner condition：
（1）.没有什么特殊的corner condition；
3.知识点总结：
（1）.尽量用IDE的联想功能，可以有效降低因为打字笔误到时后期的编译错误排查时间，本次调试在printf上竟然耗费了几次排查时间。----利用IDE的标识符联想功能提升效率。
（2）.分步骤，病分步骤确认每一个步骤的编码都是正确的。例如，本题可以分为两个主要步骤，一个是求各行各列的最大值，然后是求增量大小。那么在完成第一个步骤时，先打印确认所求各行各列的最大值是正确的。然后再进行下一步。这个方法尤其在算法比较复杂的时候，能够大大降低后面排错的低效。------步步为营、稳扎稳打。
（3）对于copy paste的代码，paste后，要仔细核对每一处是否正确，如果有一处错误遗留到后面编译或运行用例后再排错，那么效率非常低，将耗费很多时间。例如本题在求udmax时的代码，即从lrmaxcopy而来改动的。这次做的比较好，一次性编译通过。------copy paste小心修改。
4.耗时：35mins，比较满意~。主要耗时点：
（1）知识点一中提到的printf的笔误，耽误了点时间-----经验；
![image.png](https://pic.leetcode-cn.com/aafde29496cb97a6865ec8057417013dee1c9ae6664b36192b8951bda4971059-image.png)


### 代码

```c
int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    int * lrmax = NULL;
    int * udmax = NULL;
    lrmax = (int *)malloc(gridSize * sizeof(int));
    memset(lrmax, 0x00 , gridSize * sizeof(int));
    udmax = (int *)malloc((*gridColSize) * sizeof(int));
    memset(udmax, 0x00 , (*gridColSize) * sizeof(int));
    int i = 0;
    int j = 0;
    int addsum = 0;
    /*get lrmax and udmax*/
    for(i = 0; i < gridSize; i++) {
        for(j = 0, lrmax[i] = grid[i][0]; j < *gridColSize; j++) {
            lrmax[i] = lrmax[i] > grid[i][j] ? lrmax[i] : grid[i][j];
        }        
    }
    for(j = 0; j < *gridColSize; j++) {
        for(i = 0, udmax[j] = grid[0][j]; i < gridSize; i++) {
            udmax[j] = udmax[j] > grid[i][j] ? udmax[j] : grid[i][j];
        }        
    }

    //printf("lrmax = {");
    //for (i = 0; i < gridSize; i++) {
    //    printf("%d,",lrmax[i]);
    //}
    //printf("}\n");
    //printf("udmax = {");
    //for (j = 0; j < *gridColSize; j++) {
    //    printf("%d,",udmax[j]);
    //}
    //printf("}\n");

    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < *gridColSize; j++) {
            addsum = addsum + (lrmax[i] < udmax[j] ? lrmax[i] : udmax[j]) - grid[i][j];
        }
    }
    //printf("addsum = %d\n",addsum);
    free(lrmax);
    free(udmax);
    return addsum;     


}
```
### 解题思路
一看题，这不就是数学上的规划题么，再一看纯整数摆明NLP问题连M都没有（MINLP---混合整数线性规划）
对于(混合)整数规划--->分支定界法，在想想自己连LP问题(线性规划算法是单纯形法)的解法都不会.....此时要能用MATLAB该多好(Python的规划库没咋用过应该也有)。。。。
so 暴力DFS(其实还可以加上间断操作(分支界定法的思想)，先找出一种可行方案，如果在DFS（没到叶子节点）时候花费的钱已经比方案多的话直接剪去这条线节省时间


### 代码

```c
int shoppingOffers(int* price, int priceSize, int** special, int specialSize, int* specialColSize, int* needs, int needsSize){
    int best=0;
    for (int i=0;i<needsSize;i++)
        best += needs[i]*price[i];
    void DFS(int index,int* residual,int money){
        if (index>=specialSize){
            int sum=0;
            for (int i=0;i<needsSize;i++)
                sum += price[i]*residual[i];
            if (money+sum<best)
                best = money+sum;
            return;
        }
        int max=0;
        for (int i=0;i<needsSize;i++)
            if (max<residual[i])
                max = residual[i];   
        for (int i=0;i<needsSize;i++){
            if (special[index][i]&&(max>residual[i]/special[index][i]))
                max = residual[i]/special[index][i];
        }
        if (max==0)
            DFS(index+1,residual,money);
        else{
            int *new_residual;
            new_residual = (int*)malloc(sizeof(int)*needsSize);
            for (int i=0;i<=max;i++){
                for (int j=0;j<needsSize;j++)
                    new_residual[j] = residual[j] - i*special[index][j];
                DFS(index+1,new_residual,money+i*special[index][needsSize]);
            }
        }
    }
    DFS(0,needs,0);
    return best;
}
```
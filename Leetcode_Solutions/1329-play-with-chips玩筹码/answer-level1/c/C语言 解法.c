### 解题思路
由题意当筹码移动偶数单位代价不变，移动奇数单位代价加1

那么便可以将所有奇数位筹码无代价移动到同一个奇数位上
同理偶数位置的筹码也可以无代价移动到同一个偶数位上
这样便只需要将少数筹码以每个1代价来移动到多数筹码的位置

### 代码

```c
int minCostToMoveChips(int* chips, int chipsSize){
    int even_num = 0; //偶数位置的筹码个数
    int add_num = 0;  //奇数位置的筹码个数
    int i=0;
    for(i=0;i<chipsSize;i++)
    {
        if(chips[i]%2 == 0)
        {
            even_num++;
        }
        else
        {
            add_num++;
        }
    }
    return even_num>add_num?add_num:even_num; // 代价就是偶数和奇数位置中的最小筹码数
}
```
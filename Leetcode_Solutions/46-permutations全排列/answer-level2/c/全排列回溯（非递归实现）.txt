算法介绍：

    对索引进行排列与对元素进行排列是等价的。由于索引的规则性强于元素，所以对索引值进行排列要容易一点。
    本算法就是对元素索引进行排列。由于本算法是对索引值进行全排列，所以本文所说的“元素”其实都是索引值。

    如果把索引的排列当成一个N位N进制数，那么就容易得到全排列的递推规则：下一次排列对应的数值必定比上一
    次排列大，而且满足最小增量原则。最小增量指的是数值变化量最少，能变动低位，就不要变动高位（左高右低）。

    将元素分为2部分，前半部分已排列好的称为被占用元素，剩下的没排列的元素称为闲置元素。
    “自增”：每次排列都是一次自增。每次自增都是从最低位开始。当某一位增加时，实际上就是从闲置元素里
            找到一个比它稍大的元素将其替代。剩下的闲置元素按照升序进行排列。
    “进位”：若是找不到合适的闲置元素，就将当前元素变为闲置元素，然后令前一位元素“自增”。

举例说明：

    现演示[0,1,2,3]的全排过程。
        被占用：0 1 2 3   闲置：
    3要自增，但找不到闲置元素，于是将3变为闲置元素，并令2自增
        被占用：0 1 2 _   闲置：3
    2要自增，现有比2大的最小闲置元素3，用3替代2。3的状态变为已占用，2的状态变为闲置
        被占用：0 1 3 _   闲置：2
    剩下的闲置元素按升序排列
        被占用：0 1 3 2   闲置：
    2要自增，但找不到闲置元素，于是将2的状态变为闲置，并令3自增
        被占用：0 1 3 _   闲置：2
    3要自增，但找不到比3大的闲置元素，于是将3的状态变为闲置，并令1自增
        被占用：0 1 _ _   闲置：2 3
    1要自增，现有比1大的最小闲置元素2，用2替代1。2的状态变为已占用，1的状态变为闲置
        被占用：0 2 _ _   闲置：1 3
    剩下的闲置元素按升序排列
        被占用：0 2 1 3   闲置:
    如此循环，完成全排列，当最高位无法向前进位时，终止循环。


代码实现：
```
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //待返回数据初始化
    *returnSize=1;
    for(int i=0;i<numsSize;i++){
        (*returnSize)*=i+1;
    }
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    int** returnNums = (int**)malloc(sizeof(int*)*(*returnSize));
    
    //indexes 记录元素索引
    int* indexes = (int*)malloc(sizeof(int)*numsSize);
    //hashSet 记录元素使用情况，若是某个元素被占用，其对应的hash值为1，否则为0
    int* hashSet = (int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++){
        indexes[i]=i;
        hashSet[i]=1;
    }
    

    //tail 尾指针(用于"进位"操作)
    int tail = numsSize-1;

    int count = 0;
    while(tail>=0){
        //记录排列
        (*returnColumnSizes)[count] = numsSize;
        returnNums[count] = (int*)malloc(sizeof(int)*numsSize);
        for(int i=0;i<numsSize;i++){
            returnNums[count][i]=nums[indexes[i]];
        }
        count++;
        

        int isReplace = false;
        int replaceByIndex = 0;
        while(tail>=0 && !isReplace){
            for(int i=indexes[tail]+1;i<numsSize;i++){
                //从闲置的元素中，查找替代项（即大于当前元素的最小闲置元素）
                if(!hashSet[i]){
                    isReplace = true;
                    replaceByIndex = i;
                    break;
                }
            }
             
            //把当前元素状态变为"闲置"
            hashSet[indexes[tail]]=0;
            
            if(isReplace){
                //如果找到合适的元素，就用该元素替代当前元素，并将替代元素状态置为"已占用"
                hashSet[replaceByIndex] = 1;
                indexes[tail] = replaceByIndex;
                //按照升序对剩下的闲置元素进行排列
                for(int i=0;i<numsSize;i++){
                    if(!hashSet[i]){
                        tail++;
                        indexes[tail]=i;    
                        hashSet[i]=1;
                    }
                }
            }else{
                //如果没找到合适的替代元素，就"进位"
                tail--;
            }
        }    
    
    }
    

    free(indexes);
    free(hashSet);
    return returnNums;
}
```

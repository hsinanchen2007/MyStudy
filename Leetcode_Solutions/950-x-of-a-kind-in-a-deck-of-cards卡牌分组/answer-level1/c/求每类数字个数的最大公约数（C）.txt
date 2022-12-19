### 解题思路
把有相同数字的卡牌数量找出来，再求这些数量的最大公约数。

### 代码

```c
//更相减损术
int gcd(int a,int b){
    while(a != b){
        if(a > b) a = a - b;
        else b = b - a;
    }
    return a;
}

//求nums中nums[low]到nums[high]的最大公约数
int Greatest_common_divisor(int* nums,int low,int high){
    if(low == high) return nums[low];
    if((high - low) == 1){
        return gcd(nums[low],nums[high]);
    }else{
        if((high - low) % 2 == 0){
            int temp = nums[high];
            return gcd(temp,Greatest_common_divisor(nums,low,high - 1));
        }else{
            int index = (low + high - 1) / 2;
            return gcd(Greatest_common_divisor(nums,low,index),Greatest_common_divisor(nums,index + 1,high));
        }
    }
}


bool hasGroupsSizeX(int* deck,int deckSize){
    int *types = (int*)malloc(sizeof(int)*2);
    types[0] = deck[0];
    types[1] = 1;
    int typesSize = 2;
    //计算每个数的数量
    for(int i = 1;i < deckSize;i++){
        int create = 1;
        for(int j = 0;j < typesSize;j += 2){
            if(deck[i] == types[j]){
                types[j + 1]++;
                create = 0;
            }
        }
        if(create == 1){
            typesSize += 2;
            types = (int*)realloc(types,sizeof(int)*typesSize);
            types[typesSize - 2] = deck[i];
            types[typesSize - 1] = 1;
        }
        
    }
    //压缩types大小，只存数量
    typesSize /= 2;
    for(int i = 0;i < typesSize;i++){
        types[i] = types[2 * i + 1];
    }
    types = (int*)realloc(types,sizeof(int)*typesSize);
    for(int i = 0;i < typesSize;i++) if(types[i] == 1) return false;
    if(Greatest_common_divisor(types,0,typesSize - 1) != 1) return true;
    return false;
}
```
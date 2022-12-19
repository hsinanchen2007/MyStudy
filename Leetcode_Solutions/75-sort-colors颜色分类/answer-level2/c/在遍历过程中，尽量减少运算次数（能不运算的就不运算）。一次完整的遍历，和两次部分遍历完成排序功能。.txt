### 解题思路
此处撰写解题思路

### 代码

```c
#define RED 0
#define WHITE 1
#define BLUE 2

void change(int *nums, int i, int j){
    int t;

    t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}

void sortColors(int* nums, int numsSize){
    int tail = 0, red = 0, white = 0, red1, white1;
    //int blue = 0, blue1;//这里不再记录蓝色信息

    if(1 == numsSize) return;

    while(tail < numsSize){
        if(RED == nums[tail]) red ++;
        else if(WHITE == nums[tail]) white ++;
        //else blue ++;//这里不再记录蓝色信息，只记录red和white已经足够
        tail ++;
    }
    
    //给red留下区域后，把其后边的红色都挪到红色区域
    red1 = 0;
    while(red1 < red && RED == nums[red1]) red1 ++;//找到red区域第一个非red
    for(tail = red; tail < numsSize; tail ++){//给red留下区域，并从其后开始找red
        if(RED == nums[tail]){
            change(nums, tail, red1);
            red1 ++;
        }
        while(RED == nums[red1]) red1 ++;
    }

    //这个与上边的思路是一致的
    white1 = red;
    while(white1 < red + white && WHITE == nums[white1]) white1 ++;
    for(tail = red + white; tail < numsSize; tail ++){
        if(WHITE == nums[tail]){
            change(nums, tail, white1);
            white1 ++;
            while(WHITE == nums[white1]) white1 ++;
        }
    }
    
    return;
}
```
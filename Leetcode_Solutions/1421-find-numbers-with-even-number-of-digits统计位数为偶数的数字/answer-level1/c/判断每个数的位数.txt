### 解题思路
判断每个数的位数
10~99
1000~9999
100000~999999
。。。。。。
每个循环增加100即可

### 代码

```c
int isBitsEvenNumber(int num){
    int count = 10;

    if(num < 10){
        return 0;
    }

    while(count < 1000000){
        if(num >= count && num < count*10){
            //printf("%d\n", num);
            return 1;
        }
        count *= 100;
    }

    return 0;
}


int findNumbers(int* nums, int numsSize){

    int count = 0;
    int i;

    for(i = 0; i < numsSize; i++){
        if(isBitsEvenNumber(nums[i])){
            count++;
        }
    }

    return count;
}
```
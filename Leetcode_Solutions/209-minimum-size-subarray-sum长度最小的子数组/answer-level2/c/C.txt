双指针
### 代码

```c
int minSubArrayLen(int s, int* nums, int numsSize){

    int i = 0;
    int j = 1;
    int count = 2;       //默认是两个数相加，所以count初始化为2
    int lastcount = 0;
    int sum = 0;

    while(i < numsSize - 1 && j < numsSize){

        if(nums[i] >= s || nums[j] >= s){   //有单个数字大于给定的值，返回1

            return 1 ;
        }

        if(count == 2){     //第一次累加

            sum = nums[i] + nums[j] + sum;
        }else{      //第一次之后的累加，只需要累加nums[j]

            sum = sum + nums[j];
        }
        

        if(sum >= s){    //若大于等于给定的值

            i++;        //i向右挪一位
            j = i + 1;      //j比i多一位

            if(lastcount == 0){ //这是第一次大于给定的值的时候

                lastcount = count;
            }
            if(count < lastcount){  

                lastcount = count;
            }
            
            count = 2;       //让count复位重新计数
            sum = 0;          //sum清零重新累加
        }else{                   //如果没有大于给定的值，就将j向右挪一位

            j++;
            count++;    //累加的个数也要相应的加1
        }
    }

    return lastcount;
}
```
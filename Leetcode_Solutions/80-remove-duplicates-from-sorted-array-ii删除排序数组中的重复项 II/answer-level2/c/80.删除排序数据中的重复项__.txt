### 解题思路
此处撰写解题思路
连续三指针扫描整个数组,细节见注释
### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int len=0;
    if(numsSize==0)
          return len;
    else if(numsSize==1)
          return len+1;
    else if(numsSize==2)
          return len+2;
    else{                                             /*原数组长度>=3时*/
         for(int i=0;i<numsSize-2;    ){
             if(nums[i]==nums[i+1]&&nums[i+1]==nums[i+2]){    //找到三个相同的数，将后续的值向前移一位；
                  for(int k=i+3;k<numsSize;k++){              //向前移1位
                     nums[k-1]=nums[k];
                  }
                  numsSize--;                                  //移位完成后，原数组长度减1
                                     //指针在原地扫描，防止出现三个以上相同的值(故for中没有改变i)
             } 
             else{                              //没有三个及三个以上数，指针便后移，长度加1
                  i++;                          //指针后移
                  len++;                        //新数组长度加1
            } 
         }
         return len+2;
    }
}
```
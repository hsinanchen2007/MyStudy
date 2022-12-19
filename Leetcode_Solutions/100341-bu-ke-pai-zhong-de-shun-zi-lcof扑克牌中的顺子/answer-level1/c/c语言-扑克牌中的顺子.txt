### 解题思路
执行用时 :4 ms, 在所有 C 提交中击败了33.33% 的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了100.00%的用户
用数组存储1--13出现的次数，从第一个出现次数不为0的数开始，看后边是否有连续的五个数，如果在这连续的五个数中，有一个数没有出现，就看是否有0，如果有0，就转化成这个数，0的次数-1,如果没有0，就说明不连续。

### 代码

```c
bool isStraight(int* nums, int numsSize){
     int a[14];
     int i,count=1,t;
     for(i=0;i<14;i++)a[i]=0;
     for(i=0;i<numsSize;i++){
         a[nums[i]]++;
     } 
     for(i=1;i<=13;i++){
         if(a[i]>0){
             t=i;
             break;
         }
     }
     for(i=t;i<=13;i++){
       if(a[i]>1)return false;
       if(a[i]==0){
           if(a[0]>0){
               a[i]=1;
               a[0]--;
           }
           else return false;
       }
       if(a[i]>0&&a[i-1]>0&&i>1)count++;
       if(count==5)return true;
     }
     return ;
}
```
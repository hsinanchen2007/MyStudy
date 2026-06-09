其实思路可以非常简单，想成把不等于给定数值的数组元素将原来的数组按顺序覆盖即可，（不要多纠结，哈哈）这样也可以保持原有的顺序。
计算返回长度也非常简单，覆盖了几次就返回多长的长度即可。

int removeElement(int* nums, int numsSize, int val){
 int i=0,j;//所谓的双指针？
 for(j=0;j<numsSize;j++)
 {
     if(nums[j]!=val)
       {nums[i]=nums[j];
       i++;
       }
 }
 return i;
}
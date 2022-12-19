### 解题思路
两个for循环用来查找两个数组相同的值，当找到相同的值时，通过将该值和nums3数组中的值比较来判断是否重复，若重复则通过break跳出该循环，忽略这次，当nums3没有和该值相同的数时，插入该值

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
  int i,j,z,temp,num = 0;
  int maxNum = nums1Size<nums2Size?nums1Size:nums2Size;
  int *nums3 = (int*)malloc(sizeof(int)*maxNum);
  for(i=0;i<nums1Size;i++){
      temp = nums1[i];
      for(j=0;j<nums2Size;j++){
          if(temp==nums2[j]){
            if(num==0){
              nums3[num]=temp;
              num++;}
            else{
                for(z=0;z<num;z++){
                    if(temp==nums3[z]){
                      break;
                    }
                }
                if(z==num){
                  nums3[num]=temp;
                  num++;
                }
            }
          }
      }
  }
  *returnSize = num;
  return nums3;

}
```

# 思路：
1. ![捕获4.PNG](https://pic.leetcode-cn.com/78753fa0d2957c94630ec38570081d5bc333a13f387ddc1ee82994fa5614ddc0-%E6%8D%95%E8%8E%B74.PNG)
1）利用stack的方式， hashing创建储存大于nums2中每个元素的数字
2）然后，hashing映射来找出大于nums1中元素的值

# **代码：**
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){

    int i, index = 0;
    int *stack = malloc(sizeof(int) * nums2Size),
        *returnarra = malloc(sizeof(int) * nums1Size);
    int *hashmapping = malloc(sizeof(int) * 10000);
        for(i = 0; i < 10000;i++){
            hashmapping[i] = -1;
        }
    

        for(i = 0; i < nums2Size;i++){
            if(index == 0){
                stack[index++] = nums2[i];
            }else{
                while(index > 0){
                    if(nums2[i] > stack[index - 1]){
                        hashmapping[stack[index - 1]] = nums2[i];
                        index--;
                    }else{
                        break;
                    }
                }
                stack[index++] = nums2[i];
            }        
        }

        for(i = 0; i < nums1Size;i++){
            returnarra[i] = hashmapping[nums1[i]];
        }

    free(hashmapping);
    *returnSize = nums1Size;
    return returnarra;
}
```

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){

    int *returnArray = (int *)malloc(nums1Size * sizeof(int)); // 储存结果的数组
    int *stack = (int *)malloc(nums2Size * sizeof(int)); // 栈
    int htblSize = 1000; // 暂时分配1000个int长度的内存给哈希表
    int *htbl = (int *)malloc(htblSize * sizeof(int)); // 一个简单的哈希表，用来映射每个元素的Next Greater Number，规则：htbl[a] = a's next greater number.
    int temp = -1;

    for (int i = 0; i < nums2Size; i++) { // 遍历nums2，找出每个元素的Next Greater Number

        if (nums2[i] >= htblSize) { // 如果哈希表容量小于所需大小，重新分配空间
            htblSize = nums2[i] + 100;
            htbl = realloc(htbl, htblSize * sizeof(int));
        }

        while(temp > -1 && nums2[i] > stack[temp]) { // 当栈不为空时，搜索当前栈中元素的next greater number
            htbl[stack[temp]] = nums2[i];
            temp--;
        }

        stack[++temp] = nums2[i];
    }

    while (temp > -1) { // 将栈中没有next greater number的元素对应哈希表中的位置置为-1
        htbl[stack[temp]] = -1;
        temp--;
    }

    for (int i = 0; i < nums1Size; i++){ // 搜索nums1中对应元素的next greater number
        returnArray[i] = htbl[nums1[i]];
    }
    *returnSize = nums1Size;
    free(stack);
    free(htbl);
    
    return returnArray;
}
```

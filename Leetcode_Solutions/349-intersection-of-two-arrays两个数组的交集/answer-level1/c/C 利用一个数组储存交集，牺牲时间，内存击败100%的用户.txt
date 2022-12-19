**1.先判断两个数组的长度是否为0，如果为0，则直接返回0；**
**2.申请一个新数组num，num的长度取最小数组的长度，遍历num1和nums2，找到相同的值，再遍历num里面判断这个值是否已经存入了，如果有，则继续遍历，没有就放入num中**

``` C
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if(!nums1Size || !nums1Size) {
        *returnSize = 0;
        return 0;
    }
    int min = nums1Size < nums2Size ? nums1Size : nums2Size;
    int *num = (int*)malloc(sizeof(int) * min);
    int count = 0;
    for(int i = 0; i < nums1Size; i++) {
        for(int j = 0; j < nums2Size; j++) {
            int flag =0;
            if(nums1[i] == nums2[j]) {
                for(int k = 0; k < min; k ++) {
                    if(num[k] == nums1[i])
                        flag = 1;
                }
                if(flag != 1)
                    num[count++] = nums1[i];
            }
        }
    }
    *returnSize = count;
    return num;
}
```


审题：
1、数组元素为整数，可以是正、负整数和0
2、数组长度n+1，数组每个元素大小范围[1, n]
3、数组只有一个重复的整数

要求：
1、不能改变原数组
2、只能使用额外O(1)空间
3、时间复杂度小于O(n*n)

根据审题的几点信息来看：
1、使用hash统计数组元素出现的次数；
2、循环中统计数组元素出现次数，即hash值
3、同时循环中对hash值进行判断，当hash值大于1时，记录当前的数组元素值，并结束循环

时间复杂度O(n), 空间复杂度O(1)
![EasyCapture2.bmp](https://pic.leetcode-cn.com/41ad3216a3d670448f93fda169932016631fbf178fbab7e87280fdba27e972af-EasyCapture2.bmp)

```
int findDuplicate(int* nums, int numsSize){
    int *hash = (int *)malloc(numsSize * sizeof(int));
    memset(hash, 0, numsSize * sizeof(int));
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        int temp = nums[i];
        hash[temp]++;
        if (hash[temp] > 1) {
            res = temp;
            break;
        }
    }
    return res;
}
```



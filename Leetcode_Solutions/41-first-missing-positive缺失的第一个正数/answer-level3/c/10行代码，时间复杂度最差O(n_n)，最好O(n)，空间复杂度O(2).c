### 解题思路
这个困难的题，感觉也不那么难：
1、初始化Min = 1；
2、查找数组里面有没有，如有++，从开头处重新查找；
3、优化的变体：查到后，可以与nums[min-1]交换，然后从num[min]处再重新查找，可以进一步优化时间复杂度，实测结果效果不明显。

1、2步的运行结果：
![无优化.jpg](https://pic.leetcode-cn.com/9eb7e3b85acb38a26fdf3a9eca429d62586c21e8b63104527b985a3d8cfa9aa3-%E6%97%A0%E4%BC%98%E5%8C%96.jpg)


按3优化后的结果：
![优化后.jpg](https://pic.leetcode-cn.com/8a15c431a4b491de42b29ff29e20c804c1400055e5724ea48348b1948f52c2d8-%E4%BC%98%E5%8C%96%E5%90%8E.jpg)


### 代码

无优化代码：
```c
int firstMissingPositive(int* nums, int numsSize){
    int min = 1;
    int i = 0;
    for(i=0;i<numsSize;i++){
        if(nums[i]==min){
            min++;
            i = -1;
        }
    }
    return min;
}
```
局部优化代码：
int firstMissingPositive(int* nums, int numsSize){
    int min = 1;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==min){
            min++;
            nums[i] = nums[min-2];
            nums[min-2] = min-1;
            i = min-2;
        }
    }
    return min;
}


# 思路：
第一种方法：
1）计算总和
2）用数列公式  - 总和
![image.png](https://pic.leetcode-cn.com/3718e9c8f920f3142dac4b573092ca023d256dadf78bc84f4fb74355a163d25e-image.png)

第二种方法：
1）边加边减

# 代码：
方法1：
```
int missingNumber(int* nums, int numsSize){
    int sum = 0, i;
    for(i = 0; i < numsSize; i++){
        sum  += nums[i];
    }
    return ((numsSize * (1 + numsSize))/2) - sum;
}
```
方法2：
```
int missingNumber(int* nums, int numsSize){
    int sum = 0, i;
    for(i = 1; i < numsSize + 1; i++){
        sum  +=  i - nums[i - 1] ;
    }
    return sum;
}

```
比如：例1       已知：0  1  2  4  5  6 =  18
         (下标 + 1)：1  2  3  4  5  6 = 21
           21  - 18  = 3
     例2：     已知： 0   1   2   4   5   6 = 18
       (下标 + 1)：  1   2   3   4   5   6 = 18
            18  - 18 = 0
     例3:     已知：  0   =  0
        (下标 + 1)：  1   =  1
            1 + 0= 1


![image.png](https://pic.leetcode-cn.com/3205a0d97622a2231064f6c7af1d4a27b71cffdc24fa564d7baa0311abd74b98-image.png)
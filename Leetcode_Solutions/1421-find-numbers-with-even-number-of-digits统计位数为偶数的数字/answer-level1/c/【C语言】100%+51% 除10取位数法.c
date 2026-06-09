### 解题思路
1.思路比较简单：对数组中的每个元素逐个除10取位数，然后判断位数是否为偶数，如果为偶数，则计数器count++。
2.corner condition：按照上述思路，这些情况都不影响计算。
（1）.元素中的值为0的情况；
（2）.元素中的值有前导零；
3.知识点总结：
没有什么特殊的知识点。
4.耗时：24mins，本来可以10mins搞定的。主要耗时点：
（1）每个元素while循环前忘了给j清零-----算法编码实现时，没有集中注意力吧所有准备条件都写好，注意力不集中。用于排错，多花了10mins；
![image.png](https://pic.leetcode-cn.com/c72b6fc332f1b06c328c0108693f6d574372558185523e36fb1862dec29be6d2-image.png)


### 代码

```c
int findNumbers(int* nums, int numsSize){
    int i = 0;
    int count = 0;
    int calc = 0;
    int j = 0;
    for(i = 0, j = 0; i < numsSize; i++) {
        calc = nums[i];
        j = 0;
        //printf("before: calc = %d\n",calc);
        while(calc) { 
            calc = (int)(calc / 10);
            j++;
        
        }
        //printf("j = %d\n", j);
        //printf("after: calc = %d\n",calc);
        if(j % 2 == 0) {

            count++;
            //printf("nums[%d] = %d is even and count = %d\n", i, nums[i], count);
        }
    }
    return count;
}
```
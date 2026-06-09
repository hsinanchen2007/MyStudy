### 解题思路
先对整个数组扫描一遍，找出nums[i] > nums[i+1]一共有几次。如果大于1次，那这个数组肯定无法通过一次调整某个元素使其成为非递减数列。如果0次，那数组本身已经是非递减数列，不用调整都行。如果出现了一次，那么需要考虑递减出现的位置（i和i+1）中，是调整i（我们称为高位hi）还是调整低位（我们称为low）的值可以使数组变为非递减数组。是否可调，还需要看高低位前后元素与高低位的比较。这时候，边界条件情况（corner condition）就比较多了，需要逐条判断。

本题个人认为难度应该是中等，因为要考虑的边界条件比较多，耗时比较长（解题时间大于2h），而且还是在系统提供的测试用例暗示下才逐渐找到各类边界条件，如果是正式考试或竞赛，测试用例都看不到，那估计就挂了~~~

time cost 和space cost并不算很出色，一般般吧

![image.png](https://pic.leetcode-cn.com/5b207debae6cd0ae5f7d75972d2c7fccf4188e1ccef7c06a18dbbf64554ba67c-image.png)


### 代码

```c
bool checkPossibility(int* nums, int numsSize){
    int i = 0;
    int j = 0;
    int count = 0;
    int hi = 0;
    int low = 0;
    bool ret = false;

    if(numsSize <= 2) {
        return true;
    }
    
    for(i = 0; i + 1 < numsSize; i++) {
        if (nums[i] > nums[i + 1])  {
            hi = i;
            low = i + 1;
            count ++;
            if(2 <= count) {
                ret = false;
                break;
            }
        }
    }

    if(count == 0) {
        return true;
    }

    //printf("hi = %d, low = %d, numsSize = %d\n",hi, low, numsSize);

    if(count == 1) {
        if(low == numsSize - 1) {
            ret = true;

        }
        else {
        
            if(nums[low] == nums[low + 1]) {
            //do_hi();
            if (hi == 0) {
                ret = true;
            }
            else {
                if (nums[hi - 1] == nums[hi]) {
                    ret = false;
                }
                else {
                    if (nums[hi - 1] > nums[low]) {
                        ret = false;
                    }
                    else {
                        ret = true;
                    }
                }
            }
        }
        else if (nums[low] < nums[low + 1]) {
            if (nums[hi] <= nums[low + 1]) {
                //do_low();
                ret = true;
            }
            else {
                    //do_hi();
                    if (hi == 0) {
                        ret = true;
                    }
                    else {
                        if (nums[hi - 1] == nums[hi]) {
                        ret = false;
                    }
                    else {
                        if (nums[hi - 1] > nums[low]) {
                            ret = false;
                        }
                        else {
                            ret = true;
                        }
                    }
            }
                                    
            }
        }
        }
    }

    return ret;
}
```
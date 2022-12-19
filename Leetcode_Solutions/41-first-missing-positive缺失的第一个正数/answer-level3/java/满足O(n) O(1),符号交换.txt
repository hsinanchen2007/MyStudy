这个题总的来说分的情况还挺多的，由于空间时间的限制，我们不能采用普通的方法，这个题解采用的理论是，缺失的正数不可能超过n，通过符号判定是否存在正数
总体分为以下几步：
1.如果数组中不包含1，直接返回1
2.包含1，我们将所有负数，0，以及大于n的数替换为1，
3.遍历数组，将nums[i]对应的值为索引的数字替换为-号，如果为-则不替换，如果nums【i】 == n,让nums【0】为-的
4.从1遍历数组，如果没有正数，则判断nums【0】是否正，如果是，则返回n
5.如果以上条件都不满足，返回n+1
```
public int firstMissingPositive(int[] nums) {

        //检查1时候存在数组数组中
        boolean isFlag = false;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1){
                //如果存在1，设置为有效
                isFlag = true;
            }
            if (nums[i] < 0 || nums[i] == 0 || nums[i] >n){
                nums[i] = 1;
            }
        }
        //如果存在1，需要进行遍历标记
        if (isFlag && nums.length == 1){
            return 2;
        }
        if (isFlag){
            for (int i = 0; i < n; i++) {
                //因为下标不能到n，所以如果值为n，改变nums【0】符号
                if (nums[i] == n || nums[i] == -n){
                    if (nums[0] > 0){
                        nums[0] = -nums[0];
                    }
                }
                else if (nums[i] > 0){
                    if (nums[nums[i]] > 0){
                        nums[nums[i]] = -nums[nums[i]];
                    }

                }else{
                    if (nums[-nums[i]] > 0){
                        nums[-nums[i]] = - nums[-nums[i]];
                    }

                }

            }

            for (int i = 1; i < n; i++) {

                if (nums[i] > 0){
                    return i;
                }
            }
            if (nums[0] > 0){
                return n;
            }
            return n+1;
        }
        return 1;
    }
```

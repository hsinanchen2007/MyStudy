### 解题思路
左边进，右边退，相等即返回
由于中心索引可以是所有有效下标呀，所以，这里：
（1）左侧指针从-1开始，左侧累加值初始为零
（2）右侧指针从1开始，右侧累加值初始为：数组之和减去首位值
循环体：
（1）若相等，则返回p+1
（2）否则，左指针右移，并累积到左侧值；右侧值减掉一个，同时右指针右移
另外，由于考虑到中心索引可能为len-1,所以循环体外需要再判断一次。

### 代码

```java
class Solution {
    public int pivotIndex(int[] nums) {
        if (nums==null||nums.length<3){
            return -1;
        }

        int left = 0;
        int right = 0;
        for (int i = nums.length-1;i>=1;i--){
            right+=nums[i];
        }

        int p = -1;
        int q = 1;
        while (q<nums.length){
            if (left==right){
                return p+1;
            }else {        //同进退
                p++;
                left+=nums[p];
                right-=nums[q];
                q++;
            }
        }

        if (left==right){
            return p+1;
        }

        return -1;
    }
}
```
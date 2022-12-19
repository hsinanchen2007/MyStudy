解题思路见题解

### 代码

```java
/**
 * 使用三个指针
 * [0,p1]表示0的范围
 * [p1+1,p2]表示1的范围
 * [p2+1, p3)表示2的范围
 * p3表示当前指针在的位置,要求p3小于n
 */

class Solution {
    public void sortColors(int[] nums) {
        int p1 = -1, p2 = -1, p3 = 0; // 初始的时候三个区间都为空，所以满足要求
        while(p3 < nums.length){
            int tmp = nums[p3];
            switch (tmp){
                case 0: nums[++p1]=0;
                        if(++p2>p1){
                            nums[p2]=1;
                        }
                        if(p3>p2){
                            nums[p3]=2;
                        }
                        p3++; break;
                case 1: nums[++p2]=1;
                        if(p3>p2){
                            nums[p3]=2;
                        }
                        p3++; break;
                case 2: nums[p3++]=2; break;
            }
        }
    }
}

```
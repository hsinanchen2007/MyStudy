### 解题思路
此处撰写解题思路
我的思路:
    红蓝黄的球表示的就是0，1，2，直接用比较排序算法

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++)
            {
                if(nums[i]>nums[j]){
                    int k=nums[i];
                    nums[i]=nums[j];
                    nums[j]=k;
                }
            }
        }
    }
}
```
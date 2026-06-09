### 解题思路
此处撰写解题思路
我的思路:
    先将数组进行从小到大排序，然后再遍历数组中的元素，只要不和下标相同的元素那么就直接返回这个小标
如果都返回那么说明都是存在的，那就直接返回这个数组的长度;
### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {

        for(int i=0;i<nums.length-1;i++){
            for(int j=i+1;j<nums.length;j++){
                if(nums[i]>nums[j]){
                    int t=nums[i];
                    nums[i]=nums[j];
                    nums[j]=t;
                }
            }
        }
      for(int i=0;i<nums.length;i++){
          if(i!=nums[i]){
              return i;
          }
        }
        return nums.length;
    }
}
```
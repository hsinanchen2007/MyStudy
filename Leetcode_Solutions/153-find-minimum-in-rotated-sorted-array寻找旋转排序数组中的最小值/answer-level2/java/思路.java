### 解题思路
此处撰写解题思路
我的思路:
    为了防止出现负数进行排序的话，这里的Min赋值为最大的数，就是为了防止出现负数的情况；
每一个遍历的值和这个min进行比较，如果小于的话就直接赋值，不小于的话就继续往后遍历
最后返回的就是min;
### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        int min=10000000;
        for(int i=0;i<nums.length;i++){
            if(nums[i]<min){
                min=nums[i];
            }
        }
        return min;
    }
}
```
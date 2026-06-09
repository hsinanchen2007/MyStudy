### 解题思路
一次遍历，同时记录出到i处为止0的个数，然后将i处的值按有多少个0向前拷贝

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int index=0;
        for (int i=0;i<nums.length;i++){
            if (nums[i]==0){
                index++;
            }
            else{
                nums[i-index]=nums[i];
                if (i!=i-index) nums[i]=0;
            }
        }
    }
}
```
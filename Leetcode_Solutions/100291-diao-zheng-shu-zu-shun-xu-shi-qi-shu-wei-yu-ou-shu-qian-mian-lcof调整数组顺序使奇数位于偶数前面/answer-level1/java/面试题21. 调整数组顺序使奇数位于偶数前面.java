### 解题思路
首尾指针，前面找到偶数就暂停，后面指针去找奇数，找到就交换位置，以此类推。

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        if(nums.length<=1)return nums;
        int First=0;
        int Last=nums.length-1;
        while(First<Last){
            if(nums[First]%2==0){
                int temp=nums[First];
                while(First<Last&&nums[Last]%2==0)Last--;
                nums[First]=nums[Last];
                nums[Last]=temp;
            }
            First++;
        }
        return nums;
    }
}
```
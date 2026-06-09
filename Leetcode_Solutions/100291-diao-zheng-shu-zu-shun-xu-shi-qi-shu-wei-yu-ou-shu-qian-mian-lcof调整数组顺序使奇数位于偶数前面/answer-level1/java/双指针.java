### 解题思路
此处撰写解题思路
双指针法：指针i在数组头，一个指针j在数组尾，nums[i]是奇数就不互换，往后移动i，nums[i]是偶数就看nums[j]，nums[j]是奇数就互换，是偶数就往前移动j。
### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int i=0;
        int j = nums.length-1;
        while(i<j){
            if(nums[i]%2==0){
                if(nums[j]%2!=0){
                    int a = nums[i];
                    nums[i] = nums[j];
                    nums[j] = a;
                    i++;
                    j--;
                }
                else j--;
             }
            else   i++;
        }
        return nums;
    }
}
```
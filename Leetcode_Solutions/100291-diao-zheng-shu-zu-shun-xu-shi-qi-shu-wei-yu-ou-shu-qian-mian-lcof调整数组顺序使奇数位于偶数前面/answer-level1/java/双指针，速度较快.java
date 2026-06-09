### 解题思路
思路比较简单，新建一个数组来存储答案，然后遍历原数组找出奇数从开头放置，找到偶数放在数组的尾部。

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int i,start = 0,end = n - 1;
        for(i = 0;i<n ;i++){
            if(nums[i] % 2 == 0){
                ans[end] = nums[i];
                end--;
            }else{
                ans[start] = nums[i];
                start++;
            }
        }
        return ans;
    }
}
```
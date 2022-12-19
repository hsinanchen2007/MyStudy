### 解题思路
首先遍历数组，将每个数组的元素转化为字符串，再求字符串的长度，如果长度是偶数，则结果+1
### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int ans=0;
        for(int i=0;i<nums.length ;i++){
            if(String.valueOf(nums[i]).length()%2==0){
                ans++;
            }
        }
        return ans;
    }
}
```
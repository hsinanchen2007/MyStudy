### 解题思路
此处撰写解题思路
我的思路:
    通过一个统计的变量，然后循环这个数组的长度，判断这个数组中是否存在这个数字，如果存在
统计的变量累加，循环结束之后，就直接返回这个长度:
### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int len=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==target){
                len++;
            }
        }
        return len;
    }
}
```
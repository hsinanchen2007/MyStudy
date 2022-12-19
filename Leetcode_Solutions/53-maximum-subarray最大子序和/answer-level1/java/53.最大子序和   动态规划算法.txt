### 解题思路
此处撰写解题思路
    因为要找到最大的数值，我们可以这样分析 
    1：负数加上任何一个数值都比当前数值小，即 x + y < y, x为负数，y为任意一个数,
    由此当前面的连续数组值为负数的时候，我们就可以放弃，直接使用当前值来作为当前最大值；
    2：正数加上任何一个数值都比当前数值大，即 x + y > y, x为正数，y为任意一个数,
    由此当前面的连续数组值为正数的时候，我们就可以直接加上当前值，来作为当前最大值；
    3：每次获得当前最大值时，就用当前的最大值与记录的最大值做比较；

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int max = nums[0];
        int temp = max;
        for(int i = 1; i < nums.length; i++){
            if(temp > 0){
                temp += nums[i];
            }else{
                temp = nums[i];
            }
            if(temp > max){
                max = temp;
            }
        }
        return max;
    }
}
```
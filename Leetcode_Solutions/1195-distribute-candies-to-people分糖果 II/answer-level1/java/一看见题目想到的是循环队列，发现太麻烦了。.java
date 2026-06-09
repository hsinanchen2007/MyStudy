### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] nums = new int[num_people];
        int index = 1;
        //糖果数大于0，循环
        while(candies > 0){
            for(int i = 0; i < nums.length && candies > 0; i++){
                if(candies > index){
                    nums[i] += index;
                }else{
                    nums[i] += candies;
                }
                candies = candies - index;
                index++;
            }
        }
        return nums;
    }
}
```
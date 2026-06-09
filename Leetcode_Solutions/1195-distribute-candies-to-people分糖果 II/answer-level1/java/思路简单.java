### 解题思路
一次一次给

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] nums = new int[num_people];
        //  保存发糖果的个数（index+1），亦是数组下标 (index)%num_people;
        int index=0;    
        while(candies>0){
        	nums[(index)%num_people;] += candies>++index?index:candies;
        	candies-=index;
        }
        return nums;
    }
}
```
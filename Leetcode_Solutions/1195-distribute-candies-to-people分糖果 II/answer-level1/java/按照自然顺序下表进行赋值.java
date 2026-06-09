### 解题思路
是我想太多了 
这个解法效率极其低 本题不像个算法题

### 代码

```java

class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        //返回的数组
        int[] nums = new int[num_people]; 

        int i   = 1;//从数字1开始
        
        int sum = 0;

        while (sum <= candies) {
            sum += i;
            i++;
        }
        
        //System.out.println(i);

        for (int j = 1; j < i - 1; j++) {
            int index = (j - 1) % num_people;
            nums[index] += j;
        }

        //返回的剩余值
        int lastIndex = (i-2)%num_people;
        nums[lastIndex] += candies - (sum - i + 1);

        return nums;
    }
}
```
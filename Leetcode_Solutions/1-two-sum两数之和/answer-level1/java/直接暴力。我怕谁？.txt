### 解题思路
随机取两个不同下标的值。知道成功找到为止~~~~~看运气了

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int back[] = new int[2] ;
        int rand1,rand2;
        while (true){
            back[0] = (int)(Math.random()*nums.length);
            back[1] = (int)(Math.random()*nums.length);
            rand1 = nums[back[0]];
            rand2 = nums[back[1]];

            if (back[0] == back[1]) continue;
            if (target == (rand1 + rand2) ) break;

        }
        return back;
    }
}
```
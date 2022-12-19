### 解题思路
1. 从最后一个位置开始
2. 如果前一位的前一位的位置+能跳的步数 能跳过当前位置
3. 更新位置
4. 最后结果为0 那么说明可以到达起始点，说明是符合结果的
### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        int index = nums.length -1; //从最后一个位置开始
        for (int i = nums.length - 2; i >= 0; i --){
            if (nums[i] + i >= index){//如果前一位的前一位的位置+能跳的步数 能跳过当前位置
                index = i; //更新位置
            }
        }
        return index == 0;
    }
}
```
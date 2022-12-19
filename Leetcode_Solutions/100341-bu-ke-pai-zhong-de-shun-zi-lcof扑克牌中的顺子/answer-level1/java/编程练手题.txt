### 解题思路
编程练手题目，基本没有太多数据结构与算法的知识点。

### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        int max = 0;
        int min = 20;
        int zeroNum = 0;
        Set<Integer> nonZeroNum = new HashSet<Integer>();
        for(int x: nums){
            if(x != 0){
                max = max > x ? max : x;
                min = min < x ? min : x;
                nonZeroNum.add(x);
            }else{
                zeroNum += 1;
            }
        }
        // 最大值和最小值之间的差距小于等于4，同时0的数目和其他非重复的数目应该大于0
        if(max - min <= 4 && zeroNum + nonZeroNum.size() == 5){
            return true;
        }

        return false;
    }
}
```
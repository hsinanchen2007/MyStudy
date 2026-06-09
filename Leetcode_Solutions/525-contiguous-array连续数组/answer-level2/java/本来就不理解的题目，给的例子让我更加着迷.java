### 解题思路
解法是别人的
map中存放的是对于当前遍历中数据总和（0和1们这里吧0认为成-1）为key的value，这里的值即是当前位置的最大连续字串
### 代码

```java
class Solution {
    public int findMaxLength(int[] nums) {
     int max = 0;
        int len = nums.length;
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        map.put(0, -1);
        int sum = 0;
        for (int x = 0; x < len; x++) {
//1加一
            if (nums[x] == 1) {
                sum++;
//0减一
            } else {
                sum--;
            }
//如果map里面的sum的key是不是空，sum在1和0之间变换
            if (map.get(sum) == null) {
//如果空，也就是在map里面sum对应的value为空，就放上当前数组的下标
                map.put(sum, x);
//如果不空，变化max
            } else {
                max = Math.max(max, x - map.get(sum));
            }
        }  
        return max; 
    }
}
```
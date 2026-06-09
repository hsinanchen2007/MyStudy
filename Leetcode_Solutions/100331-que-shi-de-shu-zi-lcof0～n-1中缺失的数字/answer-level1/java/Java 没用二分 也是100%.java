有两个思路，第一个是比较弱的思路，一开始拿到题第一反应是map。
```java
class Solution {
    public int missingNumber(int[] nums) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }
        for (int i = 0; i <= nums.length; i++) {
            if (!map.containsKey(i)) {
                result = i;
            }
        }
        return result;
    }
}
```
第二个方法的思路不知道是不是清奇，因为好多人说二分。。。而我。。。。
```java
class Solution {
    public int missingNumber(int[] nums) {
        if (nums[0] != 0) return 0;
        int result = 0;
        boolean flag = false;
        for (int i = 0; i < nums.length && !flag; i++) {
            if (nums[i] != i) {
                result = i;
                flag = true;
            }
        }
    }
}
```
其实这个做题思路很单纯：
- 如果第一个元素不是0，那肯定是缺0，直接返回。
- 如果不缺0，那就意味着所有的数字都应该和自己的下标位置相同才对。
- 如果下标有多个不相同，意味着从第一个出现不相同下标的数组元素已经开始错位，那就输出第一个位置的数。  
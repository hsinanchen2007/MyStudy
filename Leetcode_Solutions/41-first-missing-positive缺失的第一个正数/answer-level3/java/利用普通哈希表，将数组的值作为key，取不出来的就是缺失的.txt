### 解题思路
请看代码和注释

### 代码

```java
    /**
     * 使用普通map就地解决法
     * 仍然需要使用双循环
     * 第一个循环，把数组的元素的值作为key放到哈希表中
     * 放入的条件必须是>0的数
     * 同时在放入数组元素的时候，记录一个最大值
     *
     * 第二个循环，以最大值为届，从1开始，循环+1比较
     * 如果遇到一个数，这个数从map里取不到值，那就是缺失的值
     *
     * 此种方法算是o(n)，但是利用了哈希表，所以……囧不知道算不算
     *
     * @param nums
     * @return
     */
class Solution {
    public int firstMissingPositive(int[] nums) {
        Map<Integer,Integer> map = new HashMap<>();
        // 定义一个最大值
        int max = 0;
        for(int i=0;i<nums.length;i++){
            // 小于0不放入哈希表
            if(nums[i] <= 0){
                continue;
            }
            map.put(nums[i],i);
            if(max < nums[i]){
                max = nums[i];
            }
        }
        // 从1开始找，找不到的就是缺失的
        int j=1;
        for(;j<=max;j++){
            if(map.get(j) == null){
                return j;
            }
        }
        return j;
    }
}
```
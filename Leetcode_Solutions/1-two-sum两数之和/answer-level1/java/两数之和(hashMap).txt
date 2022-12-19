### 解题思路
    借助hashMap查询时间复杂度的优势将每个数据遍历存储在其中，key为数据值，value为下标索引，插入之前比较差值，差值存在即返回；
    利用hash扰动寻找数组大小最近的2进制指数值，减少rehash

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> indexMap = new HashMap<>(getNum(nums.length));
        for (int i = 0; i < nums.length; i++) {
            int cal = target - nums[i];
            if (null != indexMap.get(cal)) {
                return new int[]{indexMap.get(cal),i};
            }else {
                indexMap.put(nums[i], i);
            }
        }
        return null;
    }
        public static int getNum(int a){
        int n = a -1;
        n |= n >>> 1;
        n |= n >>> 2;
        n |= n >>> 4;
        n |= n >>> 8;
        n |= n >>> 16;
        return n+1;
    }
}
```
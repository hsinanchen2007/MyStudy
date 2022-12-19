### 解题思路
temp[]数组的作用是先将nums[]排序，最后temp[]返回结果
排序后每个元素的索引为小于等于这个元素的元素数量，我们需要单独处理相邻元素相等的情况
只需要将相邻相等元素的value设为相等即可

### 执行结果
执行用时 ：4 ms, 在所有 Java 提交中击败了87.45%的用户
内存消耗 :41.4 MB, 在所有 Java 提交中击败了100.00%的用户


### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int n = nums.length;
        int[] temp = new int[n];
        temp = Arrays.copyOf(nums, n);
        Arrays.sort(temp);
        Map<Integer, Integer> map = new HashMap<>();
        map.put(temp[0],0);
        for(int i = 1; i < n; i++){
            if(temp[i] > temp[i-1]){
                map.put(temp[i],i);
            }
        }
        for(int i = 0; i < n; i++){
            temp[i] = map.get(nums[i]);
        }
        return temp;
    }
}
```
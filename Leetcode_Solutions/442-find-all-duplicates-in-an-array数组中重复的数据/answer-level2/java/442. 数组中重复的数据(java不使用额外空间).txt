遍历数组，使用HashMap计数的解法是很容易想到的。但这需要额外的O(n)的空间耗费。
如果我们的算法追求不使用额外空间，又要对数组中出现过的每个数进行计数。
那么我们自然可以联想到是否可以用数组本身作为HashMap使用呢？
题目条件中，数组中每个元素 1 <= a[i] <= len(a)使其成为了可能。
当索引为i的元素nums[i]-------------对应hashmap里的key  没有被访问过，
则用nums( nums[i] ) 对应的元素作为value，把它修改为负数：nums[index] = -nums[index]
```java []
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> result = new ArrayList<>();
        if(nums.length == 0){
            return result;
        }
        for (int i = 0; i < nums.length; i++){
            int index;
            index = Math.abs(nums[i]) - 1;
            if(nums[index] < 0){
                result.add(Math.abs(nums[i]));  //为啥是绝对值？防止nums[i]的值为负数
            }
            else{
                nums[index] = -nums[index];
            }
        }
        return result;
    }
}
```
```python []

```

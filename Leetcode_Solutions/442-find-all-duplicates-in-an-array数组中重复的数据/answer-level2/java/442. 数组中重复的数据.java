### 解题思路
原地修改数组，
类似于448题，
改变index=nums[i]-1索引处对应的值；
为了在访问原数组nums[i]-1处的值时进行还原, 做出的改变为 使其取反，这样在还原时，取绝对值即可；
对于原数组中重复出现的数，在改变相应索引对应值时，判断该值是否已经为负数，若是，表明重复，index+1即原数据，加入结果集。

### 代码

```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < nums.length; i ++){
            int index = Math.abs(nums[i]) - 1;
            if(nums[index] < 0){
                list.add(index + 1);
            }else{
                nums[index] *= -1;
            }
        }
        return list;
    }
}
```
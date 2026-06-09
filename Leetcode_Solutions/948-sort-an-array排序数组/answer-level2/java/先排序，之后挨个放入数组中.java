### 解题思路
先对数组进行排序，让其变为升序，之后创建集合，挨个添加到集合中

### 代码

```java
class Solution {
    public List<Integer> sortArray(int[] nums) {
        Arrays.sort(nums);
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0;i < nums.length;i++){
            list.add(nums[i]);
        }
        return list;
    }
}
```
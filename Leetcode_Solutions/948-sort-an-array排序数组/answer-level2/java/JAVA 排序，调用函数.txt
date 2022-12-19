### 解题思路
排序，调用函数，有点过分

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        Arrays.sort(nums);
        return nums;
    }
}
-------------------------------------------
class Solution {
    public int[] sortArray(int[] nums) {
        Arrays.sort(nums);
        int[] num = new int[(nums.length)];
        for(int i=0;i<nums.length;i++){
            num[i] = nums[i];
        }
        return num;
    }
}
-------------------------------------------
class Solution {
    public int[] sortArray(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            list.add(nums[i]);
        }
        Collections.sort(list);
        Integer[] num=list.toArray(new Integer[list.size()]);
        int[] num1 = new int[num.length];
        for(int i=0;i<num.length;i++){
            num1[i] = num[i];
        }
        return num1;
    }
}
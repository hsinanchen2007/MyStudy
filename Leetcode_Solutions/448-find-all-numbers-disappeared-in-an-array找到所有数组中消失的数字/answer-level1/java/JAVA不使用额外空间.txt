写完了看了下官方的题解，还是官方的写得好，不过我的这个也便于理解
第一遍从头遍历到尾，将元素放到对应的位置（nums[index]=index+1），如果当前索引值+1等于当前值，就继续下个元素，或者当前值等于要交换的值（索引值是当前位置值 - 1），继续处理下个元素，否则与对应位置交换
第二遍遍历交换后的数组，不满足nums[index]=index+1的就是丢失的
有点绕 直接上代码：
```
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        if (nums == null || nums.length == 0) {
            return Collections.emptyList();
        }
        int i = 0;
        while (true) {
            int swapIndex = nums[i] - 1;
            if (nums[i] == i + 1 || nums[swapIndex] == nums[i]) {
                i++;
            }else{
                nums[i] = nums[i] ^ nums[swapIndex];
                nums[swapIndex] = nums[i] ^ nums[swapIndex];
                nums[i] = nums[i] ^ nums[swapIndex];
            }
            if (i > nums.length -1) {
                break;
            }
        }
        List<Integer> result = new ArrayList<>();
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] != j + 1) {
                result.add(j + 1);
            }
        }
        return result;
    }
}
```

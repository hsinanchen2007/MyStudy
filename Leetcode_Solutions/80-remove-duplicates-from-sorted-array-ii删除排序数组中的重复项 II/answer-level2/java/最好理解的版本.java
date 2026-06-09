这道题和[27. 移除元素](https://leetcode-cn.com/problems/remove-element/)思路一致，即将有效的值一个一个向左移动，组成新的合法的数组。
```
public int removeDuplicates(int[] nums) {
    if (nums == null) return 0;
    if (nums.length <= 2) return nums.length;

    int idx = 1;//'新'数组的下标，该索引位置及其之前的元素都是符合题意的
    for (int i = 2; i < nums.length; i++) {//遍历'旧'数组的元素
        //如果'旧'数组中当前元素不同时和'新'的数组后两个元素相同 !(nums[i] == nums[idx] && nums[i] == nums[idx-1])
        if (nums[i] != nums[idx] || nums[i] != nums[idx - 1]) {
            nums[++idx] = nums[i];//则'旧'数组中的该值符合题意，将其添加至'新'数组末尾
        } else {
            //否则舍弃掉该非法值，继续遍历'旧'数组的下个元素
        }
    }
    return idx + 1;//最终返回有效索引+1即为'新'数组长度
}    
```

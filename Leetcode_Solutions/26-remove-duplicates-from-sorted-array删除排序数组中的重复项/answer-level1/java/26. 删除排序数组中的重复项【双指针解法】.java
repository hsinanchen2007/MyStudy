### 排序好的数组
```
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) {
            //处理空数据
            return 0;
        }
        //慢指针，用于存放相同key的索引位置
        int i = 0;
        //定义j从第2个开始起始，不断和i指针数据对比比
        for (int j = 1; j < nums.length; j++) {
            
            //因为是有序的数组，所以不相等了即可进行下一个数值的对比
            //实际nums[i] 就是之前赋值的nums[i+1]
            if (nums[j] != nums[i]) {
                //把下一个值赋值成下一个对比数据
                nums[i+1] = nums[j];
                i++;
                
            }
        }
        //因为从第一位起就应该算一个不重复数据
        return i + 1;
    }
}
```

### 非排序好的数组可使用Set
```
public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        Set<Integer> set = new HashSet<>();
        for (int j = 0; j < nums.length; j++) {
            //Set特性，不会存相同元素
            set.add(nums[j]);
        }
        return set.size();
    }
```
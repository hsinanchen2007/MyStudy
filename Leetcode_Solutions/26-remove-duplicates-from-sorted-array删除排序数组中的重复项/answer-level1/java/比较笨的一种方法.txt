

由左边开始，设置第一个是标记值，然后遍历寻找后面和标记值相同的值，如果找到，相同值的后面值依次前移一位，对比数组 长度减一。这样个方式想法简单，时间复杂度O(n^2)，但是最容易想出来




```
class Solution {
    public int removeDuplicates(int[] nums) {
        int count = nums.length;
        if(count <= 0) return 0;
        
        int key;
        for(int i = 0; i < count; i++){
            key = nums[i];
            for(int j = i+1; j < count; j++){
                if(key == nums[j]){
                    //发现相同元素，所有后面的元素前移一位
                    for(int p = j; p < count-1; p++){
                        nums[p] = nums[p+1];
                    }
                    count--;
                    j--; //由于后面元素前移了，还需要检验这个移过来的元素是否重复
                }
            }
        }
        
        return count;
    }
}
```

一个重要的条件：已排序好的数组。
然后是官方的解法，的确好，只需要遍历一遍。因为是已经排序好的，看例子得自是升序，所以重复的元素都是相邻的。只需要使用满指针指向需要插入的点，快指针依序遍历，发现不相等的元素，就插入到待插入的位置。

```
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length <= 0) return 0;
        int i = 0; //待插入的下标
        for(int j = 1; j < nums.length; j++){
            //知道找到不相等的，插入重复位置
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
            
        }
        return i+1;
    }
}
```


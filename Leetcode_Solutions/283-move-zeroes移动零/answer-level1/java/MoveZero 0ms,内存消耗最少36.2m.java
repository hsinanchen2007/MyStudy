# idea1
将左右的非零元素向前移动，最后把所有的零元素放到末尾。
```
public void moveZeroes(int[] nums) {
    //nums中非零元素的个数，也是零元素的开始插入位置。
    int nonZeroCount = 0;
    for (int num: nums) {
        if (num != 0) nums[nonZeroCount++] = num;
    }        

    while (nonZeroCount < nums.length) {
        nums[nonZeroCount++] = 0;
    }
}
```
# idea2
compare and swap 两个指针，第一个指针记录 第一个零元素的位置，第二个指针记录当前遍历的数组的位置，遇见非零元素，与第一个零元素交换位置。
```
 public void moveZeroes(int[] nums) {
       int i = 0;
        for(int j = 0 ;j < nums.length; j++){
            if(nums[j] != 0) {
                //i 与 j不想等就不交换，如果想省略代码可以省略这个判断。
                if(i != j ) {
                    exchange(nums,i,j);
                }
                i++;
            }
        }
 private void exchange(int[] nums, int i, int j) {
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
    }
 }

   


```

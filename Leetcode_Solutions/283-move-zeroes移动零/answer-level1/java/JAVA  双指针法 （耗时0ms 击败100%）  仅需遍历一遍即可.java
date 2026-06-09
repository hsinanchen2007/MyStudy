
```
public void moveZeroes(int[] nums) {       
    int j=0;    //j指针从头遍历，遇到0时停下，至到i指针指向大于0时交换
    for (int i = 1; i < nums.length; i++) {
        if(nums[j]!=0){ //不是0直接++
            j++;
            continue;
        }
        //来到这显然j是等于0，现在只要nums[i]不是0就将值赋予nums[j]，并将nums[i]置0
        if(nums[i]!=0){
            nums[j++]=nums[i]; //值换过后j++;
            nums[i]=0;
        }
    }
}
```
时间复杂度O(n)
空间复杂度O(1)


有点类似于荷兰国旗问题

荷兰国旗是将小于某个数的数放在他的左边，大于某个数的数放在数组右边，等于他的放在数组中间。

很类似的数组分块问题。

当`L`指向的数组为偶数时，和偶数左边界的第一个数交换，再判断交换之后的数的奇偶性。
```java
public int[] exchange(int[] nums) {
    if(nums == null || nums.length == 0){
        return nums;
    }

    int L = 0;
    int odd = -1; //代表奇数的左边界
    int even = nums.length; //代表偶数的右边界

    while(L < even){
        if((nums[L] & 1) == 1){
            odd ++;
            L ++;
        }else{
            swap(nums, L, --even);
        }
    }
    return nums;
}

//定义交换元素的函数
public void swap(int[] nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
```

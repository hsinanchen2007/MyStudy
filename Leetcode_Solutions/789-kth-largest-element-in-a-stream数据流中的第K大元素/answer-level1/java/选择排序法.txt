### 解题思路
1. 使用选择排序法，在构造函数1次排序
2. 然后在每次add的时候使用插入式排序
3. 复杂度在于每次插入排序仍然需要将后边的元素依次挪动
4. 比暴力法从700ms缩短到328ms
5. 效果有所提升，但是仍然难以满意

### 代码

```java
class KthLargest {

    private int[] nums;

    private int k;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        this.nums = nums;
        this.sort(this.nums);
    }

    public int add(int val) {
        int size = this.nums.length;
        int i=0;
        // 需要把新的val值插入到合适的位置
        for(;i<size;i++){
            if(val > this.nums[i]){
                break;
            }
        }

        this.nums = Arrays.copyOf(this.nums,size+1);
        int j=this.nums.length-1;
        while(j>i){
            this.nums[j] = this.nums[j-1];
            j--;
        }
        this.nums[j] = val;

        if(k>=this.nums.length){
            return this.nums[size];
        }else{
            return this.nums[k-1];
        }
    }

    // 效率较高的选择排序
    // 选到合适的就停止
    private void sort(int[] arr) {
        // 确定游标的位置
        // 游标是不断向后游走的
        // 游标是分隔着已经排好序和未排序的界限
        // 游标左侧是已经排好序的
        // 游标右侧是未排序仍然可以选择最（大）值的池子
        // 游标从0开始，意味着一开始整个数组都是被选择的池子
        // 游标达到数组的length的时候，计算结束
        int cursor = 0;

        // 游标只要跨过了合适的长度就停止
        while(cursor < arr.length){
            // 记录一个最大值
            int max = Integer.MIN_VALUE;
            // 记录当前最大值的脚标
            int j = cursor;
            // 从游标的右侧(剩余的池子)
            for(int i = cursor;i<arr.length;i++){
                // 如果找到了最大值
                if(arr[i]>max){
                    max = arr[i];
                    j = i;
                }
            }
            // 把max和当前的游标指向的元素交换位置
            // 这个地方可以优化
            // 如果cursor的值和j的值相等
            // 就可以避免一次交换
            // 即cursor == j 就不交换
            int temp = arr[cursor];
            arr[cursor] = max;
            arr[j] = temp;
            // 游标向右拨动一格，游标左侧就是排好序的
            cursor++;
        }
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```
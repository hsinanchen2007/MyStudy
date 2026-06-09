### 解题思路
1. 使用选择式排序，但是只选择前K个最大的
2. 整个数组前K（0～k-1）个数据区间是从大到小的有序排列，从K开始都是无序的
3. 新插入的元素和前K个比较，如果比前K个任意一个大，那么把前K个最小的逐出该数据区间，加入到整个数组最尾端
4. 如果没有，则将新的值放入到数组最尾端

请参考详细代码和注释

### 代码

```java
class KthLargest {

    private int[] nums;

    private int k;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        this.nums = nums;

        // 仅初始化最大的K个元素
        // 把游标左侧的作为最大K个元素的池子
        // 每当有元素进来的时候，如果比这个池子里的元素要大，那么就换掉这个元素
        // 把被换掉的元素放入到数组结尾
        // 比如
        // [4, 10, 2, 8, 0, 3, 9]，k=3
        // 初始化后
        // [10, 9, 8, | 4, 2, 0, 3]
        // 放入一个元素 11
        // [11, 10, 9, | 4, 2, 0, 3, 8]
        this.sort(this.nums,this.k);
    }

    // 最佳方法是维持一个额外的小数组，长度为K(实际这个小数组空间复杂度完全可以是o(1)，就是使用原来的数据插入排序的左侧部分）
    // 这个小数组保持着数组中最大的K个元素
    // 当有新元素进来的时候，如果新加入的元素比这个小数组的任意一个元素大
    // 则把这个小数组的最小值踢出去，重建这个小数组
    // 如果新加入的元素比这个小数组的任意一个元素都小，那就只复制到数组+1，其他操作不做
    public int add(int val){
        int size = this.nums.length;
        this.nums = Arrays.copyOf(this.nums,size+1);

        // 对于零数组的处理
        if(size == 0){
            this.nums = new int[1];
            this.nums[0] = val;
            return val;
        }

        // 不是零数组
        boolean evictedMin = false;
        for(int i=0;i<k;i++){
            if(val > this.nums[i]){
                // 把最小的那个驱逐出去
                this.nums[size] = this.nums[k-1];
                for(int j=(k-1);j>i;j--){
                    this.nums[j] = this.nums[j-1];
                }
                this.nums[i] = val;
                evictedMin = true;
                break;
            }
        }
        if(!evictedMin){
            // 没有驱逐过最小元素
            this.nums[size] = val;
        }

        // 要判断k值是否超过数组长度了
        if(k >= this.nums.length){
            return this.nums[this.nums.length-1];
        }

        return this.nums[k-1];
    }

    // 效率较高的选择排序
    // 选到合适的就停止
    private void sort(int[] arr, int len) {
        // 确定游标的位置
        // 游标是不断向后游走的
        // 游标是分隔着已经排好序和未排序的界限
        // 游标左侧是已经排好序的
        // 游标右侧是未排序仍然可以选择最（大）值的池子
        // 游标从0开始，意味着一开始整个数组都是被选择的池子
        // 游标达到数组的length的时候，计算结束
        int cursor = 0;

        // 游标只要跨过了合适的长度就停止
        if(len > arr.length){
            len = arr.length;
        }
        while(cursor < len){
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
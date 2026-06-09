
按照官方给的思路，自己写了一遍，想着容易，写着难，主要是在边界值的处理上会有很多坑

先找到旋转点，然后判断target处于那段，最后进行二分查找

1.查找旋转点
考虑特殊情况，即nums未升序，并未旋转
```
private int searchDivIndex(int[] nums, int low, int high) {
            //未旋转的情况，index设为-1
            if(nums[low] < nums[high]) {
                return -1;
            }
            //发生了旋转的情况
            //找到旋转的点，即原数组最大值所在位置
            while(low <= high) {
                int mid = (low+high)/2;
                if(nums[mid] > nums[mid+1]) {
                    return mid;
                }
//                if(nums[mid] < nums[low]) {
//                    high = mid - 1;
//                    //这样写会出现错误 如nums= {15,16,19,20,25,1,3,4,5,7,10,14}; 会发现找不到旋转点
//                } else if (nums[mid] < nums[high]) {
//                    low = mid + 1;
//                }
                if(nums[mid] < nums[low] ){
                    high = mid -1;
                } else {
                    low = mid + 1;
                }
            }
            return 0;
        }
```

2.二分查找target对应的索引
注意要排除特殊情况，nums未空、nums长度为1等
```
        public int search(int[] nums, int target) {
            if(nums.length == 0) {
                return -1;
            }
            if(nums.length == 1) {
                return nums[0]==target ? 0 : -1;
            }

            int dividedIndex = searchDivIndex(nums, 0 , nums.length-1);
            if(dividedIndex == -1) {
                return TwoSearch(nums, 0 , nums.length-1, target);
            }
            if(target == nums[0]) {
                return 0;
            }
            if(target < nums[0]) {
                return TwoSearch(nums, dividedIndex+1, nums.length-1, target);
            }
            return TwoSearch(nums, 0, dividedIndex+1, target);
        }
```

3.二分查找，找target和找旋转点本质是一样的，区别在于对nums[mid]的判断返回条件有区别
```
        private int TwoSearch(int[] nums, int low, int high, int target) {
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (nums[mid] == target) {
                    return mid;
                }
                if (target > nums[mid]) {
                    low = mid+1;
                }
                if (target < nums[mid]) {
                    high = mid-1;
                }
            }
            return -1;
        }
```

测试
```
    public static void main(String[] args) {
            int[] nums = {15,16,19,20,25,1,3,4,5,7,10,14};
            int target = 25;
            SolutionXuanZhuan solutionXuanZhuan = new SolutionXuanZhuan();
            int res = solutionXuanZhuan.search(nums, target);
            System.out.println(res);
    }


```

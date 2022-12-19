### 解题思路
配合三数之和暴力破解，没啥好说的

### 代码

```java
class Solution {
     public List<List<Integer>> fourSum(int[] nums, int target) {
        // 先排序
        Arrays.sort(nums);

        if(nums.length<4){
            return new LinkedList<>();
        }

        List<List<Integer>> result = new LinkedList<>();
        // 下面这个set是用作去重复用的
        Set<String> filterSet = new LinkedHashSet<>();

        for(int i=0;i<nums.length;i++){
            int left_v = target - nums[i];
            int[] left_arrays = new int[nums.length-1];
            for(int j=0,k=0;j<left_arrays.length;j++,k++){
                if(k == i){
                    k++;
                }
                left_arrays[j] = nums[k];
            }
            this.threeSum1(left_arrays,left_v,nums[i],result,filterSet);
        }
        return result;
    }

    public void threeSum1(int[] nums, int target, int orgValue,List<List<Integer>> rs,Set<String> fs) {

        int min = Integer.MAX_VALUE;

        // 循环从1开始，因为左右两边的不可能构成三个元素
        // 循环结束从倒数第二个结束
        for (int i = 1; i < nums.length-1; i++) {
            int mid = nums[i];

            // 定义双指针
            // 双指针从两头开始向内收
            int leftPointer = 0;
            int rightPointer = nums.length-1;

            // 结束条件
            // 1.左侧指针顶到了C位
            // &&
            // 2.右侧指针订到了C位
            while(leftPointer<i && rightPointer>i){

                int left = nums[leftPointer];
                int right = nums[rightPointer];

                int temp_sum = left+mid+right;
                int diff = target - temp_sum;
                int abs_diff = Math.abs(diff);
                if(abs_diff<min){
                    min = abs_diff;
                }
                if(diff == 0){

                    int[] tempSortedArray = new int[]{orgValue,left,mid,right};
                    Arrays.sort(tempSortedArray);
                    StringBuilder sb = new StringBuilder();
                    for(int ele:tempSortedArray){
                        sb.append(ele);
                    }
                    boolean canAdd = fs.add(sb.toString());

                    if(canAdd){
                        // 如果恰好相等，和为0，那么直接返回
                        List<Integer> item = new ArrayList<>(4);
                        item.add(tempSortedArray[0]);
                        item.add(tempSortedArray[1]);
                        item.add(tempSortedArray[2]);
                        item.add(tempSortedArray[3]);
                        rs.add(item);
                    }
                    // 随便选一个指针移动就行
                    leftPointer++;
                }else if(diff > 0){
                    // 如果大于0，证明三个数的和太小，需要增大数值，所以左边的指针向右移动
                    leftPointer++;
                }else if(diff < 0){
                    // 如果小于0，证明三个数的和太大，需要减少数值，所以右边的指针向左移动
                    rightPointer--;
                }
            }
        }
        return;
    }
}
```
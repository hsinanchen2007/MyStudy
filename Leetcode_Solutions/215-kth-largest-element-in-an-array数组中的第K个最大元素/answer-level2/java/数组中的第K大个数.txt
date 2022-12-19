### 解题思路
1. 鸡贼的使用Arrays.sort方法，速度倒是不快。。
2. 学到如何将int数组转化为Integer数组，如下：Integer[] integer = Arrays.stream(int数组).boxed().toArray(Integer[]::new);
3. 然后就想，找第k大个数，就需要比较，因此还是需要排序，但是不需要全部排序，也就是说找到第k大即可。然后就想到用快排，找到第k大就停止。
4. 写完之后，效果不是很好。然后就分析问题，其中有些地方可以改进，在递归时，如果得到的当前点不是k，那么根据和k的大小可以剪枝。然后在partition时，选取哨兵时加入随机数以对付极端测试用例。具体方法如下：private static Random random = new Random(System.currentTimeMillis());int randomIndex = start + 1 + random.nextInt(end - start);nextInt（n）方法生成一个随机数，在[0，n)之间。
5. 本题中采用是双指针搜索，一个指向start+1， 一个指向end。左右指针都可以先动，最终左指针指向大于哨兵的数，右指针指向小于哨兵的数。之后交换两个数。
6. 需注意，如果左指针先动，最后要交换start和end并返回end。如果右指针先动，最后要交换start和left-1并返回left-1.

### 代码

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Integer[] integers1 = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        Arrays.sort(integers1, Collections.reverseOrder());
        return integers1[k-1];
    }
}

class Solution {
    private static Random random = new Random(System.currentTimeMillis());

    public int findKthLargest(int[] nums, int k) {
        if(nums == null || nums.length == 0 || k < 1 || k > nums.length) return Integer.MIN_VALUE;
        int numsLen = nums.length;
        quickSort(nums, 0, numsLen-1, k);
        return nums[numsLen-k];
    }

    public void quickSort(int[] nums, int start, int end, int k){
        if(start >= end) return;
        int mid = partition(nums, start, end);
        if(mid == nums.length - k) return;
        else if(mid > nums.length - k)
            quickSort(nums, start, mid - 1, k);
        else quickSort(nums, mid + 1, end, k);
    }

    public int partition(int[] nums, int start, int end){
        if(start >= end) return start;

        int randomIndex = start + 1 + random.nextInt(end - start);
        swap(nums, start, randomIndex);
        int provit = nums[start], left = start + 1;
        while(left <= end){
            while(left <= end && nums[end] > provit) end--;
            while(left <= end && provit > nums[left]) left++;
            
            
            if(left>end) break;
            swap(nums, left, end);
            left++;
            end--;
        }
        swap(nums, start, left-1);
        return left-1;
    }

    private void swap(int[] nums, int num1, int num2){
        int tmp = nums[num1];
        nums[num1] = nums[num2];
        nums[num2] = tmp;
    }
}
```
可以参考Leetcode 31 next permutation官方题解。
使用迭代的的方法求字典顺序的下一个排列。

```
class Solution {
        
    public List<List<Integer>> permute(int[] nums) {
        // 首先进行排序
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> per = new ArrayList<Integer>();
        // 不要忘记加入第一个字典顺序
        for( int num : nums ) {
            per.add(num);
        }
        result.add( per );
        while( true ) {
            int i = nextPermutation(nums);
            // 增加这一句，跳出循环
            // 如果i = -1，说明当前是最后一个字典顺序
            if( i < 0 ) {
                break;
            }
            per = new ArrayList<Integer>();
            for( int num : nums ) {
                per.add(num);
            }
            result.add( per );
        }        
        return result;
    }
    
    public int nextPermutation(int[] nums) {

        // 先从右到左扫描数组,找到第一个降序的数，设为des
        // 再从这个数从右到左扫描，找到1个刚刚好大于des的数asc，如果数字相同，继续取靠右的
        // 交换这两个数，将原来des后面的（不包括des) 的数reverse
        int i = nums.length - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.length - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        // 如果i = -1，说明当前是最后一个字典顺序
        reverse(nums, i + 1, nums.length-1 );
        return i;
    }
    
    private void swap( int[] nums, int i, int j ) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    private void reverse( int[] nums, int left, int right ) {
        while ( left <= right ) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
    
}

```

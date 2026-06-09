```
class Solution {
    public int findMin(int[] nums) {
        int l = 0;
        int r = nums.length - 1;
        while (l < r){
            /** 这个左右中位数的选择其实是在写完if之后再决定的 l + 1就用左 反之亦然 */
            int mid = (l + r) >>> 1;

            /** 如果mid比right大 则说明[l, mid]是有序的 但是最小的数被旋转到了右侧  
                mid右侧的前几个数可能比mid大(3456712) 也能比mid小(3456712) 
                但是最靠近右侧的一定要比mid小(3456712) 所以mid显然不是解 所以l + 1
            */
            if (nums[mid] > nums[r]){
                l = mid + 1;
            }

            /** 如果上个if已经明白 其实这个直接写r = mid就可以了
                简单解释一下 如果mid小于right 则说明 [mid, right]是有序的 mid左侧的前几个数
                可能比mid小(51234) 也可能比mid大(51234) 但是左侧的数一定比mid大(51234)  
                若mid是左侧第二个数(312) 那么mid可能就是解 所有r = mid
            */
            else{
                r = mid;
            }
        }
        return nums[r];
    }
}
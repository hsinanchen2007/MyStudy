```java
class Solution {
    private Random random = new Random();

    public int findKthLargest(int[] nums, int k) {
        int l = 0;
        int r = nums.length - 1;
        // k largest num = the (nums.length - k + 1)th num
        k = nums.length - k + 1;
        while (l < r) {
            int idx = partition(nums, l, r);
            if (idx == k - 1) {
                return nums[idx];
            } else if (idx < k - 1) {
                l = idx + 1;
            } else {
                r = idx - 1;
            }
        }
        return nums[l];
    }

    private int partition(int[] nums, int start, int end) {
        int idx = start + random.nextInt(end - start + 1);
        int pivot = nums[idx];
        swap(nums, idx, end);
        idx = start - 1;
        int i = start - 1;
        while (++i < end) {
            if (nums[i] < pivot) {
                swap(nums, ++idx, i);
            }
        }
        swap(nums, ++idx, end);
        return idx;
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    public static void main(String[] args) {
        int[] nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        int k = 4;
        KthLargest kthLargest = new KthLargest();
        System.out.println(kthLargest.findKthLargest(nums, k));

    }
}

```

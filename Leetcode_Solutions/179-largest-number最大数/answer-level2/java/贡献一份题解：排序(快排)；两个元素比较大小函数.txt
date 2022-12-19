// 利用快排排序     
// 利用字符串比较两个元素的大小      
// 特殊处理：当最大的为0时，直接返回0      

```
class Solution {
    public String largestNumber(int[] nums) {
        StringBuilder builder = new StringBuilder();
        if (nums.length <= 0) {
            return builder.toString();
        } else if (nums.length <= 1) {
            return builder.append(nums[0]).toString();
        }

        sort(nums, 0, nums.length - 1);
        if (nums[nums.length - 1] <= 0) {
            return "0";
        }
               for (int i = nums.length-1; i >=0; i--) {
            builder.append(nums[i]);
        }
        return builder.toString();
    }

    public void sort(int arr[], int low, int high) {
        int l = low;
        int h = high;
        int povit = arr[low];

        while (l < h) {
            while (l < h && isLarge(arr[h], povit))
                h--;
            if (l < h) {
                arr[l] = arr[h];
                l++;
            }

            while (l < h && isLarge(povit, arr[l]))
                l++;

            if (l < h) {
                arr[h] = arr[l];
                h--;
            }
        }
        arr[l] = povit;
        if (l - 1 > low) sort(arr, low, l - 1);
        if (h + 1 < high) sort(arr, h + 1, high);
    }

    private boolean isLarge(int o1, int o2) {
        if (o1 == o2) {
            return true;

        }
          String a = String.valueOf(o1);
        String b = String.valueOf(o2);
        for (int i = 0; i <= Math.max(a.length(), b.length()); i++) {
           char x = a.charAt(i % a.length());
            char y = b.charAt(i % b.length());
            if (x == y) {
                continue;
            }

            return x > y;
        }
        return true;
    }
}
```
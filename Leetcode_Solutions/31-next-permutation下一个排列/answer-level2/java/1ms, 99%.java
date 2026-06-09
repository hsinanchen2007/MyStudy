```
public void nextPermutation(int[] nums) {
        for (int i = nums.length - 1; i > 0; i--) {
            //找到第一个比前一个大的数的下标
            if (nums[i] > nums[i - 1]) {
                int min = nums[i];
                int ind = i;
                //查找要交换的数的后面的最小值
                for (int j = i; j < nums.length; j++) {
                    if (min > nums[j] && nums[j] > nums[i-1]){
                        min = nums[j];
                        ind = j;
                    }
                }
                //交换两者位置
                int temp = min;
                nums[ind] = nums[i - 1];
                nums[i - 1] = temp;
                //排序
                for (int j = i; j < nums.length - 1; j++) {
                    for (int k = j + 1; k < nums.length; k++) {
                        if (nums[j] > nums[k]) {
                            int t = nums[j];
                            nums[j] = nums[k];
                            nums[k] = t;
                        }
                    }
                }
                return;
            }
        }
        //否则就交换
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
```

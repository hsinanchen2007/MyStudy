除了众所周知的摩尔投票法，也可以用排序来解决，因为出现超过一半的数字，排序后肯定占据了中间位置。所以此题类似于求第K大问题，此时K为数组长度的一半，即中间值。那么就可以用快排的partation来切分，因为partation每次都会将一个元素放到正确的位置，当发现当前位置是中间位置时即可返回。
```java
    public int majorityElement(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        int middle = nums.length >>> 1;
        int index = partation(left, right, nums);
        while (index != middle) {
            if (index > middle)
                right = index - 1;
            else
                left = index + 1;
            index = partation(left, right, nums);
        }
        return nums[index];
    }
    private int partation(int left, int right, int[] array) {
        int temp = array[right];
        while (left < right) {
            while (left < right && array[left] <= temp)
                left++;
            array[right] = array[left];
            
            while (left < right && array[right] > temp)
                right--;
            array[left] = array[right];
        }
        array[left] = temp;
        return left;
    }
```

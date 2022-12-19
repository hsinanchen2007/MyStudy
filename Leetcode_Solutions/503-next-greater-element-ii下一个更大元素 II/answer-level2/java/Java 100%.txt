

```
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        if (nums.length == 0) {
            return new int[0];
        }
        
        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            result[i] = Integer.MIN_VALUE;
        }
        
        
        for (int j = nums.length - 1; j >= 0; --j) {
            boolean isFind = false;
            for (int i = j + 1; i < nums.length; ++i) {
                if (nums[i] > nums[j]) {
                    result[j] = nums[i];
                    isFind = true;
                    break;
                } else {
                    if (result[i] > nums[j]) {
                        result[j] = result[i];
                        isFind = true;
                        break;
                    }
                }
            }

            if (!isFind) {
                for (int i = 0; i < j; ++i) {
                    if (nums[i] > nums[j]) {
                        result[j] = nums[i];
                        isFind = true;
                        break;
                    } else {
                        if (result[i] > nums[j]) {
                            result[j] = result[i];
                            isFind = true;
                            break;
                        }
                    }
                }
            }

            if (!isFind) {
                result[j] = -1;
            }

        }

        return result;
    }
}
```

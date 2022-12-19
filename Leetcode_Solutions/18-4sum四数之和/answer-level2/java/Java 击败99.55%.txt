```java
    public static List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>(8);
        int len = nums.length;
        if (len < 4) {
            return result;
        }
        Arrays.sort(nums);
 
        int minValue = nums[0] + nums[1] + nums[2] + nums[3];
        int maxValue = nums[len - 1] + nums[len - 2] + nums[len - 3] + nums[len - 4];
        if (maxValue < target || minValue > target) {
            return result;
        }
        int left = 2;
        int right = len - 1;
        //第一个固定值的值
        int oneValue = 0;
        //第2个固定值的值
        int twoValue = 0;
        int fourNumSum = 0;
        for (int one = 0; one <= len - 4; one++) {
            oneValue = nums[one];
            if (one > 0 && nums[one] == nums[one - 1]) {
                continue;
            }
            for (int two = one + 1; two <= len - 3; two++) {
                if (two > one+1 && nums[two] == nums[two - 1]) {
                    continue;
                }
                twoValue = nums[two];
                left = two + 1;
                right = len - 1;
                minValue = oneValue + twoValue + nums[two + 1] + nums[two + 2];
                maxValue = oneValue + twoValue + nums[len - 2] + nums[len - 1];
                if (maxValue < target || minValue > target) {
                    left = right;
                }
                while (left < right) {
                    fourNumSum = nums[left] + nums[right] + oneValue + twoValue;
                    if (fourNumSum > target) {
                        right--;
                        while (right > left && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    } else if (fourNumSum < target) {
                        left++;
                        while (right > left && nums[left] == nums[left - 1]) {
                            left++;
                        }
                    } else {
                        List<Integer> resultOne = new ArrayList<>(4);
                        resultOne.add(oneValue);
                        resultOne.add(twoValue);
                        resultOne.add(nums[left]);
                        resultOne.add(nums[right]);
                        result.add(resultOne);

                        left++;
                        right--;
                        while (right > left && nums[right] == nums[right + 1]) {
                            right--;
                        }
                        while (right > left && nums[left] == nums[left - 1]) {
                            left++;
                        }
                    }
                }

            }


        }
        return result;

    }
```

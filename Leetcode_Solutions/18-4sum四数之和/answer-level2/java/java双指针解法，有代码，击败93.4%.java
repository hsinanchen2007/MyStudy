 ```
public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> lists = new ArrayList<>();
        int length = nums.length;
        for (int i = 0; i < length-3; i++) {
            int a1 = target - nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i+1; j < length-2; j++) {
                int a2 = a1 - nums[j];
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int start = j + 1;
                int end = length - 1;

                while (start < end) {
                    int twoCounter = nums[start] + nums[end];

                    if (a2 > twoCounter) {
                        start++;
                    } else if (a2 < twoCounter) {
                        end--;
                    } else {
                        List list = new ArrayList();
                        list.add(nums[i]);
                        list.add(nums[j]);
                        list.add(nums[start]);
                        list.add(nums[end]);
                        lists.add(list);
                        while(start<end&&nums[start]==nums[start+1]){
                            start++;
                        }
                        while(start<end&&nums[end]==nums[end-1]){
                            end--;
                        }
                        start++;
                        end--;
                    }

                }
            }
        }
        return lists;
    }
```

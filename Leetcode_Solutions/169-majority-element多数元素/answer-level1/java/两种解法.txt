一：HashMap
```
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int half=(nums.length+1)/2;
        for (int num : nums) {
            int count=map.getOrDefault(num, 0);
            count++;
            if (count>=half){
                return num;
            }
            map.put(num, count);
        }
        return 0;
    }
```
![1.JPG](https://pic.leetcode-cn.com/785b0f41af346b8b01fb3920c3c949c6d904c9acfe071fa1b3b53494209b2a72-1.JPG)

二：排序
```
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
```
![捕获.JPG](https://pic.leetcode-cn.com/224658cdc7714b3c2792d6ee76fd38f1ec761cfe4b7cb749c835c3e5f8c7f562-%E6%8D%95%E8%8E%B7.JPG)


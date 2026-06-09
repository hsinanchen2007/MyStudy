### 法一
用HashMap统计元素出现次数，满足条件即可退出。

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        Map<Integer, Integer> hashMap = new HashMap<>();
        int n = nums.length / 2;
        for (int i = 0; i < nums.length; i++) {
            int count = 0;
            if (null != hashMap.get(nums[i])) {
                count = hashMap.get(nums[i]);
                hashMap.put(nums[i], ++count);
            } else {
                hashMap.put(nums[i], 1);
                count = 1;
            }

            if (count > n) {
                return nums[i];
            }
        }

        return Integer.MIN_VALUE;
    }
}
```

### 法二
不用HashMap，由于排序后的数组相等的数据一定相邻，用一个变量记录出现次数即可。

```java
class Solution {
    public int majorityElement(int[] nums) {
        if (1 == nums.length) {
            return nums[0];
        }
        Arrays.sort(nums);
        int n = nums.length / 2;
        int count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count > n) {
                return nums[i];
            }
        }

        return Integer.MIN_VALUE;
    }
}
```

### 法三
统计出现最大次数的元素
```java
class Solution {
    public int majorityElement(int[] nums) {
        int tmp = nums[0];
        int count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (tmp == nums[i]) {
                count++;
            } else {
                if (--count == 0) {
                    tmp = nums[i];
                    count = 1;
                }
            }
        }

        return tmp;
    }
}
```

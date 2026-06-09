# PS:
归并的题解太多了，提供一些非主流的方法，看看就好。
主要是利用ArrayList的特性 +  二分查找 共同实现。

# 代码1(remove())
```java
class Solution {
    public int reversePairs(int[] nums) {
        int len = nums.length, res = 0;
        ArrayList<Integer> sorted_list = Arrays.stream(nums).sorted().boxed().collect(Collectors.toCollection(ArrayList::new));
        for (int i = 0; i < len - 1; ++i) {
            int num = nums[i];
            sorted_list.remove(Collections.binarySearch(sorted_list, num));
            int idx = Collections.binarySearch(sorted_list, num);
            if (idx < 0) idx = -idx - 1;
            else {
                while (idx > 0 && sorted_list.get(idx - 1) == num)
                    --idx;
            }
            res += idx;
        }
        return res;
    }
}
```

# 代码2(add())
```java
class Solution {
    public int reversePairs(int[] nums) {
        if (nums.length < 2) return 0;
        int len = nums.length, res = 0;
        ArrayList<Integer> sorted_list = new ArrayList<>(len);
        sorted_list.add(nums[0]);
        for (int i = 1; i < len; ++i) {
            int num = nums[i];
            int idx = Collections.binarySearch(sorted_list, num);
            if (idx < 0) {
                idx = -idx - 1;
                res += i - idx;
            } else {
                while (idx + 1 < i && sorted_list.get(idx + 1) == num)
                    ++idx;
                res += i - 1 - idx;
            }
            sorted_list.add(idx, num);
        }
        return res;
    }
}
```


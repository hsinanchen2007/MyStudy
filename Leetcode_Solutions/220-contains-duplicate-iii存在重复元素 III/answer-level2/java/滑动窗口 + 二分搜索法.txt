基本思路 ： 
首先维护一个k长度的滑动窗口set。
然后由于set是排好序了的，因此可以直接把set转换为list进行二分搜索。
令lNum = nums[i] - t rNum = nums[i] + t (注意：这里可能产生溢出)，判断list中是否存在val,使得 lNum <= val <= rNum。
这道题有几个坑：
1. 直接滑动窗口+线性搜索会超时的 
2. 数字可能会产生溢出 eg [0,2147483647] 1 2147483647，然后官方解答就偷偷的使用了long类型。
3. t居然可以为负数，咕了。

```
public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        //居然存在 t < 0 用例
        if (t < 0) return false;
        //t == 0 退化为 II的问题了,直接copy
        if (t == 0) return helper(nums, k);
        Set<Integer> set = new HashSet<>();
        int n = nums.length;
        int left, right, len;
        for (int i = 0; i < n; i++) {
            //防止溢出问题
            left = nums[i] < (t + Integer.MIN_VALUE) ? Integer.MIN_VALUE : nums[i] - t;
            right = (Integer.MAX_VALUE - t) < nums[i] ? Integer.MAX_VALUE : nums[i] + t;

            //判断set中是否存在val 在 left- right之间
            if (isContain(new ArrayList<>(set), left, right))
                return true;
            set.add(nums[i]);
            if (set.size() > k)
                set.remove(nums[i - k]);
        }
        return false;
    }

    //前一道题II的代码，直接粘贴过来了
    public boolean helper(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; ++i) {
            if (set.contains(nums[i])) return true;
            set.add(nums[i]);
            if (set.size() > k) {
                set.remove(nums[i - k]);
            }
        }
        return false;
    }

    //二分法：判断set是否存在value 在lNum - rNum之间
    private boolean isContain(List<Integer> list, int lNum, int rNum) {
        int n = list.size();
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (list.get(mid) < lNum) {
                l = mid + 1;
            } else if (list.get(mid) > rNum)
                r = mid - 1;
            else
                return true;
        }
        return false;
    }
```







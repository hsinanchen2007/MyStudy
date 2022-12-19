## 记录三种解法

### 解法一：哈希表
哈希表的思路比较简朴，不赘述。

时间复杂度：$O(n)$。
空间复杂度：$O(n)$。

代码：
```java
class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int times = nums.length / 2;
        for(int i : nums)
        {
            int cnt = map.getOrDefault(i, 0) + 1;
            if(cnt > times) return i;
            map.put(i, cnt);
        }
        return -1;
    }
}
```

### 解法二：分而治之(divide and conquer)
通过递归，不断把数组一分为二，从而把问题分解为若干个子问题，通过求解子数组中的众数，得到原数组的众数。
递归边界：数组为空或只有一个元素。
到达边界时，数组中的元素就是该子数组的众数，合并两个子数组得到一个大数组的众数。合并的方法：若两个子数组众数相同，则这个众数必定也是大数组的众数；若不相同，则出现次数更多的众数为大数组的众数。
如上所述，不断合并两个子数组得到大数组的众数，如此这般，直至得到原数组的众数。

时间复杂度：$O(nlogn)$。
空间复杂度：$O(logn)$。

代码：
```java
class Solution {
    public int majorityElement(int[] nums) {
        return getMajority(nums, 0, nums.length - 1);
    }

    /**
     * 递归分治地求解子数组的众数
     * @param 子数组以及子数组首尾元素的下标
     */
    private int getMajority(int[] a, int lo, int hi) {
        if(hi == lo)    return a[lo];
        int mid = lo + (hi - lo) / 2;
        int left = getMajority(a, lo, mid);
        int right = getMajority(a, mid + 1, hi);
        if(left == right)   return left;
        if(getCount(a, lo, mid, left) > getCount(a, mid + 1, hi, right))
            return left;
        else    return right;
    }

    /**
     * @return 子数组的众数在子数组中的出现次数
     */
    private int getCount(int[] a, int lo, int hi, int key) {
        int cnt = 0;
        for(int i : a)
            if(i == key)    
                cnt++;
        return cnt;
    }
}
```

### 解法三：参考官方的投票算法
两两相消，到最后剩下的就是真正的众数。

时间复杂度：$O(n)$。
空间复杂度：$O(1)$。

代码：
```java
class Solution {
    public int majorityElement(int[] nums) {
        int cnt = 0;
        int majority = -1;
        for(int i : nums)
        {
            if(cnt == 0)        majority = i;
            if(i == majority)   cnt++;
            else                cnt--;
        }
        return majority;
    }
}
```
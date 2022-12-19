

*题外话：[动画真·硬核炫耀一下我的双指针模版](https://leetcode-cn.com/circle/article/8z7Hq0/)*

-------
**因为已知元素的出现次数大于n/2，所以本题有两个简单的切入点：**


**1、从次数切入**：常规思路`CounterMap统计次数`(O(N))，若某个元素出现次数大于n/2，则找到。这个太简单了，就简单贴下代码，不赘述了。。

``` Java
class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> counter = new HashMap<>();
        // 遍历每个数统计次数
        for (int num: nums) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
            // 如果某个数次数超过了n/2就返回
            if (counter.get(num) > nums.length / 2) {
                return num;
            }
        }
        return -1;
    }
}
```

**2、从位置切入**：本题可以理解成求第n/2+1小的数，典型的`求第K大/第K小问题`，（看见很多同学先O(NlogN)排序在找第n/2+1大的数，其实是没必要全部排序的～）直接`快排O(N)找第K大/第K小`即可。雷同问题相同解法可以看看[215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)，下面贴代码，注释的还算明了吧。。

``` Java
class Solution {
    public int majorityElement(int[] nums) {
        return quickSearch(nums, 0, nums.length - 1, nums.length / 2);
    }

    private int quickSearch(int[] nums, int lo, int hi, int k) {
        // 每快排切分1次，找到排序后下标为j的元素，如果j恰好等于n/2就返回；
        int j = partition(nums, lo, hi);
        if (j == k) {
            return nums[j];
        }
        // 否则根据下标j与k的大小关系来决定继续切分左段还是右段。
        return j > k? quickSearch(nums, lo, j - 1, k): quickSearch(nums, j + 1, hi, k);
    }

    // 快排切分，返回下标j，使得比nums[j]小的数都在j的左边，比nums[j]大的数都在j的右边。
    private int partition(int[] nums, int lo, int hi) {
        int v = nums[lo];
        int i = lo, j = hi + 1;
        while (true) {
            while (++i <= hi && nums[i] < v);
            while (--j >= lo && nums[j] > v);
            if (i >= j) {
                break;
            }
            int t = nums[j];
            nums[j] = nums[i];
            nums[i] = t;
        }
        nums[lo] = nums[j];
        nums[j] = v;
        return j;
    }
}
```
**时间复杂度:**
嗯...之前在评论里贴了快排切分后，有同学说快排不是NlogN的嘛，所以在这里赘述一下时间复杂度啦啦啦啦。
因为我们是要找下标为k的元素，第一次切分的时候需要遍历整个数组(0 ~ n)找到了下标是j的元素，假如k比j小的话，那么我们下次切分只要遍历数组(0~k-1)的元素就行啦，反之如果k比j大的话，那下次切分只要遍历数组(k+1～n)的元素就行啦，总之可以看作每次调用partition遍历的元素数目都是上一次遍历的1/2，因此时间复杂度是`N + N/2 + N/4 + ... + N/N = 2N`, 因此时间复杂度是`O(N)`。


**3、拓展问题**：求中位数有个很经典问题就是如何求数据流中的中位数，可以用大根堆小根堆双堆实现O(logN)插入O(1)查找，见[295. 数据流的中位数](https://leetcode-cn.com/problems/find-median-from-data-stream/)，解决方案很有意思但是很简洁，这里我就不贴了，感兴趣的童鞋自行前往哈_(:3」∠❀)_



**好，蟹蟹各位宝宝们观看～～ ( శ 3ੜ)～♥**





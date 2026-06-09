
🙋🙋🙋今天这道题目就没什么可说的了，常见的排序算法都是老生常谈了，我相信大家也都学过了，今天我来给大家讲有趣的故事~

### 常见的排序算法

如果你了解的排序算法不多的话，这个可以根据维基百科了解详细的信息，逐个攻破。

[排序算法——维基百科](https://zh.wikipedia.org/wiki/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95)

常见的排序算法的时间复杂度见下图（来自维基百科）：
![image.png](https://pic.leetcode-cn.com/88f1505afff7ae86bc3d197586467b609f47ab7a8ed59d42c2212b0848a89e78-image.png)

早在13年的时候，网上出现了一个可视化展现15种排序的视频，原链接在 [这里](http://panthema.net/2013/sound-of-sorting/)。网页里的视频是油管上的，没有条件的童鞋可以看 [B站UP主搬运的视频](https://www.bilibili.com/video/BV1Ws411f7aJ?from=search&seid=1321146399733812906)。**贼有意思，一定要看！（最喜欢烧水壶开了那段~）**



#### 有趣的排序算法

关于排序算法，有3个很有趣的算法，可以拿出来说一下：

* [Bogo排序](https://zh.wikipedia.org/wiki/Bogo%E6%8E%92%E5%BA%8F)：算法原理特别简单，随机打乱数组，如果当前是有序的，就排序成功，否则继续随机打乱数组，直到有序位置。平均时间复杂度 $O(n* n!)$，最优时间复杂度 $O(n)$，最坏时间复杂度 $∞$！

* [珠排序](https://zh.wikipedia.org/wiki/%E7%8F%A0%E6%8E%92%E5%BA%8F)：这个直接看图就能理解了。它的时间复杂度很有意思，可以移步到维基百科看分析。 ![image.png](https://pic.leetcode-cn.com/2e72251b56b837fb942023ccec3c8b4b6d22fe79864eb2e5253ec124fbcf0700-image.png){:height="60%" width="60%"}

* 睡眠排序（辞退排序）: 对于int[] nums，创建n个线程，每个线程sleep(nums[i])秒，然后线程醒过来的时候报数。这样就可以排序了！

### 底层排序算法
* C++ std sort：整体采用快速排序的算法，并且选择哨兵的时候，采用了三数取中法（头部，中部，尾部元素，三者的中间值作为哨兵）。如果在某次递归时，数据量小于16个，则采用插入排序。如果递归层次过深，会采用桶排序。其实std的实现还有更进一步优化，前面所说的有一些细节上不太一样，想关心具体源码细节的同学可以参考[这个人的博文](http://feihu.me/blog/2014/sgi-std-sort/)。

* Java/Python [TimSort](https://zh.wikipedia.org/zh-hans/Timsort)：Java早些年的时候排序算法用的是归并排序，从Java SE7 开始改成了TimSort。TimSort是什么呢？2002年，Tim Peters为Python标准库实现了这个算法（他自己提出并且以自己名字命名了排序算法。。）。由于现实中很多的数据都是基本有序的，这时候TimSort就会非常快。关于 TimSort，有一个有趣的故事：[形式化方法的逆袭——如何找出Timsort算法和玉兔月球车中的Bug？](https://bindog.github.io/blog/2015/03/30/use-formal-method-to-find-the-bug-in-timsort-and-lunar-rover/)
这个 bug 现在应该是已经fix了。

回到这题上来，你以为你写 `Arrays.sort(nums)` 调用的是 TimSort 吗？并不是！你使用 `Collections.sort` 的时候才是TimSort。你在IDE 里点进去 `Arrays.sort` 这个方法，你会发现是 DualPivotQuicksort。它混合了快速排序，插入排序，归并排序，桶排序，TimSort。有阅读源码能力的人可以自行研究下，网上分析 DualPivotQuicksort 源码的博文也不少，可以去看看。

### 分布式排序

最近看到了一篇文章，里面讲了[并行正则采样排序算法](https://zhuanlan.zhihu.com/p/115294026)，个人觉得还是很有意思的~

### 题解

所以今天的题解就用 DualPivotQuicksort 来水一发吧（说出来显得比较厉害）~

```java
class Solution {
    public int[] sortArray(int[] nums) {
        Arrays.sort(nums);
        return nums;
    }
}
```

说了这么多，上面很多都是比较排序，其实这道题用非比较排序的计数排序会略微快一丢丢滴，因为这道题元素的数据范围很小。

2ms 100% O(N)

```
class Solution {
    public int[] sortArray(int[] nums) {
        int max = -50001, min = 50001;
        for (int num: nums) {
            max = Math.max(num, max);
            min = Math.min(num, min);
        }


        int[] counter = new int[max - min + 1];
        for (int num: nums) {
            counter[num - min]++;
        }

        int idx = 0;
        for (int num = min; num <= max; num++) {
            int cnt = counter[num - min];
            while (cnt-- > 0) {
                nums[idx++] = num;
            }
        }
        return nums;
    }
}
```

以上谢谢大家，**求赞求赞求赞！**

❤️大佬们随手关注下我的wx公众号【[甜姨的奇妙冒险](https://pic.leetcode-cn.com/304599b006dd41bcf2042715f31a2dc4fbdc4cf9748a11a81d8978ea1e839956-wxgzh.jpeg)】和 知乎专栏【[甜姨的力扣题解](https://zhuanlan.zhihu.com/c_1224355183452614656)】 
更多题解干货等你来～～
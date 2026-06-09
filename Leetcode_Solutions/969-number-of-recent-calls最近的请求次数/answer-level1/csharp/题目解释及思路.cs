这道题就是一个阅读理解题，所以这可能就是这道题为什么有那么多踩吧。(没错我也踩了)
![截屏2020-01-1323.07.57.png](https://pic.leetcode-cn.com/0ce9a72bed80bfb3458d9fe76cdf2fbba42a406d29f1ff40f82801ba4d6b3178-%E6%88%AA%E5%B1%8F2020-01-1323.07.57.png)

从英文版到中文版，反复阅读反复理解终于理解了，接下来就给大家讲解一下。

首先我们需要搞清楚这道题目的意思。

我们举例来说吧，例如所给出的例子
￼
![截屏2020-01-1322.57.08.png](https://pic.leetcode-cn.com/2787cbe155cc45aff6926538736c0b2b8a5e31a0db7ae80413f43c85b2f7d6d1-%E6%88%AA%E5%B1%8F2020-01-1322.57.08.png)

第一个`inputs`代表电话打出的记录，
第二个`inputs`表示电话打出的时间，

所以可以理解为 

	[“RecentCouter”] 与 [null] 不需要考虑
	第一个 ping声 出现的时间为 1毫秒，
	第二个 ping声 出现的时间为 100毫秒，
	第三个 ping声 出现的时间为 300毫秒，
	第四个 ping声 出现的时间为 3002毫秒。

那么就要计算的是在当前`ping声`出现的时间及其前3000毫秒出现了多少次 ping 声。 

如果把当前`ping声`出现的时间记做 `t` ，那么就要找出`(t-3000)毫秒`至`t毫秒`之间的 `ping声`有多少次。

再次之前我们需要明确开始时间是`0毫秒`所以时间没有负数即 `if(t -3000 < 0)  t = 0;`

那么我来分析之前的那个例子，

	当 t = 1， 时间范围就为 (0~1),  那么符合此条件的ping声时间包括 [1毫秒] 所以结果就是 1
	当 t = 100， 时间范围就为 (0~100),  那么符合此条件的ping声时间包括 [1毫秒，100毫秒] 所以结果就是 2
	当 t = 3001， 时间范围就为 (1~3001),  那么符合此条件的ping声时间包括 [1毫秒，100毫秒，3001毫秒] 所以结果就是 3
	当 t = 3002， 时间范围就为 (2~3002),  那么符合此条件的ping声时间包括 [100毫秒，3001毫秒，3002毫秒] 所以结果就是 3

了解了题目意思，我们就能继续接下来的解题。

首先`RecentCounter()`是一个构造函数，根据算法的不同，有些会用到而有些不会。在我的方法中我建立了一个 `list` 来方便后续运算。然后我们就能在`list`里面进行运算了。

```
    private List<int> l;
    public RecentCounter()
    {
        l = new List<int>();     
    }
```

接下来我们看看第二个函数`public int Ping(int t) { }`，在这里会处理第二个`inputs` 传入的值(在上面的例子里为 `[[],[1],[100],[3001],[3002]]`) 

首先我们需要把传入的值放入之前主板好的`list l`中。

    l.Add(t);

这样以来依据我们出入的值可以得到不同长度的`list l`

	List<int> l = new List<int>() {} ;

	input: 1
	output: l = {1}

	input: 100
	output: l = {1,100}
	
	input: 3001
	output: l = {1,100,3001}

	input: 3002
	output: l = {1,100,3001,3002}

之前我一直理解为一次传入，后来理解了发现是一次一次地传入，所以每次运行此函数都会返回一个值，在网页中会自动把结果整理成一个数组，理解这一点就没有那么迷惑了。

还是以上面那个例子为例

	当 input = 1
	l = {1}

按照之前我们理解的意思，我们需要找到 `l` 中所有大于等于 `0`( 原为1 - 3000，但是时间没有负数，所以返回0，上面讨论过) 并且小于等于`1`的数的总个数。我们遍历 `l`发现有1个数，所以返回 1.

	当 input = 100
	l = {1,100} (1为上一步所加进的)

这次我们要找到`l`中大于等于`0` (100-3000 = -2900 => 0)且小于等于`100`的值，这里有2个，所以返回2 。

	当 input = 3001
	l = {1,100,3001}

这次我们要找到`l`中大于等于`1`(3001- 3000 = 1)且小于等于`3001`的个数，这里为3，所以返回3。

	当 input = 3002
	l = {1,100,3001,3002}

找到 大于等于`2`小于等于`3002`的个数为3(100,3001,3002)，所以返回3。

我们发现当`input <= 3000`时 我们可以直接返回`l`的长度，因为下限不会低于`0`。我们可以得到以下代码：

	if (t - 3000 < 0) return l.Count;

如果`input>3000`我们就需要算法来运算。对于C#来说 我们可以用`BinarySearch`来找出数在`list`中的索引。

这里我们利用简单的例子来讲解`BinarySearch`的用法

	List<int> test = new List<int>() {1,3,4,6,7,10};
	Console.WriteLine(test.BinarySearch(1));    // 0
	Console.WriteLine(test.BinarySearch(2));    // -2
	Console.WriteLine(test.BinarySearch(3));    // 1
	Console.WriteLine(test.BinarySearch(4));    // 2
	Console.WriteLine(test.BinarySearch(5));    // -4
	Console.WriteLine(test.BinarySearch(6));    // 3
	Console.WriteLine(test.BinarySearch(7));    // 4
	Console.WriteLine(test.BinarySearch(8));    // -6
	Console.WriteLine(test.BinarySearch(9));    // -6
	Console.WriteLine(test.BinarySearch(10));   // 5
	Console.WriteLine(test.BinarySearch(11));    // -7

当数存在当时，会返回此数的索引 (例如1，3，4，6，7，10)
当数不存在时，会返回 一个负数(例如2，5，8，9，11)，这里负数的绝对值-1 为如果把此数安升序放入数组里的索引。例如 8，如果放入 test 中 则为 {1,3,4,6,7,8,10} ，其中 8 的索引为 5 (|-6| - 1, ) 。 (｜｜为绝对值运算)

那么了解了`BinarySearch`的用法我们继续回到最初的例子。

	当 input = 3002
	l = {1,100,3001,3002}

这里我们要找的下限为 `2` (3002 - 3000)，那么如果2在l中，那么其索引应该为 `| l.BinarySearch(2) | -1  = ｜-2｜-1 = 2 -1 = 1 `。其实到这步我们已经可以了

	if(t >= 3000){
		var index = l.BinarySearch(t - 3000);
		return index > 0 ? l.Count - index : l.Count - (-index-1);
	}

但是还是觉得`(-index-1)`太麻烦了，我们可以简化为`～index`。

那么 `～` 表示的是什么呢？

`～` 表示的是反码，简单来说就是把十进制数转换为原码，然后进行反码运算，再转换为十进制。因为原码只有`0`和`1`，所以必须要用一位来表示正负，
这也是为什么`int`的最大值或最小值不互为绝对值。感兴趣的朋友可以自己去进一步了解。

	Console.WriteLine(int.MaxValue);  // 2147483647
	Console.WriteLine(int.MinValue);  //-2147483648


对于`～`不是很理解的话我们可以举一些例子。

	Console.WriteLine(~-4);    // 3
	Console.WriteLine(~-3);    // 2
	Console.WriteLine(~-2);    // 1
	Console.WriteLine(~-1);    // 0
	Console.WriteLine(~0);     // -1
	Console.WriteLine(~1);     // -2
	Console.WriteLine(~2);     // -3
	Console.WriteLine(~3);     // -4
	Console.WriteLine(~4);     // -5

那么 在`index<0`的情况下， `(-index-1) = ～index`

所以来说全部代码为

```
public class RecentCounter {
    private List<int> l;
	public RecentCounter()
	{
		l = new List<int>();     
	}

	public int Ping(int t)
	{
		l.Add(t);
		if (t - 3000 < 0) return l.Count;
		var index = l.BinarySearch(t - 3000);
		return index >= 0 ? l.Count - index : l.Count - ~index;
	}
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.Ping(t);
 */ 
```

这里参考学习了一下 krishnacs 的文章与代码，感兴趣的话可以查看一下
[https://leetcode.com/problems/number-of-recent-calls/discuss/191221/O(log-n)-Its-binary-search-C](https://leetcode.com/problems/number-of-recent-calls/discuss/191221/O(log-n)-Its-binary-search-C)
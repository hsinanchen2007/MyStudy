在得定的数组nums的数据元素中，只会出现下述两种情况
- 出现重复元素
- 不出现重复元素
但是，这么分类显然让人感觉意犹未尽，因为会涉及到重复数字是否是0的情况
因此我们可以进一步划分：
- 出现重复元素
    - 重复元素不含0
    - 重复元素含0。则含两个0（扑克牌最多只有两个王）
- 不出现重复元素
    - 出现0（显然，只含一个0）
    - 不出现0

我们逐渐深入的来看：
考虑到关于**顺子**的定义：**除0外**不能含有重复数字
说明，只要发现有非零重复元素，直接返回false即可
则显然，Set或者Map可以胜任。
**此处我们采用Set.利用set对象不可加入重复元素的特性**
    即：若set中不含元素a,则set.add(a)成功加入，且返回true
    否则返回false
    我们可以利用此函数的返回值

当加入到Set中之后。则set.size()有两种情况：
1. set.size()==5(不含重复元素)
    此时也可分两种情况
    - 含一个0
    - 不含0
    则对于每种情况均设置变量max，minNot0分别记录最大值和非0最小值
    - i:当不含0时，return max-minNot0==4 
        如：23456为顺子，6-2==4；返回true
        23458不是顺子，因为8-2==6!=4；返回false
    - ii:含0时（则只含一个0）
        此时采用计数原理。（插空法）
        **空5空5空5空5空** 
        5代表非零数字，空为0可以放入的位置
        有5中摆放法
        但无论如何摆放，想要构成顺子，则必有两种情况
        ①0在两端。如：05555或者55550 此时需要满足max-min==3
        ②0在中间位置。如：50555、55055、55505 此时需要满足max-min==4
1. set.size()==4（含有两个重复的0）
    我们也设置两个变量max，minNot0分别记录最大值和非0最小值
    此时情况为：**空5空5空5空**
    利用插空法，则先插入一个0有4种插法。再插入第二个0有5种插法
    **注意**此时，在插入第二个0的过程中会发生重复情况：当插入位置紧挨着第一个0时
    因为此处大小王都可代替任意牌，则当两王紧挨时，不应区分大小王的左右顺序
    所以一共有C4,1×C5.1÷2=10种插法（Ca,b为组合数，表示从a个数中选b个数共有多少种方式）
    它们分别为：
    - i:(00555、55500) 05550 此时需要满足max-min==2
    - ii:(05055、55050）(05505、50550) 此时需要满足max-min==3 
    - iii:(50055、50505、55005) 此时需要满足max-min==4

**PS:**在以往的问题中，都是不确定用例长度的
这次此题目反而就限定了输入数组的长度为5
一时反而不知该怎么做更好了。比如：是否要/值得采用java的Map或者Set等。。。
```
```java
    public static boolean isStraight(int[] nums) {
    	int min=Integer.MAX_VALUE,
		max=Integer.MIN_VALUE;
    	Set<Integer> set = new HashSet<>();
    	for(int i=0;i<nums.length;i++) {
    		if(nums[i]!=0) {
    			if(!set.add(nums[i])) return false;
    		}else set.add(nums[i]);
    	}
    	if(set.size()==5) {//含一个零或者不含0
    		if(set.contains(0)) {//含0
    			for(int t:nums) {
    				if(min>t&&t!=0) min=t;
        			if(max<t) max=t;
    			}
    			return max-min==3||max-min==4;
    		}else {//不含0
    			for(int t:nums) {
    				if(min>t&&t!=0) min=t;
        			if(max<t) max=t;
    			}
    			return max-min==4;
    		}
    	}else {//最多含两个0
    		for(int t:nums) {
				if(min>t&&t!=0) min=t;
    			if(max<t) max=t;
			}
			return max-min==2||max-min==3||max-min==4;
    	}
    }
```

```

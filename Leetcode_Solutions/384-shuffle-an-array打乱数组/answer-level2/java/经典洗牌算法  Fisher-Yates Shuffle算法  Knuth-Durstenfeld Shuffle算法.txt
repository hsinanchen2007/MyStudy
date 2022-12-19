 Fisher-Yates Shuffle算法

最早提出这个洗牌方法的是 Ronald A. Fisher 和 Frank Yates，即 Fisher–Yates Shuffle，

其基本思想就是从原始数组中随机取一个之前没取过的数字到新的数组中，具体如下：

1. 初始化原始数组和新数组，原始数组长度为n(已知)；

2. 从还没处理的数组（假如还剩k个）中，随机产生一个[0, k)之间的数字p（假设数组从0开始）；

3. 从剩下的k个数中把第p个数取出；

4. 重复步骤2和3直到数字全部取完；

5. 从步骤3取出的数字序列便是一个打乱了的数列。
- __# 代码：__
```
/** Returns a random shuffling of the array. */
	public int[] shuffle() {
		Random random = new Random();
		List<Integer> list = new ArrayList<Integer>();

		for (int i = 0; i < shuffledNums.length; i++) {
			list.add(shuffledNums[i]);
		}

		int x, j = 0;
		for (int i = list.size() - 1; i >= 0; i = list.size() - 1) {
			x = random.nextInt(i + 1);
			shuffledNums[j++] = list.get(x);
			list.remove(x);

		}

		return shuffledNums;
	}
```


Knuth-Durstenfeld Shuffle算法

Knuth 和 Durstenfeld 在Fisher 等人的基础上对算法进行了改进，在原始数组上对数字进行交互，省去了额外O(n)的空间。
该算法的基本思想和 Fisher 类似，每次从未处理的数据中随机取出一个数字，然后把该数字放在数组的尾部，即数组尾部存放的是已经处理过的数字。

__# 代码：__
```

    /** Returns a random shuffling of the array. */
   public int[] shuffle() {
		Random random = new Random();
        int x,t;
		for (int i = shuffledNums.length - 1; i > 0; i--) { 
			x = random.nextInt(i + 1);  
			t = shuffledNums[i];
			shuffledNums[i] = shuffledNums[x];
			shuffledNums[x] = t;
		}
		return shuffledNums;
	}
}
```

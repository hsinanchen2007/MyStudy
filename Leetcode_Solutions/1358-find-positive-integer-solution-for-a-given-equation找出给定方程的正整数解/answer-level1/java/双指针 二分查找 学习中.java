两个方法都是**参考评论和题解**所学习的
**我自己没读懂题目**，看了评论和题解才一知半解，写题解加深理解

# 双指针：
定义**两个指针**，都从一**端**移动到另一**端**
需要消耗的时间比较多，
两个指针需要从一端到另一端
```
public static List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
		// 声明一个集合，存放结果
		List<List<Integer>> list = new ArrayList<List<Integer>>();

		int left = 1;// 由题意：1 <= x, y <= 1000
		int right = 1000;// 由题意：1 <= x, y <= 1000
		while (left <= 1000 && right >= 1) {

			int r = customfunction.f(left, right);
			List<Integer> temp = new LinkedList<Integer>();
			if (r == z) {
				temp.add(left);// 添加到临时集合中
				temp.add(right);// 添加到临时集合中
				list.add(temp);// 添加到结果集中
				// 记得把这两个数改变
				right--;
				left++;

			} else if (r > z) {// 结果比目标要大,边界向中间靠齐
				right--;
			} else {
				left++;
			}
		}

		return list;
	}
```

# 二分查找：
确定一个变量，另一个变量通过二分查找确定
消耗的时间相对较少
```
public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
		List<List<Integer>> list = new ArrayList<List<Integer>>();

		// 需要用到4 个变量控制
		// i 控制一个不变的数，三个用来二分查找匹配的数
		// 两个循环
		for (int i = 1; i <= 1000; i++) {
			if (customfunction.f(i, 1) > z) {
				break;
			}
			int left = 1;
			int right = 1000;
			//通过边界确定跳出循环
			while (left <= right) {
				int mid = (right + left) / 2;

				// 计算x,y 的结果
				int result = customfunction.f(i, mid);

				if (result == z) {
					List<Integer> temp = new ArrayList<Integer>();
					temp.add(i);
					temp.add(mid);
					list.add(temp);
					break;
				} else if (result > z) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			}
		}
		return list;

	}
```
*一起加油，一起写题解*

![战盟图片1572788138.jpg](https://pic.leetcode-cn.com/beec6a05e2726d1a6704fddfc6e80af30c0de6aa3ff9dad62d8973d1a0e01585-%E6%88%98%E7%9B%9F%E5%9B%BE%E7%89%871572788138.jpg)

准备两数组，一个放原始价格，一个放对应的输出结果。
当前原始数组的最后一个元素小于等于新元素的时候，拿之前算好的输出结果，中间就不需要重复计算了，直接跳到前面的位置找对应位置的元素 是否满足，重复这个过程，直到不满足条件。将整个过程的结果累加，作为新输入的结果


class StockSpanner {

		private List<Integer> list;
		private List<Integer> rests;

		public StockSpanner() {
			list = new ArrayList<>();
			rests = new ArrayList<>();
		}

		public int next(int price) {

			int va = 1;
			for (int i = list.size() - 1; i >= 0;) {
				if (list.get(i) > price) {
					break;
				}
				int dqwd = rests.get(i);
				va += dqwd;
				i -= dqwd;
			}
			list.add(price);
			rests.add(va);

			return va;
		}
	}
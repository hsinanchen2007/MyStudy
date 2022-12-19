使用单调栈，且单调栈中元素从大到小排序，根据题目含义，如果插入的元素是x，x之前若存在y大于x，则y之前小于x的元素都无法统计，这很符合单调栈的含义，每次插入元素都要先遍历检查前面的元素，如果比他小就pop掉（看不见）
代码如下：
class StockSpanner {
public:
	//排序即可;
	stack<int> prices;
	stack<int> weight;
	int day;
	StockSpanner() {
		day = 1;
		//记录当前日期;
	}

	int next(int price) {
		int w = 1;
		while (!prices.empty() && prices.top() < price) {
			prices.pop();
			auto it = weight.top();
			w += it;
			weight.pop();
		}
		prices.push(price);
		weight.push(w);
		return w;
	}
};

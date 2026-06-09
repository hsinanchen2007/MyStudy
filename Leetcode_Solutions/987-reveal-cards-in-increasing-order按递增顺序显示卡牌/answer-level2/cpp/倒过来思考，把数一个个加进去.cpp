先从大到小排序，然后用双向队列，将第一个数加进去。
然后对排好序的deck从第二个数开始循环，将队列最后一个数放到最前面，再将新数加到最前面。
实现过程中间发现个问题，排序用sort函数时自己写的cmp要么只能定义在类外，要定义在类内只能加static，有大佬告诉我为什么吗？
```
class Solution {
public:
	static bool cmp(int a,int b){
		return a > b;
	}

	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		sort(deck.begin(), deck.end(), cmp);
		deque<int> tmp;
		tmp.push_front(deck[0]);
		for (int i = 1; i < deck.size(); i++){
			tmp.push_front(tmp.back());
			tmp.pop_back();
			tmp.push_front(deck[i]);			
		}
		vector<int> res(tmp.begin(),tmp.end());
		return res;
	}
};
```

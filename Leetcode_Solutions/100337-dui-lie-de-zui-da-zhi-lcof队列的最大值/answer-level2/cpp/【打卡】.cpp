太菜
参考了剑指OFFER~
```
class MaxQueue {
private:
	struct Node{
		int val;
		int index;
		Node(int v, int i):val(v), index(i){}
	};
	deque<Node> data;
	deque<Node> maxData;
	int curIndex;

public:
    MaxQueue() {
		curIndex = 0;
    }
    
    int max_value() {
		if(maxData.empty())
			return -1;
		return maxData.front().val;
    }
    
    void push_back(int value) {
		while(!maxData.empty() && maxData.back().val <= value)
			maxData.pop_back();
			
		Node node(value, curIndex++);
		data.push_back(node);
		maxData.push_back(node);
    }
    
    int pop_front() {
		if(data.empty())
			return -1;
		if(data.front().index == maxData.front().index)
			maxData.pop_front();
		int value = data.front().val;
		data.pop_front();
		return value;
    }
};
```

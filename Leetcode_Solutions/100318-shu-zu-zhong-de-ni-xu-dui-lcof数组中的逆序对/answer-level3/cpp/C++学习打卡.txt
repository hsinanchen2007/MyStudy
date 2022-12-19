### 解题思路
此处撰写解题思路

### 代码

```cpp
struct node {
	int data;
	int index;
	int inversionPairCount;
	node() :data(0), index(0), inversionPairCount(0) {};
	node(int a, int b, int c) :data(a), index(b), inversionPairCount(c) {};
};

class Solution {
private:
	void devide(vector<node>& myData, int left, int right) {
		if (left == right) { return; }
		int mid = (left + right) / 2;
		devide(myData, left, mid);
		devide(myData, mid+1, right);
		merge(myData, left, mid, right);
		return;
	}

	void merge(vector<node>& myData, int left, int mid, int right) {
		vector<node> temp(right - left + 1);
		int i = left, j = mid+1, k = 0;
		while (i <= mid && j <= right) {
			if (myData.at(i).data <= myData.at(j).data) {
				temp.at(k++) = myData.at(i++);
			}
			else {
				myData.at(j).inversionPairCount += mid - i + 1;
				temp.at(k++) = myData.at(j++);
			}
		}
		while (i <= mid) {
			temp.at(k++) = myData.at(i++);
		}
		while (j <= right) {
			temp.at(k++) = myData.at(j++);
		}
		//将temp中排好序的数据拷贝到myData中
		for (int pos = 0; pos <= right-left; pos++) {
			myData.at(pos+left) = temp.at(pos);
		}
		return;
	}

public:
	int reversePairs(vector<int>& data) {
		if (data.size() <= 1) { return 0; }
		vector<node> myData(data.size());
		for (int i = 0; i < data.size(); i++) {
			myData.at(i) = node(data.at(i), i, 0);
		}
		devide(myData, 0, myData.size() - 1);
		int ans = 0;
		for (int i = 0; i < myData.size(); i++) {
			ans += myData.at(i).inversionPairCount;
		}
		return ans;
	}
};

```
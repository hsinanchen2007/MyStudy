#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class MedianFinder 
{
public:
	/*
	因为q_1和q_2分别为最大堆和最小堆，因此下面的代码，既能严格控制size()相差为1，
	又能保证，top()大小
	*/
	void addNum(int num)
	{
		if (q_1.empty())     //初始push进q_1或者q_2都可
			q_1.push(num);
		else if (q_2.size() <= q_1.size())
		{
			if (num >= q_1.top()) 
				q_2.push(num);
			if (num < q_1.top())
			{
				q_2.push(q_1.top());
				q_1.pop();
				q_1.push(num);
			}
		}
		else if(q_2.size() > q_1.size())
		{
			if (num < q_2.top()) 
				q_1.push(num);
			else
			{
				q_1.push(q_2.top());
				q_2.pop();
				q_2.push(num);
			}
		}
	}

	double findMedian()
	{
		if (q_1.size() < q_2.size()) return (double)q_2.top();
		else if (q_1.size() > q_2.size()) return (double)q_1.top();
		else return (q_1.top() + q_2.top()) / 2.0;
	}
private:
	priority_queue<int> q_1;  //最大堆
	priority_queue<int, vector<int>, greater<int> > q_2; //最小堆
};
int main()
{
	MedianFinder  M;
	M.addNum(1);
	M.addNum(2);
	M.addNum(3);
	double r = M.findMedian();
	cout << r << endl;
	system("pause");
	return 0;
}

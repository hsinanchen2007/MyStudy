class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int size = gas.size();
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < size; i++)
		{
			sum1 += gas[i];
			sum2 += cost[i];
		}
		if (sum1 < sum2)
		{
			return -1;
		}
		int current = 0;  //表示当前的剩余油量
		int start = 0;
		int num = 0;

		for (int i = 0; num < size; i = (i + 1) % size)
		{
			current += gas[i] - cost[i];
			++num;
			if (current < 0)
			{
				num = 0;
				start = (i + 1) % size;
				current = 0;
			}
		}
		return start;
	}
};


//这里我选择用第一个gas[i]>cost[i]的点作为start点
//思路和大部分大神的思路差不多
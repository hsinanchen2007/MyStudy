不能被三整除的， 余数只能为 1， 2
余数为1 ： 减去一个余数为1的， 或减去两个余数为2的；
余数为2： 减去两个余数为1的，或减去两个余数为2的；

也就是，要找到两个余数为1，两个余数为2， 并且越小越好。

也可以用O(n)的解法顺序遍历，然后找最小两个。

```
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
		
		int sum = 0;
		
		sum = accumulate(nums.begin(), nums.end(), sum); //总和
		
		int r = sum % 3;
		
		if(r == 0)
		{
			return sum;
		}
		
		priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end()); //小顶堆。
		
		int ret_1 = sum, ret_2 = sum;
		
		int num_1 = 0, num_2 = 0;
		
		if(r == 1)
		{
			num_1 = 1;
			num_2 = 2;
		}
		else
		{
			num_1 = 2;
			num_2 = 1;
		}
		
		while(!pq.empty() && (num_1 || num_2))
		{
			int temp = pq.top();
			pq.pop();
			
			if(num_1 && temp % 3 == 1)
			{
				--num_1;
				ret_1 -= temp;
			}
			else if(num_2 && temp % 3 == 2)
			{
				--num_2;
				ret_2 -= temp;
			}
		}

        if(num_1) //出来了还得检查是否完成调整
        {
            ret_1 = 0;
        }

        if(num_2)
        {
            ret_2 = 0;
        }	

		return max(ret_1, ret_2);	
    }
};
```





class Solution {
public:
	void mReves(vector<int>& target , int start , int end)
	{
		while (start <= end)
		{
			int tmp = target[end];
			target[end] = target[start];
			target[start] = tmp;

			start++;
			end--;
		}		
	}

	void rotate(vector<int>& nums, int k) 
	{    
		if (nums.size() <= 1) return;
		k = k % (nums.size());
		mReves(nums, 0, nums.size()-k-1);
		mReves(nums, nums.size() - k, nums.size() - 1);
		mReves(nums, 0, nums.size() - 1);	
	}
};
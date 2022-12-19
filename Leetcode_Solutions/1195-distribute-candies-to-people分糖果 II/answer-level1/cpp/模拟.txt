class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int>res(num_people, 0);
		int i = 0;
		int a = 1;
		while (candies > 0)
		{
			for (int i = 0; i < num_people; i++)
			{
				if (candies >= a)
				{
					res[i] += a;
					candies -= a;
                    a++;
				}
				else
				{
					res[i] += candies;
					candies = 0;
				}
			}
		}
		return res;
	}
};
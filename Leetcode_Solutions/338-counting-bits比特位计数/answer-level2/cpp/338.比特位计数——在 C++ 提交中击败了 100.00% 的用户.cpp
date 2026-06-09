![Image 1.png](https://pic.leetcode-cn.com/92b350057129a4029eb7489c426eba66d68413b0b79032141349a735abc43c0b-Image%201.png)
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> ans;
		ans.push_back(0);
		if (num > 0)
		{
			vector<int> temp = ans;
			int count = 1;
			while (count <= num)
			{
				for (int i = 0; i < temp.size(); i++)
				{
					ans.push_back(temp[i] + 1);
					count++;
					if (count > num)
						break;
				}
				temp = ans;
			}
		}
		return ans;
	}
};

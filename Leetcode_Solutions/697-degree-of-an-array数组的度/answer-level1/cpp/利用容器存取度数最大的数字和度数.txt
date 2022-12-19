class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		int a = nums.size();
		if (a == 1)return 1;
		vector<int>q = nums;
		sort(q.begin(), q.end());
		vector<int>b;//度最大的数字
		vector<int>c;//度数
		b.push_back(q[0]);
		c.push_back(1);
		for (int i = 1; i < a; i++) {
			if (q[i] == b[b.size() - 1]) {
				c[c.size() - 1]++;
				if (c.size() >=2) {
					if (c[c.size() - 1] > c[c.size() - 2]) {
						int m_b = b[b.size() - 1];
						int m_c = c[c.size() - 1];
						b.clear();
						c.clear();
						b.push_back(m_b);
						c.push_back(m_c);
					}
				}
			}
			else {
				if (c.size() >= 2) {
					if (c[c.size() - 1] <c[c.size() - 2]) {
						b.pop_back();
						c.pop_back();
					}
				}
				b.push_back(q[i]);
				c.push_back(1);
			}
			if (i == a - 1) {
				if (c.size() >= 2) {
					if (c[c.size() - 1] <c[c.size() - 2]) {
						b.pop_back();
						c.pop_back();
					}
				}
			}
		}
		if (b.size() == a) { return 1; }
		int qu=0,len=0,m_len=INT_MAX;
		for (int i = 0; i < b.size(); i++) {
			qu = 0, len = 0;
			for (int j = 0; j < a; j++) {
				if (nums[j] == b[i]) {
					qu++;
				}
				if (qu != 0) {
					len++;
					if (qu == c[i]) { break; }
				}
			}
			m_len = min(m_len, len);
		}
		return m_len;
	}
};
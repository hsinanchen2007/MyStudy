### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	vector<int> change(int num) {
		vector<int> res;
		while (num > 0) {
			res.push_back(num % 2);
			num /= 2;
		}
		return res;
	}
	int reverseBits(int num) {
		int count1 = 0;
		int count0 = 0;
		stack<int> s;
		vector<int> res;
		int flag = 0;
		while (num>0) {
			int n = num & 1;
			if (n == 1) {
				count1++;
				num = num >> 1;
			}
			else if (n==0&&count0==0) {
				flag = 1;
				count0++;
				count1++;
				num = num >> 1;
				s.push(num);
			}
			else if (n==0) {
				//count0++;
				res.push_back(count1);
				count1 = 0;
				num = s.top();
				s.pop();
				//count1 = 0;
				count0 = 0;
			}		
		}
		
		res.push_back(flag==0?(count1+1):count1);
		count1 = 0;
		count0 = 0;
		if (!s.empty()) {
			num = s.top();
			s.pop();

			while (num>0) {
				int n = num & 1;
				if (n==1) {
					count1++;
				}
                num = num >> 1;
			}
			res.push_back(count1 + 1);
		}
		return *max_element(res.begin(),res.end());
	}
};
```
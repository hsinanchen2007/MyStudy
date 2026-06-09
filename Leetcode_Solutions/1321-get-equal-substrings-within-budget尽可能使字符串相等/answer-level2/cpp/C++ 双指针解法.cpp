![ans.jpg](https://pic.leetcode-cn.com/29e49523a16abc5d5a045f2d09450f5a2f70df77a5d908b3d6ec23ac5aca2be7-ans.jpg){:width=400}
如图，把 $s$ 串和 $t$ 串对应位置字符求差的绝对值 $abs(s[i]-t[i])$ 后可以得到一个新数组
求这个数组中一段连续子数组的长度, 要求子数组的和 `<=m &&` 子数组长度最长
就可以直接双指针了
有不对的地方请大佬指出
```cpp [-C++]
#include <stack>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#define debug
using namespace std;

int abs(int x) { return x > 0 ? x : -x; }
//#define max(x,y) (x > y ? x : y)
class Solution {
public:
    int equalSubstring(string s, string t, int m) {
        int ret = 0;
		if(s.empty() || t.empty()) return ret;
		
		vector<int> arr(s.length(), 0);
		for(int i=0; i<s.length(); i++)
			arr[i] = abs(s[i] - t[i]);
		int i = 0, j = 0, sum = 0;
		while(i < (int)s.length()) {
			while(j<(int)s.length() && sum+arr[j]<=m) {
				sum += arr[j];
				j++;
			}
			ret = max(ret, j-i);
			sum -= arr[i];
			i++;
		}
		
		return ret;
    }
};

#ifdef debug233333
int main(void) {
	freopen("test", "r", stdin);
	string s = "abcd", t = "bcdf";
	int cost = 3;
	Solution sl;
	cout << sl.equalSubstring(s, t, cost) << endl;
	s = "abcd", t = "cdef", cost = 3;
	for(int i=0; i<s.length(); i++) printf("[%d]", s[i]);
	printf("\n");
	for(int i=0; i<t.length(); i++) printf("[%d]", t[i]);
	printf("\n");

	cout << sl.equalSubstring(s, t, cost) << endl;
	s = "abcd", t = "acde", cost = 0;
	for(int i=0; i<s.length(); i++) printf("[%d]", s[i]);
	printf("\n");
	for(int i=0; i<t.length(); i++) printf("[%d]", t[i]);
	printf("\n");

	cout << sl.equalSubstring(s, t, cost) << endl;
	s = "krrgw", t = "zjxss", cost = 19;
	for(int i=0; i<s.length(); i++) printf("[%d]", s[i]);
	printf("\n");
	for(int i=0; i<t.length(); i++) printf("[%d]", t[i]);
	printf("\n");
	cout << sl.equalSubstring(s, t, cost) << endl;
	return 0;
}
#endif

```

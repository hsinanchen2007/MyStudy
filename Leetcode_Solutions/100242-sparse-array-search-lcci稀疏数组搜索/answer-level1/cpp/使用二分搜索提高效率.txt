本来信心满满准备一次提交就过的，结果还是用了3次 …………

相对于普通二分查找，还需要注意如下几点：

1. left 和right可能对应的是空值，还需要人为的判断并缩小边界。
2. 计算出的mid可能对应的也是空值，这里的策略是将mid向右偏，直到不为空或者接触到右边界，如果到达右边界，说明mid和right这一段没有我们想要的值，所以将right更新为最初的mid即可。

细节比较多,注意盯住边界。

```c++
class Solution {
public:
	int findString(vector<string>& words, string s) {
		int left = 0, right = words.size() - 1;
		while (left <= right) {
			if (words[left].size() == 0) {
				left++;
				continue;
			}
			if (words[right].size() == 0) {
				right--;
				continue;
			}
			int mid = (right + left) / 2;
			while (words[mid].size() == 0) {
				mid++;
				if (mid == right) {
					right = (right + left) / 2;
					continue;
				}
			}

			if (words[mid] == s)
				return mid;
			else if (words[mid] > s) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return -1;
	}
};

```

![1.jpg](https://pic.leetcode-cn.com/df7ab756d3f2a130a69e84e4831f58c7b1e95684e332d5f783f4a84ee445b3bf-1.jpg)

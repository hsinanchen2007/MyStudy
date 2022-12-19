![image.png](https://pic.leetcode-cn.com/f937fed475d8c577ae2997ad14ba0905a07fc87ffe3386a0aa00478aebf31731-image.png)

解题思路：先将数组排序，用首个元素和后续元素对比并计数，将个数分别存入set和vector中，对比容量即可知道个数是否有相同。

bool uniqueOccurrences(vector<int>& arr) {
	int count = 1;
	vector<int> num;
	set<int>    com;
	sort(arr.begin(), arr.end());
	while(!arr.empty()) {
		for (int j = 0; j<arr.size(); ++j) {
            if(j ==0) continue;
			if (arr[0] == arr[j]) ++count;

		}
       arr.erase(arr.begin(),arr.begin()+count);
		num.push_back(count);
		com.insert(count);
		count = 1;
	
	}
	if (num.size() == com.size()) return true;
	return false;
}
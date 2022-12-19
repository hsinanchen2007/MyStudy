1. 开始标记为零，遍历，map里不存在则存入字符及下标；
2. 存在则计算长度，当前下标-开始标记，大于置换；
3. 若存在的map中字符下标大于开始标记，更新开始标记；
4. 更新map。

```
int mylengthOfLongestSubstring(string s) {
	map<char, int> re;
	int max = 0;
	int start = 0;
	if (s.empty())
		return 0;
	if (s.size()==1){
		return 1;
	}
	map<char, int>::iterator iter;
	int i;
	for (i = 0; i < s.size(); i++){
		iter = re.find(s[i]);
		if (re.end() == iter){
			re.insert(pair<char, int>(s[i], i));
		}
		else{
			int temp;
			if ((temp = i - start) > max)
				max = temp;
			if (start < iter->second + 1)
				start = iter->second+1;
			re.erase(iter);
			re.insert(map<char, int>::value_type(s[i], i));
		}
	}
	if (i-start > max)
		max = i - start;
	return max;
}
```


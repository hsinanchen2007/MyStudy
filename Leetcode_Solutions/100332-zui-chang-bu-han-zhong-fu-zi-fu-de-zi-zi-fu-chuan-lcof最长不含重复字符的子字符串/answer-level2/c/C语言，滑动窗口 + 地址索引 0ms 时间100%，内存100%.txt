
![48.PNG](https://pic.leetcode-cn.com/8c2187c7294ed90beb1a4acf0dccd9827829d4eedfcbd190896586cd5ec31db5-48.PNG)
```
int lengthOfLongestSubstring(char* s) {
	int left, right, maxlen = 1, len, i, nextindex;
	int index[256] = { 0 };

	len = strlen(s);
	if (len < 2)return len;

	left = 0;
	right = 0;
	memset(index, 0xff, sizeof(index));
	index[s[left]] = 0;
	right = 1;
	while (right < len) {
		if (index[s[right]] == 0xffffffff) { //Î´Ôø³öÏÖ¹ý
			index[s[right]] = right;  //¼ÇÂ¼³öÏÖµÄÎ»ÖÃ£»
			if (right - left + 1 > maxlen) {
				maxlen = right - left + 1;
			}
		}
		else { //³öÏÖ¹ý£»
			nextindex = index[s[right]] + 1;
			for (i = left; i < nextindex; i++) {
				index[s[i]] = -1;
			}
			left = nextindex < right ? nextindex : right;
			//Ìø¹ýÈ¥£¬Ò²Òª¸üÐÂbitmap
			index[s[right]] = right;
		}
		right++;
	}
	return maxlen;
}
```

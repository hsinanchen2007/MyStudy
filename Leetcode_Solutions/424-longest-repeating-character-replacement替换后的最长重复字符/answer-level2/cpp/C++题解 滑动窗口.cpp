滑动窗口题目    

    用数组记录下当前窗口各个字母的总数和当前窗口中出现次数最多的字母的数量
    当：窗口大小 > (最大字母数-k)时扩张移动窗口，否则扩张窗口
    当窗口移动到字符串末端后结束，答案为最后窗口的大小
```
int characterReplacement(string s, int k) {
        int len = s.size();
        int left = 0, right = 0, maxlen = 0, ch[26] = {0}, ans = 0;
        for(right = 0;right < len;right++, ans++){
		ch[s[right] - 'A']++;
		for(int i=0;i<26;i++){
			maxlen = max(maxlen, ch[i]);
		}
		if((right - left + 1) > (maxlen + k)){
			ch[s[left]-'A']--;
			left++;
			ans--;
		    }
        }
        return ans;
}
```
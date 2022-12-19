## 思路
因为题目给出了字符范围，所以我们可以用一个循环加count统计第一个出现的字符的个数，然后进行对比即可
```
class Solution {
public:
	vector<int > getCount(vector<string >& v) {
		vector<int > qVector;
        int r;
        for (int i = 0; i < v.size(); i++) {
        	for (char c = 'a'; c <= 'z'; c++) {
        		if (r = count(v[i].begin(), v[i].end(), c)) {
        			qVector.push_back(r); 
        			break;
				}
			}
		}
		return qVector;
	}
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        // 题目给出了长度都大于0，所以干脆可以不判断非法情况
        vector<int > qCount = getCount(queries);
        vector<int > wCount = getCount(words);
        vector<int > result;
        int qLen = qCount.size(), wLen = wCount.size(), t;
        int maxNum = wCount[0];
        // 标记一个最大值，防止无用的循环 
        for (int i = 1; i < wLen; i++) maxNum = maxNum < wCount[i] ? wCount[i] : maxNum;
        // 对比 
		for (int i = 0; i < qLen; i++) {
			t = 0;
			if (qCount[i] < maxNum) {
				for (int j = 0; j < wLen; j++) {
					if (qCount[i] < wCount[j]) {
						t++;	
					}
				}
			}
			result.push_back(t); 
		} 
		return result;
    }
};
```

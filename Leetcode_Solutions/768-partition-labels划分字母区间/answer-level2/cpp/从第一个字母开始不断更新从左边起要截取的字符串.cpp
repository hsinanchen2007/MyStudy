不断更新从左边起要截取的字符串（代码中该字符串为tmp），初始状态为第一个字符，更新的条件是截取字符串中某字符在字符串后出现了，说明至少还要截取到最后出现该字符的那个位置。如果截取字符串中没有任何字符在之后出现说明这个截取的字符串符合题目要求划分的片段，且是最短的。然后就是对剩下的串继续划分。
由于题目要求把整个字符串全都划分，所以这样从左起开始的贪心的划分方法是有效的。
代码写的不太好，还用了两个bool型的标记。
```
class Solution {
public:
	vector<int> partitionLabels(string S) {
		vector<int> res;
		int pos = 0;	//pos记录要切割的字符串的最后下标。
		string f = "";	//f记录查看过的字母
		while (S != "") {
			string tmp = S.substr(0, 1);	//tmp记录暂时切割的字符串
			bool flag = true;
			while (flag) {
				bool flag2 = false;
				for (int i = 0; i < tmp.length(); i++) {	//扫描tmp
					if (f.find(tmp[i]) == string::npos) {
						f.push_back(tmp[i]);
						if (S.rfind(tmp[i]) > pos) {	//当这种情况出现时，生成新的tmp，重新扫描新的tmp
							pos = S.rfind(tmp[i]);
							tmp = S.substr(0, pos + 1);
							flag2 = true;
							break;
						}
					}
				}
				if(!flag2)	//tmp扫描最后也没有新的tmp出现
					flag = false;
			}
			S = S.substr(pos + 1);
			res.push_back(pos + 1);
			pos = 0;
			f = "";
		}
		return res;
	}
};
```

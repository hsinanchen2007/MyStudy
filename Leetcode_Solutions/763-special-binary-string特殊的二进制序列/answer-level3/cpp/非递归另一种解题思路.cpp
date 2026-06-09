# 解题思路
（1）从位置`i`（初始`i=0`）开始扫描字符串，寻找两个连续的特殊字串`substr1`与`substr2`，若 **找到** 则执行**步骤**（2），若 **未找到** 执行**步骤**（3）；
（2）判断是否要交换`substr1`与`substr2`，若`true`则交换`并将i=0`继续执行（1）；若`false`执行**步骤**（3）；
（3）继续从位置`i`处寻找新的（**更长的**）`substr1`与`substr2`；若 **找到** 则执行**步骤**（2），若 **未找到** 执行**步骤**（4）；
（4）`i++`后执行**步骤**（1）
（5）直到`i=S.length()`，`return`; 
# 源代码：
```
class Solution {
private:
	bool isSwap(string a, string b)//判断是否交换
	{
		int minSize = a.size()<b.size() ? a.size() : b.size();
		for (int i = 0; i<minSize; i++){
			if (a[i]<b[i]){
				return true;
			}
			else if (a[i]>b[i]){
				return false;
			}
		}
		return false; //equal
	}
	bool findMinSubSpstr(string S, string& outSub, int& outLen, int len = 0){//获取大于len的最短的特殊子串
		string tempSub;
		int Count1=0, Count0 = 0;
		int subLen = 0;
		for (int i = 0; i<S.size(); i++){
			if (Count0>Count1){
				return false;
			}
			if (Count1 == Count0 && subLen > len){
				outSub = S.substr(0, subLen);
				outLen = subLen;
				return true;
			}
			if (S[i] == '1'){
				Count1++;
			}
			else{
				Count0++;
			}
			subLen++;
		}
		if (Count1 == Count0 && subLen > len){
			outSub = S.substr(0, subLen);
			outLen = subLen;
			return true;
		}
		return false;
	}

public:
	string  makeLargestSpecial(string S) {
		int prefix1, suffix1, prefix2, suffix2 = 0;
		int subStrLen1=0, subStrLen2=0,lastSubLen1=0,lastSubLen2 = 0;
		string substr1, substr2, tempStr;
		string outString = S;
		string remainStr;
		bool hasSwap = false;
		for (int i = 0; i<S.length(); i++){
			tempStr = outString.substr(i);
			if (i>0){
				remainStr = outString.substr(0, i);
			}
			while (1){
				if (findMinSubSpstr(tempStr, substr1, subStrLen1, lastSubLen1)){//find first 
					lastSubLen1 = subStrLen1;
					lastSubLen2 = 0;
					if (findMinSubSpstr(tempStr.substr(subStrLen1), substr2, subStrLen2, 0)){//find second
						if (isSwap(substr1, substr2)){//判断是否交换
							//swap
							tempStr = substr2 + substr1 + tempStr.substr(subStrLen1 + subStrLen2);
							//swap 后重新开始;直到没有swap
							hasSwap = true;
							break;
						}
					}
					else{
						break;
					}
				}
				else{
					break;
				}
			}
			subStrLen1 = subStrLen2 = lastSubLen1 = lastSubLen2 = 0;
			outString = remainStr + tempStr;
			//swap 后重新开始;直到没有swap
			if (hasSwap){
				i = -1;
				remainStr = "";
				hasSwap = false;
			}
		}
		return outString;
	}
};
```
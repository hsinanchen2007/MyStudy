#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<int> maxDepthAfterSplit(string seq) {
		if (seq.size() == 0) { return vector<int>{}; }
		vector<int>res(seq.size());
		int index1(0);
		int index2(0);//两个对象各需要多少右括号
		for (int i = 0; i < seq.size(); ++i) {
			if (seq[i] == '(') {
				if (index1 == 0) { res[i] = 0; ++index1; }
				else {
					if (index2 == 0) { res[i] = 1; ++index2;}
					else {
						if (index1 > index2) { res[i] = 1; ++index2; }
						else { res[i] = 0; ++index1; }
					}
				}
			}
			else {
				if (index1 < index2) { res[i] = 1; --index2; }
				else { res[i] = 0; --index1; }
			
			}
		}
		return res;
	}
};
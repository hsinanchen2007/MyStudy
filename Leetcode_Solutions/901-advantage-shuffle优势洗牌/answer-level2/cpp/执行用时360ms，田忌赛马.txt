```
class Solution {
public:
	vector<int> advantageCount(vector<int>& A, vector<int>& B) {
		vector<int> res(A.size(), 0);
		multimap<int, int> m;	//map记录B中各个值对应的位置。
		for (int i = 0; i < B.size(); i++)
			m.insert(make_pair(B[i], i));
		//给A、B排序
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		vector<int>::iterator t1 = A.begin();
		vector<int>::iterator r1 = B.begin();
		vector<int>::iterator r2 = B.end() - 1;
		int insertVal = 0;
		//田忌赛马
		while (t1 !=A.end()) {
			if (*t1 <= *r2) {	//A中最小值小于等于B中最大值
				if (*t1 > *r1) {	//A中最小值能赢过B中最小值，可以赢		
					//cout << "A:" << *t1 << "-" << "B:" << *r1 << endl;;
					insertVal = *r1;
					++r1;
				}
				else {		//A中的最小值小于等于B中的最小值，无论如何赢不了，那就和B的最大值配对，下等马对上等马
					//cout << "A:" << *t1 << "-" << "B:" << *r2 << endl;;
					insertVal = *r2;
					--r2;					
				}				
			}
			else {		//A中最小值大于B中最大值，可以赢。如果A中最小值大于B中最大值，也就随便排列了
				insertVal = *r2;
				//cout << "A:" << *t1 << "-" << "B:" << *r2 << endl;
				--r2;
			}
			multimap<int, int>::iterator it= m.find(insertVal);
			res[it->second] = *t1;
			m.erase(it);
			++t1;
		}
		return res;
	}
};
```

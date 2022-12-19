```
class Solution {
public:
	void merge(vector<string>& v, string str) {
		int count = 0;
		vector<string> s;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < str.size(); j++) {
				string tmp = v[i];
				tmp.append(1, str[j]);
				s.push_back(tmp);
			}
		}
		v = s;
	}
	vector<string> letterCombinations(string digits) {
		map<char, string> a;
		a.insert({ '1',"" });
		a.insert({ '2',"abc" });
		a.insert({ '3',"def" });
		a.insert({ '4',"ghi" });
		a.insert({ '5',"jkl" });
		a.insert({ '6',"mno" });
		a.insert({ '7',"pqrs" });
		a.insert({ '8',"tuv" });
		a.insert({ '9',"wxyz" });
		vector<string> v;
        vector<string> result;
        if(digits.empty())
            return result;
		for (auto e : digits) {
			v.push_back(a[e]);
		}
		for (auto c : v[0]) {
			string str;
			stringstream stream;
			stream << c;
			str = stream.str();
			result.push_back(str);
		}
		for (int i = 1; i < v.size(); i++) {
			merge(result, v[i]);
		}
		return result;
	}
};
```

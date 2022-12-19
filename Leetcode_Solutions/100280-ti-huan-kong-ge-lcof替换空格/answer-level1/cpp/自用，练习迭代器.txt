顺便练习容器的函数用法，自用

class Solution {
public:
    string replaceSpace(string s) {
		string::iterator it = s.begin();
		vector<int> pos;
		int i=0;
		while (it != s.end())
		{
			if (*it == ' ') pos.push_back(i);
			i++;
			it++;
		}
		
		vector<int>::reverse_iterator ite;
		vector<int> pos_res;
		for (ite = pos.rbegin(); ite != pos.rend(); ite++) {
			pos_res.push_back(*ite);
		}
		for (auto i : pos_res) {
			s.replace(i, 1, "%20");
			
		}
		return s;
    }
};
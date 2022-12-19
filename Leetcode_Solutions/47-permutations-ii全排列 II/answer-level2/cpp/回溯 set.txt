emmmm偷懒用了set去重，所以只超过了5%的用户
set<vector<int>>的遍历是这样的：
set<vector<int> >::iterator it;
	for (it = ans.begin(); it != ans.end(); it++) {
		cout << it->size() << "  ";
		vector<int>temp = *it;
		res.push_back(temp);
		/*for (int i = 0; i < temp.size(); i++)
		{
			cout << temp[i] << " ";
		}
		cout << "\n";*/
	}
return res;
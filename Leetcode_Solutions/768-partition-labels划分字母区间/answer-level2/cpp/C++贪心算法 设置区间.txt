bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    return a.first<b.first;
}
class Solution {
public:
vector<int> partitionLabels(string S) {
	vector<pair<int, int>>vp;//存储各个字符区间的数组
	for (char c = 'a'; c <= 'z'; c++) {
		int first = 0;
		int second = 0;
		first = S.find_first_of(c);
		if (first == -1) {
			continue;
		}
		second = S.find_last_of(c);
		vp.push_back(make_pair(first, second));
		sort(vp.begin(), vp.end(), cmp);//区间从小到大排序
	}
	vector<int>result;
	int begin = vp[0].first;
	int end = vp[0].second;
	for (int i = 1; i < vp.size(); i++) {
		if (vp[i].first < end) {
			if (vp[i].first > begin && vp[i].second > end) {
				end = vp[i].second;
			}
			if (vp[i].first<begin && vp[i].second>begin && vp[i].second < end) {
				begin = vp[i].first;
			}
		}
		else {
			result.push_back(end - begin + 1);
			begin = vp[i].first;
			end = vp[i].second;
		}
	}
	result.push_back(end - begin + 1);
	return result;
}
};
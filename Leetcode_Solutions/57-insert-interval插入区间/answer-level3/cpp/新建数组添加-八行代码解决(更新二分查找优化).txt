效率不高，如果在原数组中就地合并，时间和内存应该可以继续优化。
```
class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> > &A, vector<int> &a) {
		vector<vector<int> > v;
		auto i=A.begin();
		for(; i!=A.end() && a[0]>(*i)[1]; v.push_back(*i++));
		for(; i!=A.end() && a[1]>=(*i)[0]; ++i)
			a={min(a[0],(*i)[0]), max(a[1],(*i)[1])};
		v.push_back(a);
		v.insert(v.end(),i,A.end());
		return v;
    }
};
```

方法2,直接在原数组中就地合并.二分查找找到需要合并的起始位置,然后就地合并,删除已经合并的区间,插入合并后的单个区间.
```
class Solution {
	static bool comp(const vector<int> &a, const vector<int> &b){
		return a[1]<b[0];
	}
public:
	vector<vector<int> > insert(vector<vector<int> > &A, vector<int> &a) {
		int i=lower_bound(A.begin(),A.end(),a,comp)-A.begin(), j=0;
		for(j=i; j<A.size() && a[1]>=A[j][0]; ++j)
			a={min(a[0],A[j][0]), max(a[1],A[j][1])};
		A.insert(A.begin()+j,a);
		A.erase(A.begin()+i, A.begin()+j);
		return A;
	}
};
```

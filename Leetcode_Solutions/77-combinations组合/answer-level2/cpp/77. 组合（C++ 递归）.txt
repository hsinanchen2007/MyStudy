# 77. 组合
**代码实现：**
```
class Solution {
public:
	void combineRecrusion(int begin,int end,int k,vector<int> rst_item,vector<vector<int>> &rst){
		if ( k <= 0 ) {
			rst.push_back(rst_item);
			return;
		} 
		if ( begin > end ) return;
		for( int i = begin; i <= end; ++i ){
			vector<int> temp_item = rst_item;
			temp_item.push_back(i);
			combineRecrusion(i+1,end,k-1,temp_item,rst);
		}
		return;
	}
	
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> rst;
		vector<int> rst_item;
		combineRecrusion(1,n,k,rst_item,rst);
		return rst;
    }
};
```

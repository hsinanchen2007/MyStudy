按照会议结束的时间排序，将先结束的放在前面
按照排好的顺序遍历每一个时间区间，选择后做好标记，一个区间只能选择一个数（代表第几天数）
```
class Solution {
public:
bool vis[100010] = {false};
static bool cmp(vector<int> v1,vector<int>v2){
	//按照会议结束时间来排序
	if(v1[1] != v2[1]) return v1[1] < v2[1];
	else return v1[0] < v2[0]; 
}
    int maxEvents(vector<vector<int>>& events) {
       sort(events.begin(),events.end(),cmp);
	    int count  = 0;
	    for(int i=0; i<events.size(); i++){
		    for(int j=events[i][0];j<=events[i][1];j++){
			    if(vis[j]==false){
				    vis[j] = true;
				    count++;
				    break;
			    }
		    }
	    }
	    return count;	 
    }
};
```

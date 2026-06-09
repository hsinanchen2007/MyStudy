### 解题思路
此处撰写解题思路

参考官方解题思路第二次尝试

新元素为[a,b];
新建集合 ans；
遍历原集合：
1.若集合元素右端小于a，区间无交集，直接插入ans；
2.若集合元素左端大于b，区间无交集
****1）若新元素未插入，集合后面也不会出现插入位置，此时需插入
****2）插入集合元素
3.若区间有交集
****1）若元素未插入 先将元素插入；
****2）更新元素左右端点值
	ans[t][0]=min(intervals[i][0],ans[t][0]);
	ans[t][1]=max(intervals[i][1],ans[t][1]);
遍历结束；
遍历结束时若 新元素未插入，则插入原集合末尾；


执行用时 :
20 ms, 在所有 C++ 提交中击败了63.28%的用户
内存消耗 :
10.7 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
		if(intervals.size()==0){//特殊情况 原集合为空 
			intervals.push_back(newInterval);
			return intervals;
		}
		vector<vector<int> > ans;
		int t=-1;//记录插入位置 
		for(int i=0;i<intervals.size();i++){
			if(newInterval[0]>intervals[i][1]){// 比 newInterval 左端小的直接插入 
				ans.push_back(intervals[i]);
			}else if(intervals[i][0]>newInterval[1]){//比 newInterval 右端大的直接插入
				if(t<0) ans.push_back(newInterval),t++;
				ans.push_back(intervals[i]);
			}else{
				if(t<0){ 
					t=ans.size();
					ans.push_back(newInterval);
				}
				ans[t][0]=min(intervals[i][0],ans[t][0]);
				ans[t][1]=max(intervals[i][1],ans[t][1]);
			}
		}
		if(t<0){//若没有插入 
				ans.push_back(newInterval);
		} 
		
		return intervals=ans;
    }
};
```
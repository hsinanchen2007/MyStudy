### 解题思路
对于新区间[a,b]，
1.从原集合中找到第一个元素x，使得a<=intervals[x][1]，没有则x=-1
2.从原集合中找到第一个元素y，使得b<=intervals[y][0]，没有则y=-1
3.
1).若x<0 说明新区间大于原区间所有元素，插入原区间末端；
2).若y<0 说明新区间小于原区间所有元素，插入原区间前端；
3).若其他 说明新区间包含在已有区间内，将元素x的区间更新
intervals[x][0]=min(intervals[x][0],newInterval[0]);//更新左端点
intervals[x][1]=max(intervals[y][1],newInterval[1]);//更新右端点
删除原区间[x+1,y]的元素

执行用时 :
128 ms, 在所有 C++ 提交中击败了6.75%的用户
内存消耗 :
32 MB, 在所有 C++ 提交中击败了5.49%的用户
### 代码

```cpp
class Solution {
public:
	int findX(int num,vector<vector<int> > list,int a,int b){
		if(b<a||a<0) return -1;
		int mind=a+(b-a)/2;
		int x;
		if(list[mind][1]>=num){
			if(mind==0||list[mind-1][1]<num){
				x=mind;
			}else
				x=findX(num,list,a,mind-1);
		}else{
			x=findX(num,list,mind+1,b);
		}
		return x;
	}
	int findY(int num,vector<vector<int> > list,int a,int b){
		if(b<a||a<0) return -1;
		int mind=a+(b-a)/2;
		int y;
		if(list[mind][0]<=num){
			if(mind==b||list[mind+1][0]>num){
				y=mind;
			}else
				y=findY(num,list,mind+1,b);
		}else{
			y=findY(num,list,a,mind-1);
		}
		return y;
	}
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
		int x=-1,y=-1;
		x=findX(newInterval[0],intervals,0,intervals.size()-1);
		y=findY(newInterval[1],intervals,0,intervals.size()-1);
		if(x<0) intervals.push_back(newInterval);
		else if(y<0) intervals.insert(intervals.begin(),newInterval);
		else if(y<x){
			vector<vector<int> >::iterator it=intervals.begin()+x;
			intervals.insert(it,newInterval);
		}else {
			intervals[x][0]=min(intervals[x][0],newInterval[0]);
			intervals[x][1]=max(intervals[y][1],newInterval[1]);
			vector<vector<int> >::iterator it1=intervals.begin()+x;
			intervals.erase(intervals.begin()+x+1,intervals.begin()+y+1);
		}
		return intervals;
    }
};
```
### 解题思路
此处撰写解题思路
先以每个subvector[0]来从小到大排序，迭代，两两比较，合并后想办法删除前面那个。
corner case：
1.[x,x]这种情况要保留
2.erase删除元素后会改变长度，for循环中用erase会出问题！
3.记得考虑前一个元素[x,y]包含[a,b]的情况！
4.就算是通过记录下标来删除，也要从后往前删除，不然坐标还是会变得不匹配！
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());//sort on first element of each subvector
        int len = intervals.size();
        vector<int> del ;
        for (int j = 1 ; j < len ; j++){
            if ( intervals[j][0] <= intervals[j-1][1]){
                intervals[j][0] = intervals[j-1][0];
                if ( intervals[j][1] <= intervals[j-1][1])intervals[j][1] = intervals[j-1][1];
                //later one is included in previous one
                //intervals[j-1][0] = intervals[j-1][1] = 0;
                //set condition for erasing//[0,0]situation counts normal
                //intervals.erase (intervals.begin()+(j-1));
                //can't erase here or length will change
                //cout<<intervals[j][0];
                del.push_back(j-1);
            }
            
        }
        int lend = del.size();
        for (int i = lend-1 ; i >=0 ; i--){
            intervals.erase(intervals.begin()+del[i]);
        }
        // auto iter = intervals.begin();
	    // while (iter != intervals.end()) {
        //     //cout<<(*iter)[0];
		//     if (  (*iter)[0] == (*iter)[1] )iter = intervals.erase(iter);//erase will return next iterator!
		//     else ++iter;//don't forget this 
	    // }
        return intervals;
    }  
};
```
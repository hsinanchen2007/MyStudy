### 解题思路
先以每个subvector[0]来从小到大排序，迭代，两两比较，合并后想办法删除前面那个。
corner case：
1.[x,x]这种情况要保留
2.erase删除元素后会改变长度，for循环中用erase会出问题！
3.记得考虑前一个元素[x,y]包含[a,b]的情况！
4.就算是通过记录下标来删除，也要从后往前删除，不然坐标还是会变得不匹配！

还写了一种 iterator 的 写法，个人感觉挺简洁的结果巨慢。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());//sort on first element of each subvector
        
        int len = intervals.size();
        if (len == 0)return {};
        if (len == 1)return intervals;
        
        auto iter = intervals.begin();
	    while (iter != (intervals.end()-1) ){
            if ( (*(iter+1))[0] <= (*iter)[1]){
                (*(iter+1))[0] = (*iter)[0];
                if ( (*(iter+1))[1] <= (*iter)[1] ) (*(iter+1))[1] = (*iter)[1];
                iter = intervals.erase(iter);
            }
            else ++iter;//don't forget this 
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

//2
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());//sort on first element of each subvector
        
        int len = intervals.size();
        if (len == 0)return {};
        if (len == 1)return intervals;
        
        auto iter = intervals.begin();
	    while (iter != (intervals.end()-1) ){
            if ( (*(iter+1))[0] <= (*iter)[1]){
                (*(iter+1))[0] = (*iter)[0];
                if ( (*(iter+1))[1] <= (*iter)[1] ) (*(iter+1))[1] = (*iter)[1];
                iter = intervals.erase(iter);
            }
            else ++iter;//don't forget this 
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
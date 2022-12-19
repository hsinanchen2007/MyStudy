参照别人的C++写法，之前写的老是在最后一个用例超时，应该是用了太多的set操作导致的。
下面代码的思路：
1.创建一个数组v，这个用来存储结果，每个结果的子数组都有两个元素组成，所以用数组v输出的时候，每两个元素组成一个结果的子数组输出。
2.当有一个val添加进来的时候，用二分查找v，找到大于val的位置index。
2.1 这个时候index先分奇偶。如果是奇数，说明我们找到的是某个子数组的右边（因为index是从0开始的，所以为奇数的时候是子数组的右边）。既然是右边，那么val肯定被该子数组包含了，否则的话肯定找到该子数组的左边的引索。这种情况说明val已经被我们的结果数组包含了，所以不处理。
2.2 当index为偶数的时候，这个时候找到的是某个子数组A的左边或者是压根找不到（这个时候为v的size），先说找不到的情况，那么只能直接再插入一个val的子数组。
如果index<v.size,那么可以判断一下val是不是刚好比子数组A左边的数小1，如果是这样，那么把这个子数组A左边的数改为val。否则的话，和该子数组不连续，那么也是插入一个val的子数组。
2.3 当插入完val子数组或者更新完子数组A之后，index对应的值已经改变了，我们再判断一下index和index-1是否已经可以连在一起了。如果是的话，把inidex、index-1、删除（这里要注意顺序，先删index）。

```
class SummaryRanges {
public:
    
    vector<int> v;
    
    
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        long index = upper_bound(v.begin(), v.end(), val) - v.begin();
        if (index % 2 == 0) { //这个找到的是左边
            if (index < v.size() && v[index] - val == 1) {
                v[index] = val;
            } else {
                v.insert(v.begin() + index , val);
                v.insert(v.begin() + index , val);
            }
            if (index > 0 && v[index] - v[index - 1] <= 1) { //判断一下是否相连
                v.erase(v.begin()+index);
                v.erase(v.begin()+index-1);
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (int i=0; i<v.size();i+=2) {
            vector<int> r;
            r.emplace_back(v[i]);
            r.emplace_back(v[i+1]);
            res.emplace_back(r);
        }
        return res;
    }
};
```
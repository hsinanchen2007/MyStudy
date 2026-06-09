### 解题思路
先遍历，以nums里面的值为key,次数为 value，构建哈希表。
然后维护一个小顶堆，插入后取出来逆序。

### 代码

```cpp
#include <queue>
#include <map>
class Solution {
public:
    struct cmp{
        template<typename T, typename U>
        bool operator()(T const& left, U const &right) {
            if (left.second > right.second) return true;
            return false;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        map<int,int>::iterator iter;
        priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> q;  
        for(int i=0;i<nums.size();++i){
            iter = m.find(nums[i]);
            if(iter == m.end()){
                m[nums[i]] = 1;
            }else{
                m[nums[i]]++;
            }
        }
        iter = m.begin();
        while(iter != m.end()){
            int key = iter->first;
            int value = iter->second;
            pair<int,int> temp(key,value);
            q.push(temp);
            if(q.size() > k){
                q.pop();
            }
            iter++;
        }
        vector<int> output;
        for(int i=0;i<k;++i){
            int temp = q.top().first;
            output.push_back(temp);
            q.pop();
        }
        int begin = 0;
        int end = output.size()-1;
        while(begin <= end){
            int temp = output[begin];
            output[begin] = output[end];
            output[end] = temp;
            begin++;
            end--;
        }
        return output;
    }
};
```
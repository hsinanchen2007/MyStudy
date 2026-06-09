### 解题思路
要求输出出现频率前k的数字, 很容易想到使用优先队列. 但是需要将给出的数组进行统计, 可以使用哈希表来做统计的操作. 然后利用优先队列来输出频率前k的数字. 在使用优先队列时, 涉及到的数据是一个键值对, 可以利用结构体来进行操作. 当然也可以直接使用pair类.

### 代码

```cpp
class Solution {
public:

    struct node{
        int vec1;
        int vec2;
        friend bool operator < (node a, node b){
            return a.vec2 < b.vec2; //相当于less
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        priority_queue<node > pri_que;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        for(auto i : map){
            struct node tmp;
            tmp.vec1 = i.first;
            tmp.vec2 = i.second;
            pri_que.push(tmp);
        }
        for(int i = 0; i < k; i++){
            res.push_back(pri_que.top().vec1);
            pri_que.pop();            
        }
        return res;
    }
};
```
### 解题思路
map 大顶堆 排序
### 代码

```cpp
class Solution {
public:
    string frequencySort(string s) {
        map<char,int> frequencyMap;
        for(auto it:s){
            frequencyMap[it]++;
        }
        priority_queue<pair<int,char>> bigTopHeap;
        for(auto it:frequencyMap){
            bigTopHeap.push(make_pair(it.second,it.first));
        }
        string res;
        while(!bigTopHeap.empty()){
            pair<int ,char>top=bigTopHeap.top();
            int num=top.first;
            while(num>0){
                res+=top.second;
                num--;
            }
            bigTopHeap.pop();
        }
        return res;
    }
};


```
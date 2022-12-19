### 解题思路
此处撰写解题思路

### 代码

```cpp
/*  multiset   */
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size() <= 0 || k <= 0){
            return vector<int>();
        }
        vector<int> res;
        multiset<int> mset;
        for(int i = 0; i < arr.size(); ++i){
            mset.insert(arr[i]);
        }
        
        multiset<int>::iterator it = mset.begin();
        for(int i = 0; i < k; ++i){
            res.push_back(*it);
            it++;
        }
        return res;
    }
};

/*  multimap */
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size() <= 0 || k > arr.size() || k <= 0){
            return vector<int>();
        }
        vector<int> res;
        multimap<int,int> temp;
        for(int i = 0;i < arr.size(); i++){
            temp.insert(make_pair(arr[i],i));
        }

        map<int,int>::iterator it = temp.begin();
        for(int j = 0; j < k; j++){
            res.push_back(it->first);
            ++it;
        }
        return res;
    }
};


/*  大根堆  */
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size() <= 0 || k <= 0){
            return vector<int>();
        }
        vector<int> res;
        priority_queue<int> sq;
        int i = 0;
        while(sq.size() < k){
            sq.push(arr[i++]);
        }
        for(int j = i; j < arr.size(); ++j){
            if(arr[j] < sq.top()){
                sq.pop();
                sq.push(arr[j]);
            }
        }
        while(!sq.empty()){
            res.push_back(sq.top());
            sq.pop();
        }
        return res;
    }
};
```
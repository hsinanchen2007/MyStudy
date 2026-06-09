```
class Solution {
public:
    queue<int>Q;
    deque<int>D;
    int maxNum(){
        return D.front();
    }
    void _push(int value){
        Q.push(value);
        while(!D.empty()&&value>D.back()){
            D.pop_back();
        }
        D.push_back(value);
    }
    void _pop(){
        int t=Q.front();
        if(!D.empty()&&D.front()==t){
            D.pop_front();
        }
        Q.pop();
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()){
            return {};
        }
        vector<int>res;
        for(int i=0;i<k;i++){
            _push(nums[i]);
        }
        res.push_back(maxNum());
        for(int i=k;i<nums.size();i++){
            _pop();
            _push(nums[i]);
            res.push_back(maxNum());
        }
        return res;
    }
};
```

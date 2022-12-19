```
class MovingAverage {
public:
    /** Initialize your data structure here. */
    vector<int> nums;
    int count = 0;
    int size = 0;
    MovingAverage(int size) {
        this->size = size;
        
    }
    
    double next(int val) {
        if(count>=size){
            nums.erase(nums.begin());
        }else{
            count++;
        }
        nums.push_back(val);
        int sum = 0;
        for(auto iter = nums.begin();iter!=nums.end();++iter){
            sum += *iter;
        }
        return sum*1.0/count;
    }
};
```

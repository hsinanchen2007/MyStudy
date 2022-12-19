```
class MovingAverage {
public:
    /** Initialize your data structure here. */
    vector<int> vdata;
    double sum;
    int size;
    MovingAverage(int size) {
        this->size = size;
        sum = 0.0;
    }
    
    double next(int val) {
        if(vdata.size() == size)
        {
            sum -= vdata.front();
            vdata.erase(vdata.begin());
        }
        sum += val;
        vdata.push_back(val);
        return sum/vdata.size();
    }
};

```

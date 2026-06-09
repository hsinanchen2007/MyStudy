```
class MinStack {
private:
    vector<int> dp;
    vector<int> data;
    int idx;
public:
    /** initialize your data structure here. */
    MinStack() {
        idx = 0;
    }

    void push(int x) {
        data.emplace_back(x);
        if(dp.empty())
            dp.emplace_back(data[idx]);
        else
            dp.emplace_back(min(dp[idx-1],data[idx]));
        idx++;
    }

    void pop() {
        if (idx)
        {
            idx--;
            data.erase(data.end() - 1);
            dp.erase(dp.end() - 1);
        }
    }

    int top() {
        return data.back();
    }

    int getMin() {
        return dp.back();
    }
};
```

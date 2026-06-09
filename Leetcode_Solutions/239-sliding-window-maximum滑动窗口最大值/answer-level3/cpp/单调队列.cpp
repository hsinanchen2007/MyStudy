class monotonicqueue {

private:
    deque<int> q;
public:
    void push(int n) {
        while (!q.empty() && n > q.back()) {
            q.pop_back();
        }
        q.push_back(n);
    }

    int mx(){
        return  q.front();
    }
    
    void pop (int n) {
        //加入左边界的正好是最大值。pop掉，否则已经被pop掉了。
        if (!q.empty() && q.front() == n) {
            q.pop_front();
        }
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        monotonicqueue window;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k-1) {
                window.push(nums[i]);
            } else {
                window.push(nums[i]);
                res.push_back(window.mx());
                window.pop(nums[i-k+1]);
            }


    }

    return res;
    }
};



# 标题
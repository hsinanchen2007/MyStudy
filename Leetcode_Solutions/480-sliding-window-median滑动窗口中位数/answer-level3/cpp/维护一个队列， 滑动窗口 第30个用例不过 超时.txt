class Solution {

public:
    double calArrayMedian(deque<int>&data) {
		deque<int>deq = data;
	    int size = deq.size();
        sort(deq.begin(), deq.end());
       if (size%2)
        return deq[size/2];
       else
        return ((double)deq[size/2-1] + (double)deq[size/2]) / 2;    
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        deque<int>deq; 
        vector<double>res;
        for(int i=0; i<nums.size(); i++) {
            if (i < k - 1) {
                deq.push_back(nums[i]);
            } else {
                deq.push_back(nums[i]);
                res.push_back(calArrayMedian(deq));
                deq.pop_front();
            }
        }
        return res;
    }
};
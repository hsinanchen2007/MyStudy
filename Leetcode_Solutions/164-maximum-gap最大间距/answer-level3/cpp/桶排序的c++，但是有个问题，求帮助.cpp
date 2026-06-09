我这个桶排序的代码，有个用例报错，我本地debug也没问题。有高手看看吗？
[15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740]

```
int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int minVal = nums[0];
        int maxVal = nums[0];
        for(int i=1; i<n ;++i){
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
        }
        if(minVal==maxVal) return 0;
        int interval = ceil((double)(maxVal-minVal) / (n-1));
        vector<int> minVec(n-1, INT_MAX);
        vector<int> maxVec(n-1, INT_MIN);
        for(int i=0; i<n; ++i){
            if (nums[i] == minVal || nums[i] == maxVal)
                continue;
            int index = nums[i]/interval;
            minVec[index] = min(minVec[index], nums[i]);
            maxVec[index] = max(maxVec[index], nums[i]);
        }
        int res = 0;
        int pre = minVal;
        for (int i = 0; i < n-1; ++i){
            if (minVec[i]==INT_MAX) continue;
            res = max(res, minVec[i] - pre);
            if (maxVec[i] != INT_MIN) pre = maxVec[i];

        }
        res = max(res, maxVal-pre);
        return res;
    }


```

![image.png](https://pic.leetcode-cn.com/1ce92bce23b099e20991de1a85ff60636d3a71340520b6b695f2b1b26e5d77c8-image.png)


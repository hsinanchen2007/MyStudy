小根堆可解，用一个数表示当前堆中的最大值并每次迭代更新。
```
struct ele{
        int value;
        int arrayIdx;  // idx-th array
        int numIdx;    // idx-th element in that array
        ele(int v=0, int a=0, int n=0): value(v), arrayIdx(a), numIdx(n) {}
    };

struct CMP{
    bool operator()(const ele &a, const ele &b) const{
        return a.value > b.value;
    }
};

vector<int> MIN(vector<int> &a, vector<int> &b){
    if (a[1] - a[0] < b[1] - b[0]) return a;
    else if (a[1] - a[0] > b[1] - b[0]) return b;
    else return a[0] < b[0] ? a : b;
}

class Solution {
public:    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<ele, vector<ele>, CMP> heap;
        int i;
        int k = nums.size();
        int currentMaxValue = -2000000;
        for (i = 0; i < k; ++i){
            heap.push(ele(nums[i][0], i, 0));
            currentMaxValue = max(currentMaxValue, nums[i][0]);
        }
        
        ele out;
        vector<int> ans = {400000, 800000};
        vector<int> candidate = {0, 0};
        while (true){
            out = heap.top();
            heap.pop();
            candidate[0] = out.value;
            candidate[1] = currentMaxValue;
            ans = MIN(ans, candidate);
            
            ++out.numIdx;
            if (out.numIdx >= nums[out.arrayIdx].size()) break;
            out.value = nums[out.arrayIdx][out.numIdx];
            currentMaxValue = max(currentMaxValue, out.value);
            heap.push(out);
        }
        return ans;
    }
};
```

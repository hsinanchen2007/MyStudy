### 解题思路
48ms,93%击败

### 代码

```cpp
class KthLargest {
public:
    vector<int> hap = vector<int>(100000,INT_MIN);
    int cnt = 0;
    int m;
    KthLargest(int k, vector<int>& nums) {
        m = k;
        cnt = k;
        if(nums.size()){
            for(int i = 0;i < nums.size();++i)hap[i+1] = nums[i];
            for(int i = k;i >= 1;--i) down(i);//建堆
            for(int i = k+1;i <= nums.size();++i){
                if(hap[i] <= hap[1]);
                else{
                    hap[1] = hap[i];
                    down(1);
                }
            }
        }
    }
    void down(int x){
        int t = x;
        if(x*2 <= cnt && hap[t] > hap[2*x])t = 2*x;
        if(x*2+1 <= cnt && hap[t] > hap[2*x+1])t = 2*x+1;
        if(t != x){
            swap(hap[x],hap[t]);
            down(t);
        }
    }
    int add(int val) {
        if(val <= hap[1])return hap[1];
        else{
            hap[1] = val;
            down(1);
            return hap[1];
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```
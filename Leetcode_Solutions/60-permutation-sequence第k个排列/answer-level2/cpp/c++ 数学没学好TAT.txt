### 解题思路
最近发现阿里出笔试题挺爱出数学类题目的。。。

### 代码

```cpp
class Solution {
private:
    vector<int> nums;

    void initial(){
        nums.resize(10);
        nums[0] = 1;
        for(int i = 1; i < 10; i++) nums[i] = nums[i-1]*i;
    }

public:
    Solution(){
        initial();
    }

    string get(vector<bool> &visited, int remain_length, int k){
        if(remain_length == 0){
            for(int i = 1; i < 10; i++){
                if(!visited[i]) return to_string(i);
            }
        }
        int cur = 1;
        while(cur < 10){
            while(cur < 10 && visited[cur]) cur++;
            if(k - nums[remain_length] <= 0) break;
            else{
                k -= nums[remain_length];
                cur++;
            }
        }
        visited[cur] = true;
        // cout << cur << endl;
        return to_string(cur) + get(visited, remain_length-1, k);
    }

    string getPermutation(int n, int k) {
        if(n == 1) return "1";
        vector<bool> visited(n+1, false);
        return get(visited, n-1, k);
    }
};
```
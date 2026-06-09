### 解题思路
先把所有位置找到，然后二分找

### 代码

```cpp
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        unordered_map<string,vector<int>> mp;
        for(int i = 0; i < words.size();i++){
            if(words[i] == word1 || words[i] == word2){
               mp[words[i]].push_back(i); 
            }
        }
        vector<int> a = mp[word1];
        vector<int> b = mp[word2];
        int sz = b.size();
        int min_value = INT_MAX;
        for(int i = 0; i < a.size();i++){
            int cur = bin_find(0,sz,a[i],b);
            if(cur-1 >=0)
                min_value = min ({min_value, abs(a[i]-b[cur-1])});
            if(cur<sz)
                min_value = min ({min_value, abs(a[i]-b[cur])});
        }
 
        return min_value;

    }
    int bin_find(int left,int right, int target,vector<int> nums){
        while(left < right){
            int mid = left + (right-left)/2;
            if(target == nums[mid]) return mid;
            if(target < nums[mid]) right = mid;
            else left = mid+1;
        }
        return left;
    }
};
```
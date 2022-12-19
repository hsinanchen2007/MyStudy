### 解题思路
朴素贪心算法：
  当前位置为 pos , 可跳距离为 step = nums[pos]，若下一跳为 i ，其在 [pos+1, pos+step] 范围内，则 **i 点可达的距离范围 = i 距离 pos 的距离 + i 点可进一步跳的距离**，即 distance = i - pos + nums[i]，那么只需使用贪心算法，在 [pos+1, pos+step] 的范围内将**当前 pos 的下一个可达最远距离的 maxi 找出来即可****完成当前跳的最优解**，依次迭代找到整体的最优价。
**注意：细节见代码**

### 代码

```cpp
class Solution {
private:
    int nextBestJump(vector<int> nums, int pos){
        int step = nums[pos];
        if(step == 1){
            return pos+1;
        }
        int maxlen = 0;
        int next = pos + 1;
        for(int i = pos+1; i < min((int)nums.size(), pos+step+1); i++){
            if(i == nums.size()-1){
                return nums.size()-1;
            }
            if(nums[i] + i - pos > maxlen){
                maxlen = nums[i] + i - pos;
                next = i;
            }
        }
        return next;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int pos = 0;
        while(pos < n-1){
            if(nums[pos] == 1){
                // 由于测例中存在大量 1 的现象，避免函数调用带来的速度影响，直接 +1，否则会超时
                pos++;
            }
            else pos = nextBestJump(nums, pos);
            cnt++;
        }    
        return cnt;
    }
};
```
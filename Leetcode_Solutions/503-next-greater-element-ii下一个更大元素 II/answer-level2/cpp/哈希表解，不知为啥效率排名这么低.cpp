class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret;
        unordered_map<int, int> m;                //定义hash表，映射关系为该元素下标及其下一个更大元素下标
        int size = nums.size();
        for (int i = size - 1; i >= 0; i--) {     //从末尾往回操作
            int next = (i + 1) % size;
            while(nums[i] >= nums[next] && i != next && m.count(next)) {    //利用哈希表进行跳跃搜索更大值
                next = m[next];
            }

            while(i != next && nums[i] >= nums[next]) {                     //哈希表搜不到的，用线性搜
                next = (next + 1) % size;
            }
            if (i == next) {
                ret.insert(ret.begin(), -1);                                 //如果元素为最大值，那么一定会有i == next
            } else {
                ret.insert(ret.begin(), nums[next]);                         //否则，找到了next更大值
                m[i] = next;
            }
        }
        return ret;
    }
};
位操作+缓存


class Solution {
public:
    bool CheckValid(int index, uint32_t& mask)
    {
        uint32_t backup = mask;
        if (bits[index] == 0 || bits[index] & mask) {
            return false;
        }
        mask |= bits[index];
        return true;
    }

    int maxLength(vector<string>& nums)
    {
        if (nums.size() == 0) {
            return 0;
        }

        BuildBits(nums);

        uint32_t mask = 0;
        Dfs(0, nums, mask);

        return res;
    }

    void Dfs(int index, vector<string>& nums, uint32_t& mask)
    {
        if (index == nums.size()) {
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            uint32_t tmp = mask;
            if (CheckValid(i, tmp)) {
                mSize += nums[i].size();
                res = max(res, mSize);
                // cout<<"res:" <<res<<endl;
                Dfs(i + 1, nums, tmp);
                mSize -= nums[i].size();
                
            }
        }
    }

    void BuildBits(vector<string>& nums)
    {
        for (size_t i = 0; i < nums.size(); i++) {
            uint32_t tmp = 0;
            for (auto it : nums[i]) {
                if (tmp & (1 << (it - 'a'))) {
                    tmp = 0;
                    // cout<<tmp<<endl;
                    break;
                } else {
                    tmp |= (1 << (it - 'a'));
                }
            }

            bits.push_back(tmp);
        }
    }

private:
    int res{0};
    int mSize{0};
    vector<uint32_t> bits;
};


![image.png](https://pic.leetcode-cn.com/6224e4c737160ee773f9c08627b27749c247e9e42e61111c2f3956e53650688c-image.png)

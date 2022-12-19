```
class Solution {
public:
    int findGreatDouble(vector<int>& nums, long long aim)
    {
        int le = 0, ri = nums.size();
        while (le < ri) {
            int mid = le + (ri - le) / 2;
            if (nums[mid] <= aim + aim) {
                le = mid + 1;
            } else {
                ri = mid;
            }
        }
        return ri;
    }

    int low_bit(int i)
    {
        return (i) & (-i);
    }

    void bit_update(vector<int>& nums, int i, int dis)
    {
        while(i < nums.size()) {
            nums[i] += dis;
            i += low_bit(i);
        }
    }

    int calcum(vector<int>& bit, int pos)
    {
        int sum = 0;
        while (pos > 0) {
            sum += bit[pos];
            pos -= low_bit(pos);
        }
        return sum;
    }

    int reversePairs(vector<int>& nums) {
        map<int, int> valToRank;
        vector<int> ran(nums.begin(), nums.end());
        vector<int> bit(nums.size() + 1, 0);
        sort(ran.begin(), ran.end(), less<int>());
        for (int i = nums.size() - 1; i >= 0; i--) {
            valToRank[ran[i]] = i;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int first_gd = findGreatDouble(ran, nums[i]);
            sum += (i - calcum(bit, first_gd));
            bit_update(bit, valToRank[nums[i]] + 1, 1);
        }
        return sum;
    }
};
```


```cpp
class Solution {
public:
    // 先排序  直接返回 N/2位置的元素 （无论N是奇数还是偶数）
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        return nums.at(nums.size() / 2);

    }

    // hash表 统计次数，再遍历获取大于N/2次数的num
    int majorityElement(vector<int>& nums) {
    
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i)
        {
            ++m[nums.at(i)];
            if (m[nums.at(i)] > nums.size() / 2)  //题意：必存在大于N / 2次数的数
                return nums.at(i);
        }
        return 0; //只是为了编译通过
    }

    //Boyer-Moore 投票算法
    int majorityElement(vector<int>& nums) {

        int candidate = nums.at(0);
        int count = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (count == 0)
            {
                candidate = nums.at(i);
                count = 1;
            }

            else if (nums.at(i) == candidate) //注意：不能写成if 避免count==0后又进入此分支，使count变为2
                ++count;

            else
                --count;
        }

        return candidate;
    }
};
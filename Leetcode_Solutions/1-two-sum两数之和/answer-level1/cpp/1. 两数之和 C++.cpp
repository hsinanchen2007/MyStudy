```cpp    
class Solution {
public:
    //1、暴力法
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> v(2);
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(nums.at(i) + nums.at(j) == target)
                {
                    v.at(0) = i;
                    v.at(1) = j;
                    return v;
                }
            }
        }
        return v;
    }

    //2、使用hash表，两次遍历数组
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> v(2);
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            map.insert(pair<int, int>(nums.at(i), i));
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            auto found = map.find(target - nums.at(i));
            if (found != map.end() && found->second != i)  //注意：两个元素的下标不能相同  题目：你不能重复利用这个数组中同样的元素。
            {
                v.at(0) = i;
                v.at(1) = found->second;
                return v;
            }
        }

        return v;
    }

    //3、使用hash表，一次遍历数组
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> v(2);
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            map.insert(pair<int, int>(nums.at(i), i));

            auto found = map.find(target - nums.at(i));
            if (found != map.end() && found->second != i) //注意：下标不能相同  题目：你不能重复利用这个数组中同样的元素。
            {
                //注意：这里的found->second会小于i
                v.at(0) = found->second;
                v.at(1) = i;

                return v;
            }
        }

        return v;
    }

    //4、先从hash表中找，找不到再保存
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> v(2);
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto found = map.find(target - nums.at(i));
            if (found != map.end())
            {
                //注意：这里的found->second会小于i（因为i还没存）
                v.at(0) = found->second;
                v.at(1) = i;

                return v;
            }

            map.insert(pair<int, int>(nums.at(i), i));
        }

        return v;
    }
};
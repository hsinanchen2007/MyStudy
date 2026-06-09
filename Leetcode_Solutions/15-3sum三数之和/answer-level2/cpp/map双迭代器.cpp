使用map维护一个有序数组及元素数量，使用双层循环遍历map，找到三数之和为0的情况保存下来，位避免重复，可保证num1 <= num2 <= num3，还需判断其元素数量是否可以满足需求。
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int>tmp;
        int len = nums.size();
        map<int, int> mp;
        for (int i = 0; i < len; i ++) {
            mp[nums[i]] ++;
        }
        map<int, int>::iterator i, j, pos;
        for (i = mp.begin(); i != mp.end(); i ++) {
            for (j = i; j != mp.end(); j ++) {
                int sum = i -> first + j -> first;
                i -> second --; //表示取用这个数字
                j -> second --;
                pos = mp.find(-sum);
                if (pos != mp.end() && -sum >= j -> first && pos ->second > 0 && i -> second >= 0 && j -> second >= 0) { // 判断大小及数字个数是否满足要求
                    tmp.clear();
                    tmp.push_back(i -> first);
                    tmp.push_back(j -> first);
                    tmp.push_back(-sum);
                    result.push_back(tmp);
                }
                i -> second ++; // 退还这个数字
                j -> second ++;
            }
        }
        return result;
    }
};
```

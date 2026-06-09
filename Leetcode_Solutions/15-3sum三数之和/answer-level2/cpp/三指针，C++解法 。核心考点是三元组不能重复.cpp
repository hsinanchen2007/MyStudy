### 解题思路
单纯的找和为0的三元组很容易，保证三元组不重复需要花费点心思，元组的去重让我费了一番心思，甚至还尝试用hashmap检测，显然超时了。

简单说下我的解法，三个指针L，M，R，L和R居左，R居右，R向左移动，和为0即停，移动M，M移动到头了再移动L。
最初我第一时间就想到了三指针，但是最初是L、M、R全部在左，那样效率上不会太好，因为在大样本下，L和M之和趋于负无穷，让R指针居于正无穷是明智方法。（倾斜数据可以通过判断迅速跳过或结束）

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        int len = nums.size(),l = 0, m = 1, r = len-1;
        vector<int> t;
        while (l < len - 1 && nums[l] <= 0) {
            if(r < len && l < m && m < r){
                while ((nums[l] + nums[m] + nums[r]) > 0 && r > 0) { --r;}
                if (l<m && m < r && (nums[l] + nums[m] + nums[r]) == 0) {
                    t.push_back(nums[l]);
                    t.push_back(nums[m]);
                    t.push_back(nums[r]);
                    res.push_back(t);
                    t.clear();
                    while(r > 0 && r < len && r > m && nums[r-1] == nums[r]){--r;}
                }
            }
            while(m < len - 1 && nums[m+1] == nums[m]){++m;}
            ++m;
            if(m>r){
                while(l < len - 1 && nums[l+1] == nums[l]){++l;}
                ++l;m = l+1;r = len - 1;
            }
        }

        return res;
    }
};
```
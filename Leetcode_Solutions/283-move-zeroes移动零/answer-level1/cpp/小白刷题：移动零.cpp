遍历数组，遇到零删除，统计删除了多少零，之后在末尾补上

代码：
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num = 0;
        vector<int>::iterator it = nums.begin();
        while (it != nums.end()) {
            if (*it == 0) {
                nums.erase(it);
                num++;
            }
            else
                it++;
        }
        for (int i = 0; i < num; i++)
            nums.push_back(0);
    }
};
```

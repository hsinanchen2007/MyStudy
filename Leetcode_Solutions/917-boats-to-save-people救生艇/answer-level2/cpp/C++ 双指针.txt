简单双指针
```
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int res = 0;
        while (l <= r) {
            if (people[l] + people[r] > limit) {
                --r;
            } else {
                --r;
                ++l;
            }
            ++res;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/6bc170b24f6c8190159c03048feba35e9b283914e44c6578470ad2e80870afe2-image.png)

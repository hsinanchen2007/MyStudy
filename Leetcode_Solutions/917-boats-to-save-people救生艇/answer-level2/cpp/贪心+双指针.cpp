这个题和[令牌放置](https://leetcode-cn.com/problems/bag-of-tokens/)类似。

贪心策略，先排序，再使用双指针。

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res =0;
        if(people.size() == 0){
            return 0;
        }
        sort(people.begin(),people.end());

        int left=0,right=people.size()-1;
        while(left <= right){
            if(people[right] == limit){
                right--;
                res++;
            }else if(people[right] < limit){
                if(people[left] + people[right] <=limit){
                    right--;
                    left++;
                }else{
                    right--;
                }
                res++;
            }
        }
        return res;
    }
};
```
稍微简化一下：
```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res =0;
        if(people.size() == 0){
            return 0;
        }
        sort(people.begin(),people.end());

        int left=0,right=people.size()-1;
        while(left <= right){
            res++;
            if(people[left] + people[right] <= limit){
                left++;
            }
            right--;
        }
        return res;
    }
};
```
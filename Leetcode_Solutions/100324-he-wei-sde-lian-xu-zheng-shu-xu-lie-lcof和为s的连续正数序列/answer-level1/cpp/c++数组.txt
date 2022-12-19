### 解题思路
从1开始把数字放到vector里面去，如果sum比target大，就删除前面的，如果小于target，就把后面的加进去。
因为至少要两个数字，所以只需要判断到target一半的大小就可以了+

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result;
        int sum=0;
        int n=1;
        vector<int>cur;
        while(n<target){
            if(sum<target){
                cur.push_back(n);
                sum+=n;
                n++;
            }else if(sum>target){
                sum-=cur[0];
                cur.erase(cur.begin());
            }else{
                result.push_back(cur);
                sum-=cur[0];
                cur.erase(cur.begin());
            }
        }
        return result;
    }
};
```
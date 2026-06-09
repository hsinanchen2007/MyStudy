找到当前位置能走的最大距离。
例子1：
[3,2,1,0,4]，每个点所能走到的最大距离分别是[3,3,3,3,X]，最后一个位置我们不在意，用X表示。可以发现，对于前3个点，最大距离都大于等于自己的索引i，但是对于第四个点，最大距离仍是3，索引为4，这就是判断false的条件。
例子2：
[2,3,1,1,4]，每个点的最大距离分别是[2,4,3,4,X]，最大距离maxlen始终大于索引，因此true。

其实还可以优化，例如当maxlen>numslen就返回true，但是跑起来慢了。

```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int numslen = nums.size();
        vector<int> arr(numslen,0);
        int maxlen = 0;
        
        for(int i=0;i<numslen-1;i++)
        {
            arr[i] = nums[i]+i;
            maxlen = arr[i]>maxlen?arr[i]:maxlen;
            if(maxlen<=i) return false;
        }
        return true;
    }
};
```

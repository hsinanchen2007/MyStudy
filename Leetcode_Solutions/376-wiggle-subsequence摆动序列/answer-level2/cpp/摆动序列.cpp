### 解题思路
贪心算法只考虑当前最优。
当前位置的diff和prediff相异，那么我就选他，计数器加1
三种情况，
差值，全部等于0，
差值一开始等于0，后面至少有一个不等
差值一开始不等于0,
                prediff   diff    是否允许加1
                0          >0         允许
                0          <0         允许
                0           0         不允许
                >0         <0         允许
                >0         0         不允许    3 1  2 2
                >0         >0         不允许
                <0         >0         允许
                <0         0         不允许    1 3  2 2
                <0         <0         不允许


### 代码

```cpp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if(size==0||size==1) return size;
        int prediff  = nums[1]-nums[0];
        int count = prediff==0?1:2;
        int diff;
        for(int i=2;i<nums.size();i++){
            diff = nums[i]-nums[i-1];
            // 这里存在特殊情况，如果一开始是1，1开头，如果diff！=0，那么即使prediff==0,也允许cout+1,之后所有的prediff不会等于0的，
            // 而如果diff一直等于0，那么也不会cout++
            // 
              if(diff>0&&prediff<=0||diff<0&&prediff>=0){
                  count++;
                  prediff = diff;
              }

        }
        return count;
    }
};
```
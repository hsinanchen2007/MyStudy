### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {//代表最大长度
        int res(0),start(0),jump,dis;
        int num_size=nums.size();
        while(start<num_size-1){
            dis=0;
            for(int i=1;i<=nums[start];++i){
                if(start+i==num_size-1) //如果可以直接到达末尾就不用再贪心
                    return ++res;
                else if(i+nums[start+i]>dis){
                    dis=i+nums[start+i];
                    jump=i;
                }
            }
            res++;
            start+=jump;
        }
        return res;
    }
};
```
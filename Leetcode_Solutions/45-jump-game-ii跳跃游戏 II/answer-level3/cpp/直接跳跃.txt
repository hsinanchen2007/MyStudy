### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int a=0,num=0,max=0;
        int step=1;
        while(a+nums[a]+1<nums.size()){
            max=0;
            for(int i=1;i<=nums[a];++i){
                if(a+i+nums[a+i]>max){
                    max=a+i+nums[a+i];
                    num=i;
                }
            }
            a+=num;
            ++step;
        }
        return step;
    }
};
```
### 解题思路
![TIM图片20191213190948.png](https://pic.leetcode-cn.com/560691ff2d4e3400ad4e27df7c0a36d0aff151c131736922a30faed755dd2cdb-TIM%E5%9B%BE%E7%89%8720191213190948.png)
分别记录下0,1,2出现的次数，然后对nums赋值
### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int x=0,y=0,z=0,i;
        for(i=0;i<nums.size();i++)
            if(nums[i]==0)
                x++;
            else
                if(nums[i]==1)
                    y++;
                else
                    z++;
        i=0;
        while(x>0){
            nums[i++]=0;
            x--;
        }
        while(y>0){
            nums[i++]=1;
            y--;
        }
        while(z>0){
            nums[i++]=2;
            z--;
        }
    }
};
```
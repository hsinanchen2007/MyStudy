### 解题思路
简单的C++暴力法，希望各位大佬多多指点
利用双指针，一个low和一个high，指向两端，不断记录两端之间的和。
效率还行，4ms和9.1MB
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int low=1,sum=0;
        vector<vector<int>> re;
        for(int high=1;high<target/2+2;high++)//当超过target/2+2的时候就结束了
        {
            sum+=high;
            while(sum>=target)
            {
                if(sum==target)
                {
                    vector<int> tmp;
                    for(int j=low;j<=high;j++)
                        tmp.push_back(j);
                    re.push_back(tmp);
                    sum-=low;
                    low++;
                }
                else
                {   
                    sum-=low;
                    low++;
                }
            }
        }
        return re;
    }
};
```
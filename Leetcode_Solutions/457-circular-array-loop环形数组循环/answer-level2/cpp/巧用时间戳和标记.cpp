### 解题思路
给出了数据范围，那么可以考虑用一下特殊的数做标记和时间戳，相当于剪掉了所有不可能的枝
代码ifelse比较丑，有大佬看到顺手替我改改也好

### 代码

```cpp
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if(nums.empty()) return false;
        //pre-process
        int len=nums.size();
        int tag1=1001,tag2=-1001;
        int tag;
        for(int i=0;i<len;++i)
        {
            if(nums[i]==0) continue;
            if(abs(nums[i])>=1001) continue;
            int k=i;
            if(nums[i]>0)
            {
                tag=tag1++;
            }else{
                tag=tag2--;
            }
            while(nums[k]!=0)
            {
                int curk=k;
                int nk=(k+nums[k])%len;
                if(nk<0) nk+=len;
                if(nums[nk]==tag&&nk!=curk) return true;
                if(nk==curk)
                {
                    nums[curk]=0;
                    break;
                }
                if(abs(nums[nk])>=1001&&nums[nk]!=tag)
                {
                    nums[curk]=0;
                    break;
                }
                if(nums[nk]*nums[curk]<=0)
                {
                    //nums[nk]反向或者已经被否决过
                    nums[curk]=0;//则由该curk必然走不成环
                    break;
                }
                nums[curk]=tag;//打上当前轮次的时间戳
                k=nk;
            }
        }
        return false;
    }
};
```
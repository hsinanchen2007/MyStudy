### 解题思路
将问题先化简只考虑三个元素a,b,c的大小关系。因此函数func的功能就是根据a,b,c的大小修改a,b,c并返回修改的次数。
首先做预处理，如果nums[0]>nums[1],则将nums[0]=nums[1].这样将会使我们后面考虑a,b,c时，总会有a<=b.
下面考虑a,b,c.
1.若a<=b<=c,则不需要修改元素，func返回0;example:(1，2，3)、(1，1，1)elc.
2.若a==b>c,则要修改c=b,func返回1;example:(2,2,1)elc.
3.若a<b&&b>c&&a<=c时，则要修改b=a,func返回1;example:(1,3,2).
4.若a<b&&b>c&&a>c时，则要修改c=b,func返回1;example:(3,4,1).
然后i从1开始到len-2结束，判断num[i-1],nums[i],nums[i+1]的修改次数。

### 代码

```cpp
class Solution {
public:
    int func(int &a,int &b,int &c){
        if(a<=b&&b<=c) return 0;
        else if(a==b&&a>c){
            c=a;
            return 1;
        }else if(a<b&&b>c&&a<=c){
            b=a;
            return 1;
        }else if(a<b&&b>c&&a>c){
            c=b;
            return 1;
        }else return 0;
    }
    bool checkPossibility(vector<int>& nums) {
        int len=nums.size();
        if(len<3) return true;
        int cnt=0;
        if(nums[0]>nums[1]){
            nums[0]=nums[1];
            cnt++;
        }
        for(int i=1;i<len-1;i++){
            cnt+=func(nums[i-1],nums[i],nums[i+1]);
            if(cnt>1) return false;
        }

        return true;
    }
};
```
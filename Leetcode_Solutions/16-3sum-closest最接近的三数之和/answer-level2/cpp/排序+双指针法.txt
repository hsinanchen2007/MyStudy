### 解题思路
先对nums排序，然后第一层循环从一个元素开始遍历，第二层循环用双指针法来确定这三个数，使三个数的和与target的差最小。当和小于target时说明小了，把左指针往后移，当和大于target时将右指针往前移，进行下一次判断。这里不能像三数和那样当第一个数大于target时就返回。

### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums,int target) {
        sort(nums.begin(),nums.end());
        cout<<nums[0];
        //if(nums[0]>target)return (nums[0]+nums[1]+nums[2]);
        int l=0,r=0,sum=0,min=10000,diff=0;
        int a1=0,a2=1,a3=2;
        int n = nums.size();
        for(int i = 0;i<n-2;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            l=i+1;
            r=n-1;
            while(l<r){
                sum=nums[i]+nums[l]+nums[r];
                diff=abs(sum-target);
                //cout<<sum<<"-";
                if(diff==0){
                    return (nums[i]+nums[l]+nums[r]);
                }

                if(diff<min){
                    min=diff;
                    a1=i;a2=l;a3=r;
                }

                if(sum>target){
                    r--;
                    while(r>-1&&nums[r]==nums[r+1]){
                        r--;
                    }
                }
                else {
                    l++;
                    while(l<n&&nums[l]==nums[l-1]){
                        l++;
                    }
                }
            }
        }
        cout<<"index"<<a1<<","<<a2<<","<<a3<<endl;
        return(nums[a1]+nums[a2]+nums[a3]);

    }
};
```
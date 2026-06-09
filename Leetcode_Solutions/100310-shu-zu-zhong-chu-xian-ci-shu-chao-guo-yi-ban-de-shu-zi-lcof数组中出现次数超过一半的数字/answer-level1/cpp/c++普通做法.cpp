### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt[25000][2];
        int number=-1;
        for(int i=0;i<nums.size();i++)
        {
            //cout<<nums[i]<<endl;
            bool flag=false;
            for(int j=0;j<=number;j++)
                if(nums[i]==cnt[j][0])
                {
                    //cout<<"find it"<<endl;
                    flag=true;
                    cnt[j][1]++;
                    if(cnt[j][1]>=(nums.size()+1)/2)
                        return nums[i];
                }
            if(flag==false)
            {
                //cout<<"can not find it"<<endl;
                number++;
                cnt[number][0]=nums[i];
                cnt[number][1]=1;
            }
        }
        return nums[0];

    }
};
```
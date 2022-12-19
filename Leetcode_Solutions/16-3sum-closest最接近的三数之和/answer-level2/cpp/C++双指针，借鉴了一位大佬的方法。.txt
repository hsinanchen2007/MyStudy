用一个for循环来当一个数字的遍历，另外一个while循环来遍历另外两个指针。
由于max应该为INT_MAX,可是编译错误，就设置成了200，编译通过。
```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int max = 200;
        int sum = 0;
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i<len;i++)
        {
            int l = 0;
            int r = len-1;
            while(l<r)
            {
                if(l == i)
                {
                    l++;
                }
                if(r == i)
                {
                    r--;
                }
                if(l >= r)
                {
                    break;
                }
                int x = nums[l] + nums[i] + nums[r];
                int n = abs(x-target);
                
                if(n<max)
                {
                    sum = x;
                    max = n;
                }
                if(x == target)
                {
                    return sum;
                }
                if(x < target)
                {
                    l++;
                }
                if(x > target)
                {
                    r--;
                }
            }
        }
        return sum;
    }
};
```



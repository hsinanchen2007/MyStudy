C++ 8MS 8.7MB 双指针逼近
C++ 76MS 8.7MB 10行代码，暴力破解
```
class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int target) {//双指针逼近
        int len=nums.size();
        int ins=INT_MAX;
        int sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++)
        {
            int l=0;
            int r=len-1;
            while(l<r)
            {
                if(l==i)  l++;
                if(r==i)  r--;
                if(l>=r) break;
                int x=nums[l]+nums[i]+nums[r];
                int n=abs(x-target);
               if(n<ins)
                  {sum=x;
                   ins=n;
                  }
                if(x==target)  return sum;
                if (x>target) r--;
                if(x<target) l++;             
            }
        }
        return sum;
    }
};
/* 暴力法
class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int target) {
        int p=0;
        int len=nums.size();
        while(1){           
        for (int i=0;i<len-2;i++)
            for(int j=i+1;j<len-1;j++)
                for(int k=j+1;k<len;k++)
                    if(nums[i]+nums[j]+nums[k]==target+p)
                        return target+p;
            if(p<0)p=-p;
            else {p++;p=-p;}
        }
    }
};
*/
```

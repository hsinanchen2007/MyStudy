第一种解法：贪心
Brute force,  遍历所有丑数，排序，输出第n个
Time complexity:O（NlogN） runtime 112ms
Space complexity:O (N)  
有个 trick， 如果使用static 命名vector 可以使runtime 降低为 48ms

```
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>nums;
        
        for(long a=1;a<=INT_MAX;a*=2)
            for(long b=a;b<=INT_MAX;b*=3)
                for(long c=b;c<=INT_MAX;c*=5)
                    nums.push_back(c);
        
        sort(nums.begin(),nums.end());
        
        return nums[n-1];
        
    }
};


```


第二种解法：使用类似动态规划的方法
```
class Solution {
public:
    int nthUglyNumber(int n) {
        
        static vector<int>nums={1};
        static  int i2=0;
        static  int i3=0;
        static  int i5=0;
        
        while(nums.size()<n)
        {
            const int next2=nums[i2]*2;
            const int next3=nums[i3]*3;
            const int next5=nums[i5]*5;
            
            int next=min(next2,min(next3,next5));
            if(next==next2) ++i2;
            if(next==next3) ++i3;
            if(next==next5) ++i5;
            nums.push_back(next);
        }
        
        return nums[n-1];
        
    }
};

```


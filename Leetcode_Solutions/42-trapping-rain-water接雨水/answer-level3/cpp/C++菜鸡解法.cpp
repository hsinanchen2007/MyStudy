```
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<2)    return 0;
        //这道题目可以看成两个数组值相减，可以发现雨水覆盖后变成一个山峰，即从0到达max或者从
        //height.size()-1到达max的时候都是非递减数列。把这个数组的总值减去之前初始数组的总值
        //即为答案              time:4ms 94.75%   memory: 6.8ms, 100% 
        int max=0;                      //找到峰值
        int sum=0;                      //初始数组值
        int ans=height[0];              //ans为雨水覆盖的数组值
        for(int i=0;i!=height.size();i++){
            if(height[i]>max)
                max = height[i];
            sum+= height[i];
        }
        int j=0;                        //峰值的下标
        for(int i=0;i!=height.size();i++)
        {
            if(height[i]==max)
            {
                j=i;
                break;
            }
        }
        for(int i=1;i<=j;i++){
            if(height[i]<height[i-1])
                height[i]=height[i-1];
            ans += height[i];
        }
        for(int i=height.size()-1;i>j;i--){
            if(height[i-1]<height[i])
                height[i-1]=height[i];
            ans += height[i];
        }
        return ans-sum;
    }
};
```



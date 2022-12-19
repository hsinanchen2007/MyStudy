这道题可运用分而治之的思想来解决。
运用类似归并排序的方法，我写了以下代码，试了几个例子是没有错的，请大家帮忙有错误吗？谢谢！
```
class Solution {
public:
    int maxProduct(vector<int>& nums,int i,int j) { // i是初始位置的下标，j是终止位置的下标。
        int middle = (i+j)/2;  
        if(i==j) return nums[i];
        int m1 = maxProduct(nums,i,middle);
        int m2 = maxProduct(nums,middle+1,j);
        int m3 = 1;
        for(int k=0;k<=j;k++){
            m3 *= nums[k];
        }
        int m = max(m1,m2);
        m = max(m,m3);
        return m;
    }
};
```



### 代码

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans=0;//记录最终结果
        int sum=0;//记录每个子数组元素之和

        for(int i=0;i<k;i++)
            sum+=arr[i];
        if(sum>=threshold*k) ans++;

        int len=arr.size();
        //不断向后推进
        for(int i=0;i<len-k;i++)
        {
            sum-=arr[i];
            sum+=arr[k+i];
            if(sum>=threshold*k) ans++;
        }

        return ans;
    }
};
```
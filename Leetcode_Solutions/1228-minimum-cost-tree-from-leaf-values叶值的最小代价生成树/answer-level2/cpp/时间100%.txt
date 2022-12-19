### 解题思路
每一次找相邻两个乘积最小的值，并且删除这两个中较小的值即可，直到arr的size为1返回结果

### 代码

```cpp
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int sum=0;
        while(arr.size()!=1)
        {
            int temp=INT_MAX,inde;
            for(int i=0;i<arr.size()-1;++i)
            {
                if(arr[i]*arr[i+1]<temp)
                {
                    inde=arr[i]>=arr[i+1]?i+1:i;
                    temp=arr[i]*arr[i+1];
                }
            }
            sum+=temp;
            arr.erase(arr.begin()+inde);
        }
        return sum;
    }
};
```
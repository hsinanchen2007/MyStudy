### 解题思路
我们假设两个哨兵设置在数组头和尾两个位置，第一次快排结束后两个哨兵会相遇在数组的第N个位置，把数组分成[0...N-1],N,[N+1...末尾]，N在中间，左右两个数组都是无序的，但是左边的数组所有的数都小于arr[N-1](下标从0开始)，所以我们通过第一次快排能得到数组的前N个数，如果N大于K，则继续快排N左边的数组，小于K的话则快排右边的数组，等于的话就输出左边的数组即可

### 代码

```cpp
class Solution {
public:
    int K;
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        K = k;
        vector<int> res;
        
        qsort(arr,0,arr.size()-1);
        for(int i=0;i<k;++i)
        {
            res.push_back(arr[i]);
        }
        return res;

    }

    void qsort(vector<int>& vec,int start , int end )
    {
        if(start>= end)
            return ;
        int i= start;
        int j = end;
        bool flag = true;

        while(i!=j)
        {
            if(vec[j]>=vec[i])
            {
                if(flag)
                    --j;
                else
                    ++i;
            }
            else
            {
                int temp = vec[j];
                vec[j] = vec[i];
                vec[i] = temp;
                flag = !flag;
            }
        }
        if(i>K)
        {
            qsort(vec,start,i-1);
        }
        else{
            qsort(vec,i+1,end);
        }
        return;
    }
};
```
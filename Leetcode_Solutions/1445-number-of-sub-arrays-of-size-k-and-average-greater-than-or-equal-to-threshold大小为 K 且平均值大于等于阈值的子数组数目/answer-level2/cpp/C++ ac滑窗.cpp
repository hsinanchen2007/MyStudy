### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int _res=0;
        threshold=threshold*k;//不想每次循环都计算 ps:一组数的平均值>=t，则这组数的和>=n(这组数的个数)*t
        //第一个窗口
        int i=k-1,_tempsum=0;
        for(int j=0;j<=i;j++){
                _tempsum+=arr[j];
        }
        if(_tempsum>=threshold)_res++;
        //开始滑动，每次只用减去窗口头并加上下一个元素
        while(i+1<arr.size()){
            _tempsum=_tempsum-arr[i-k+1]+arr[i+1];
            if(_tempsum>=threshold)_res++;
            i++;
        }
        return _res;
    }
};
```
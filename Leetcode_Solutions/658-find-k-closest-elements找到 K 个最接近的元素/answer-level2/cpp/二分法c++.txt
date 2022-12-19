执行用时 :112 ms, 在所有 C++ 提交中击败了93.99%的用户
内存消耗 :13.5 MB, 在所有 C++ 提交中击败了43.20%的用户
```
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        int left = 0;
        int right = arr.size() - 1;
        //处理特殊情况
        if(arr[0] >= x)
        {
            for(int i = 0;i<k;++i)
                result.push_back(arr[i]);
            return result;
        }
        if(arr[right]<=x)
        {
            for(int i = k - 1;i>=0;--i)
                result.push_back(arr[right - i]);
            return result;
        }
        //寻找最接近的一个数
        int middle;
        while(left + 1<right)
        {
            middle = left + (right - left)/2;
            if(arr[middle]<x)
                left = middle;
            else if(arr[middle]>x)
                right = middle;
            else
                break;                  
        }
        if(arr[right] - x < abs(arr[middle] - x))
            middle = right;
        if(x - arr[left] <= abs(arr[middle] - x))
            middle = left;
        left = middle;
        right = middle;
        //寻找接近的集合
        while(left>=0 && right<arr.size() && left+k - 1>right)
        {
            if(abs(arr[left] - x) == abs(arr[right] - x))
            {
                --left;
            }
            else if(abs(arr[left] - x) < abs(arr[right] - x))
                --left;
            else if(abs(arr[left] - x) > abs(arr[right] - x))
                ++right;
        }
        //处理集合
        if(right>arr.size() - 1)
        {
            left = arr.size() - k;
            right = arr.size() - 1;
            for(int t = left;t<left + k;++t)
                result.push_back(arr[t]);
            return result;
        }  
        else if(left<0)
        {
            left = 0;
            right = left + k - 1;
        }
        while(abs(arr[left] - x) == abs(arr[right] - x))
        {
            if(left - 1<0)
                break;
            else if(abs(arr[left - 1] - x) == abs(arr[left] - x))
            {
                --left;
                --right;
            }
            else
                break;
        }
        if(right - left == k - 1 && right<arr.size() - 1 && abs(arr[left] - x) > abs(arr[right + 1] - x))
            ++left;
        else if(right - left > k - 1 && right<arr.size() - 1 && abs(arr[left] - x) > abs(arr[right] - x))
            ++left;
        if(right - left == k - 1 && left > 0 && abs(arr[left - 1] - x) < abs(arr[right] - x))
            --left;
        for(int t = left;t<left + k;++t)
            result.push_back(arr[t]);
        return result;
    }
};
```

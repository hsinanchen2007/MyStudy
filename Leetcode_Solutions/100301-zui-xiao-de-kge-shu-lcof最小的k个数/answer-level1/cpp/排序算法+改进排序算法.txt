# 一.快速排序算法
将数组进行快速排序，输出最小的k个数。
快排的时间复杂度是：O(nlogn)
快速空间复杂度是：O(logn)~O(n)，递归会用到栈
# 运行效果
执行用时 :92 ms, 在所有 C++ 提交中击败了14.46%的用户
内存消耗 :19.4 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int len=arr.size();
        vector<int> ans;
        if(len<k) return ans;
        
        sort(arr.begin(),arr.end());
        for(int i=0;i<k;i++)
            ans.push_back(arr[i]);
        return ans;
    }
};
```
# 第二，改进快速排序算法
不必要全部把元素排序，根据快速排序的性质，我们只要知道当第k个元素找到自己的位置时候。
前k个元素就是最小的k个元素。
# 执行效果
执行用时 :
76 ms, 在所有 C++ 提交中击败了20.82%的用户
内存消耗 :19 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码
```
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
         vector<int> ans;
        if(k==0 || arr.size()<k) return ans;  //注意这些特殊输入情况，否则会出现错误
        int start=0;
        int end=arr.size()-1;
        int index=Partition(arr,start,end);
        while(index!=k-1)
        {
            if(index>k-1)
            {
                end=index-1;
                index=Partition(arr,start,end);
            }
            else
            {
                start=index+1;
                index=Partition(arr,start,end);
            }
        }
        for(int i=0;i<k;i++)
            ans.push_back(arr[i]);
        return ans;
        
    }
    int Partition(vector<int>&arr,int start,int end)
    {
        int i=start;
        int j=end;
        int pivot=arr[i];
        while(i<j)
        {
            while((i<j)&&(arr[j]>=pivot))j--;
                arr[i]=arr[j];
            while((i<j)&&(arr[i]<=pivot))i++;
                arr[j]=arr[i];
        }
        arr[i]=pivot;
        return i;
    }
};
```


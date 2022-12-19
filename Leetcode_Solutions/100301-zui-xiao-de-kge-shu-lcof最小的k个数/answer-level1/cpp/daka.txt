```
class Solution {
public:
    //利用快排思想
    int quickSortCore(vector<int>& arr, int begin, int end)
    {
        if(begin >= end)
            return begin;
        int key = arr[begin];
        while(begin < end)
        {
            while(begin < end && arr[end] >= key)
                end--;
            if(begin < end)
                arr[begin] = arr[end];
            while(begin < end && arr[begin] <= key)
                begin++;
            if(begin < end)
                arr[end] = arr[begin];
        }
        arr[begin] = key;
        return begin;
    }
    
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        vector<int> rec;
        int begin = 0, end = arr.size() - 1;
         
        while(k != 0)
        {
            int index = quickSortCore(arr, begin, end);
            if(index - begin + 1 <= k)
            {
                k = k - (index - begin + 1);
                for(int i = begin; i <= index; i++)
                    rec.push_back(arr[i]);
                begin = index + 1;
            }
            else
                end = index - 1;
        }
        return rec;
    }  
};
```

```C++ []
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if(k == 0) return res;
        if(k>arr.size()) return arr;
        int start = 0;
        int end = arr.size()-1;
        int index = partition(arr, start, end);
        while(index != k-1)
        {
            if(index > k-1)
            {
                end = index-1;
                index = partition(arr, start, end);
            }
            else
            {
                start = index+1;
                index = partition(arr, start, end);
            }
        }
        for(int i=0; i<k; i++)
            res.push_back(arr[i]);
        return res;
    }

    int partition(vector<int>& arr, int start, int end)
    {
        int i=start; int j = end;
        while(i<j)
        {
            while(i<j && arr[i]<=arr[j]) j--;
            if(arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            while(i<j && arr[i]<= arr[j]) i++;
            if(arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }

        return i;
    }
};
```


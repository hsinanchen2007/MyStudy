```
class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        if(arr.size() < 3) return arr;
        vector<int> arr2 = arr;
        bool change = true;
        while(change == true)
        {
            change = false;
            for(int i=1; i<arr.size()-1;i++)
            {
                if(arr[i] < arr[i-1] && arr[i] < arr[i+1])
                {
                    change = true;
                    arr2[i]++;
                }
                else if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
                {
                    change = true;
                    arr2[i]--;
                }
            }
            arr = arr2;
        }
        return arr;
    }
};
```
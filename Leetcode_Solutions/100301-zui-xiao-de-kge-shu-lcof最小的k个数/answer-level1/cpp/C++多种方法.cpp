

### 代码

```cpp
class Solution {
public:
    //暴力
    vector<int> smallForward(vector<int>& arr, int k)
    {
        for(int i = k; i < arr.size(); i++)
        {
            for(int j = 0; j < k; j++)
            {
                if(arr[i] < arr[j]) swap(arr[i], arr[j]);
            }
        }
        vector<int> res(arr.begin(), arr.begin()+k);
        return res;
    }
    //排序后选取
    vector<int> sortFind(vector<int>& arr, int k)
    {
        sort(arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin()+k);
    }
    //快排
    vector<int> quickSort(vector<int>& arr, int k)
    {
        int i = -1;
        int end = arr.size() - 1;
        int start, low, high;
        while(i != k-1)
        {         
            if(i>k-1)
            {
                low = start;
                high = i-1;
                end = high;
            }
            else
            {
                low = i+1;
                high = end;
                start = low;
            }
                
             int tmp = arr[low];
             while(low < high)
             {
                while(low<high && arr[high]>tmp)
                    high--;
                arr[low] = arr[high];
                while(low<high && arr[low]<=tmp)
                    low++;
                arr[high] = arr[low];
             }
             arr[low] = tmp;
             i = low;
        }  
        return vector<int>(arr.begin(), arr.begin()+k) ;
    }

    //全堆排序
    vector<int> heapSort(vector<int>& arr, int k)
    {
        for(int i = arr.size()/2-1; i>=0; i--)
            shiftdown(arr, i, arr.size());
        for(int i = arr.size()-1; i>0;i--)
        {
            swap(arr[0],arr[i]);
            shiftdown(arr, 0, i);
        }
        return vector<int>(arr.begin(), arr.begin()+k);
    }

    //部分堆排序
    vector<int> partHeapSort(vector<int>& arr, int k)
    {
        for(int i = k/2-1; i >= 0; i--)
            shiftdown(arr,i,k);
        for(int i = k; i < arr.size(); i++)
        {
            if(arr[i]<arr[0])
            {
                swap(arr[0], arr[i]);
                shiftdown(arr,0,k);
            }
        }
        return vector<int>(arr.begin(), arr.begin()+k);   
    }

    void shiftdown(vector<int>& arr, int cur, int len)
    {
        while(cur*2+1<len)
        {
            int leaf = cur*2+1;
            if(leaf+1<len && arr[leaf]<arr[leaf+1])
                leaf++;
            if(arr[cur]>=arr[leaf]) break;
            swap(arr[cur],arr[leaf]);
            cur = leaf;     
        }
    }
    //数组计次
    vector<int> arrCount(vector<int>& arr, int k)
    {
        vector<int> counts(10001, 0);
        vector<int> res;
        for(int i = 0; i < arr.size(); i++)
            counts[arr[i]]++;
        for(int i = 0; i < counts.size(),k > 0; i++)
        {
            while(k>0 && counts[i]>0)
            {
                res.push_back(i);
                counts[i]--;
                k--;
            }
        }
        return res;
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //暴力
        // return smallForward(arr, k);

        //排序后选取
        // return sortFind(arr, k);

        //快排
        // return quickSort(arr, k);

        //全堆排序
        // return heapSort(arr,k);

        //部分堆排序
        // return partHeapSort(arr, k);

        //数组计次
        return arrCount(arr,k);
    }   
};
```
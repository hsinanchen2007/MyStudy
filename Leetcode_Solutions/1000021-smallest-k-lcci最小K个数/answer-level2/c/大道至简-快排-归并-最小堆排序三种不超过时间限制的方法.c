![image.png](https://pic.leetcode-cn.com/1db93deee7001eff6b84d965ccdfefa1298d3eaf4c71855a90f897bb41254904-image.png)

最小堆：
```
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if(arr.empty()) return {};
        vector<int> v;

        int len=arr.size();
        HeapSort(arr,v,k,len);
        return v;        
    }

    void HeapSort(vector<int>& arr,vector<int>& v,int k,int len)
    {
        for(int i=(len-1)/2;i>=0;i--)
        {
            HeapAdjust(arr,i,len);
        }
        for(int j=len-1;j>=len-k;j--)
        {
            v.push_back(arr[0]);
            swap(arr[0],arr[j]);
            HeapAdjust(arr,0,j);
        }
    }
    void HeapAdjust(vector<int>& arr,int idx,int len)
    {
        int i=idx,j=2*i+1;
        int tmp=arr[i];
        while(j<len)
        {
            if(j+1<len&&arr[j+1]<arr[j])
                j++;
            if(arr[j]<tmp)
            {
                arr[i]=arr[j];
            }
            else
                break;
            i=j;
            j=2*i+1;
            
        }
        arr[i]=tmp;    
    }
};
```


快排：
```
std::mt19937 rnd(time(NULL));
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if(arr.empty()) return {};
        vector<int> v;
        
        QuickSort(0,arr.size()-1,arr);
        v.assign(arr.begin(),arr.begin()+k);
        return v;
    }
    void QuickSort(int left,int right,vector<int>& arr)
    {
        if(left<right){
        int mid=partsplit(left,right,arr);
        QuickSort(left,mid-1,arr);
        QuickSort(mid+1,right,arr);
        }
    }

    int partsplit(int low,int high,vector<int>& arr)
    {
        swap(arr[low],arr[rnd()%(high-low+1)+low]);
        int pivot=arr[low];
        int i=low,j=high+1;

        for(;;)
        {
            while(i<j&&arr[--j]>=pivot){};
            while(i<j&&arr[++i]<=pivot){};

            if(i>=j) break;
            swap(arr[i],arr[j]);
        } 
        swap(arr[low],arr[j]);
        return j;
    }
};
```


归并：
```
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if(arr.empty()) return {};
        MergeSort(arr,0,arr.size()-1);

        vector<int> v;
        v.assign(arr.begin(),arr.begin()+k);
        return v;
    }
    void Merge(vector<int>& arr,vector<int> &TmpArray, int leftStart, int rightStart, int rightEnd) {
        int i, leftEnd, nums, tmp;
        leftEnd = rightStart - 1;
        tmp = leftStart;
        nums = rightEnd - leftStart + 1;

        while (leftStart <= leftEnd && rightStart <= rightEnd) {
            if (arr[leftStart] <= arr[rightStart])
                TmpArray[tmp++] = arr[leftStart++];
            else
                TmpArray[tmp++] = arr[rightStart++];
        }

        while (leftStart <= leftEnd)
            TmpArray[tmp++] = arr[leftStart++];
        while (rightStart <= rightEnd)
            TmpArray[tmp++] = arr[rightStart++];

        for (i = 0; i < nums; i++, rightEnd--)
            arr[rightEnd] = TmpArray[rightEnd];
    }

    void Msort(vector<int>& arr,vector<int> &TmpArray, int left, int right) {
        int center;
        if (left < right) {
            center = (left + right) >> 1;
            Msort(arr,TmpArray, left, center);
            Msort(arr,TmpArray, center + 1, right);

            if (arr[center] > arr[center + 1])//优化
                Merge(arr,TmpArray, left, center + 1, right);
        }
    }

    void MergeSort(vector<int>& arr,int left,int right) {
        vector<int> TmpArray(arr.size(), 0);
        Msort(arr,TmpArray, left, right);
        vector<int>().swap(TmpArray);
    }
};
```

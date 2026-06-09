最小堆排序
```
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.empty()) return {};
        int len=arr.size();

        for(int i=len/2-1;i>=0;i--){
            HeapAdjust(arr,i,len);
        }

        vector<int> v;
        for(int j=len-1;j>len-1-k;j--){
            v.push_back(arr[0]);
            swap(arr[0],arr[j]);
            HeapAdjust(arr,0,j);
        }
        return v;
    }
    void HeapAdjust(vector<int>& arr,int s,int len){
        int j=s*2+1;
        int tmp=arr[s];
        while(j<len){
            if(j<len-1&&arr[j+1]<arr[j]) j++;
            if(tmp>arr[j]) arr[s]=arr[j];
            else break;
            s=j;
            j=2*s+1;
        }
        arr[s]=tmp;
    }
};
```
快速排序
```
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.empty()||k==0) return{};
        int len=arr.size();
        return Qsort(arr,k-1,0,len-1);
    }
    
    vector<int> Qsort(vector<int>& arr,int k,int left,int right){
        vector<int> v;
        int mid=Partition(arr,left,right);
        if(mid==k)  {
            v.assign(arr.begin(),arr.begin()+mid+1);
            return v;
        }
        return mid>k?Qsort(arr,k,left,mid-1):Qsort(arr,k,mid+1,right);
    }

    int Partition(vector<int>& arr,int left,int right)
    {
        std::mt19937 rnd(time(0));
        swap(arr[left],arr[rnd()%(right-left+1)+left]);
        int pivot=arr[left];
        int i=left,j=right+1;

        for(;;)
        {
            while(i<j&&arr[--j]>=pivot){}
            while(i<j&&arr[++i]<=pivot){}

            if(i>=j) break;
            swap(arr[i],arr[j]);
        }
        
        swap(arr[left],arr[j]);
        return j;
    }
};
```

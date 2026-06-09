### 解题思路
快排真香，topK会了呀

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> pp;
        int l=0;
        int r=arr.size()-1;
        int tmp=arr[l];
       if(k==0)
       return pp;
while(1){
    int i=l;
    int j=r;
    tmp=arr[l];
    
    while(i<j){
        while(arr[j]>tmp&&i<j)
            j--;
        while(arr[i]<=tmp&&i<j)
            i++;
        int p=arr[i];
        arr[i]=arr[j];
        arr[j]=p;
    }
    
   
    //return pp1;
    if(tmp>arr[i])
    {int p=arr[i];
    arr[i]=tmp;
    arr[l]=p;}
    if(i+1==k)
        break;
    else if(i+1<k)
        l=i+1;
    else if(i+1>k)
        r=i-1;
}
for(int i=0; i<k; i++)
    pp.push_back(arr[i]);

return pp;
    }
};
```
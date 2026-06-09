### 解题思路


### 代码

```cpp
class Solution {
public:
void Quicksort(vector<int> &arr,int low,int high,int k)
{
  if(low<high)
  {
      int pos=partion(arr,low,high);
      if(pos==k-1)  //下标已经来到第k个位置，说明pos前面的都是小的
        return ;
      Quicksort(arr,low,pos-1,k);
      Quicksort(arr,pos,high,k);
  }

}
int partion(vector<int> &arr,int low,int high)
{
    //选取基准：随机选取
    int n=rand()%(high-low+1)+low;  //随机从数组中选取一个下标
    swap(arr[n],arr[low]);
    int pvalue=arr[low];//选取第一个数为基准
    while(low<high)
    {
        while(high>low&&arr[high]>pvalue)  //从右边找第一个小于它的数，将它放到arr[low]位置
        high--;
    arr[low]=arr[high];
        while(low<high&&arr[low]<=pvalue)
        {
            low++;
        }//找到从左边开始第一个大于pvalue,把它放到后面high位置
        arr[high]=arr[low];
        
        //一直循环直到low>high
    }
    arr[low]=pvalue;
    return low;  //low（下标位置）左边是小于pvalue的值，右边是大于它的
}
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //快排；sort函数的本质也是快排
        vector<int> res;
    if(k<=0)
    return res;
    Quicksort(arr,0,arr.size()-1,k);
    for(int i=0;i<k;i++)
    res.push_back(arr[i]);

    return res;

    }
};
```
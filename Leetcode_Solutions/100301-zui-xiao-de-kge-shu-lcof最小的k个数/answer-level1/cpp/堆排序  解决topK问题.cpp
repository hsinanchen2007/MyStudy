### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:

    void heap(vector<int>& arr,int len,int root){
                
        int tmp = arr[root];
        int i=0;
        for(i=2*root+1;i<len;i=i*2+1){
            if(i+1<len && arr[i]>arr[i+1]){
                i++;
            }
            if(tmp>arr[i]){      //不是arr[root]>arr[i]，找了半天，在[0,1,1,2,4,4,1,3,3,2]为例时
                arr[root]=arr[i];
                root=i;
            }
        } 
        arr[root]=tmp;
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int len = arr.size();
        for(int i=len/2-1;i>=0;i--){  //建堆
            heap(arr,len,i);
        }        
        vector<int> ans;
        int tmp=0;
        for(int j=0;j<k;j++){       //交换，再排序
            ans.push_back(arr[0]);
            tmp = arr[0];
            arr[0]=arr[len-1-j];
            arr[len-1-j]=tmp;
            heap(arr,len-j-1,0);
        }
        return ans;
        // int tmp;
        // for (int i = len-1;i>len-1-k; --i) {
        //     ans.push_back(arr[0]);
        //     tmp = arr[0];
        //     arr[0]=arr[i];
        //     arr[i]=tmp;
        //     heap(arr, i,0);
        // } 
        //return ans;
    }
};
```
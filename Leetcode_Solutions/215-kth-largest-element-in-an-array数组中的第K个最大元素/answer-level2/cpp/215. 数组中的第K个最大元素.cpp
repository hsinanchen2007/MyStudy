### 大顶堆
建立大顶堆，每次输出一个堆顶元素，直到K个。
### 时间/空间复杂度
时间：O（n/2logn）
空间：O（1）
### 代码

```cpp
class Solution {
public:
    void adjustHeap(vector<int> &heap,int i,int n){
        int left=2*i+1;
        int right=2*i+2;
        int maxNum=heap[i],maxIndex=i;
        if(left<n && maxNum<heap[left]){
            maxNum=heap[left];
            maxIndex=left;
        }
        if(right<n && maxNum<heap[right]){
            maxNum=heap[right];
            maxIndex=right;
        }
        if(maxNum!=heap[i]){
            int tmp=heap[i];
            heap[i]=heap[maxIndex];
            heap[maxIndex]=tmp;
            adjustHeap(heap,maxIndex,n);
        }
    }
    int findKthLargest(vector<int>& heap, int k) {
        int n=heap.size();
        for(int i=n/2-1;i>=0;--i){
            adjustHeap(heap,i,n);
        }
        int count=0;
        int ans=0;
        for(int i=n-1;i>=0;--i){
            int top=heap[0];
            if(++count==k){
                ans=top;
                break;
            }
            heap[0]=heap[i];
            heap[i]=top;
            adjustHeap(heap,0,i);
        }
        return ans;
    }
};
```
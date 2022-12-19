### 1.使用队列(其实队列就是堆实现的)
```java []
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        Queue q=new PriorityQueue<Integer>((a,b)->{return b-a;});
        for(int i=0;i<arr.length;i++){
            q.offer(arr[i]);
            while(q.size()>k)q.poll();
        }
        int []res=new int[k];
        for(int i=0;i<k;i++){
            res[i]=(int)q.peek();
            q.poll();
        }
        return res;
    }
}
```
```c++ []
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int,vector<int> ,less<int> > q;
        for(int i=0;i<arr.size();i++){
            q.push(arr[i]);
            while(q.size()>k)q.pop();
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
```
### 2.手写堆
```cpp
const int maxn=10005;
class Solution {
public:
    int heap[maxn];
    int size;
    void heapfy(int k,int len){
        int ls=k<<1,rs=k<<1|1;
        int index=k;
        if(ls<=len&&heap[index]<heap[ls])index=ls;
        if(rs<=len&&heap[index]<heap[rs])index=rs;
        if(index!=k){
            swap(heap[index],heap[k]);
            heapfy(index,len);
        }
    }
    void buildheap(){
        for(int i=size>>1;i>0;i--)heapfy(i,size);
    }
    void heapsort(){
        for(int i=size;i>0;i--){
            swap(heap[1],heap[i]);
            heapfy(1,i-1);
        }
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        size=k;
        for(int i=0;i<k;i++)heap[i+1]=arr[i];
        buildheap();
        for(int i=k;i<arr.size();i++){
            if(arr[i]<heap[1]){
                heap[1]=arr[i];
                heapfy(1,k);
            }
        }
        vector<int> res(heap+1,heap+k+1);
        return res;
    }
};
```

### 3.快速排序思想
```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quick_select(arr,0,arr.size()-1,k);
        arr.resize(k);
        return arr;
    }
    void quick_select(vector<int>&arr,int l,int r,int k){
        if(l>=r)return;
        int tmp=arr[l];
        int i=l,j=r;
        while(i<j){
            while(i<j&&arr[j]>=tmp)j--;
            while(i<j&&arr[i]<=tmp)i++;
            if(i<j)swap(arr[i],arr[j]);
        }
        swap(arr[i],arr[l]);
        if(i<k)quick_select(arr,i+1,r,k);
        if(i>k)quick_select(arr,l,i-1,k);
        if(i==k)arr.resize(k);
    }
};
```
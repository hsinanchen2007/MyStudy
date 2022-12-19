c++ 快排  每个案列都随机化一下  避免极端案例

- 记得快排前，对数组随机化一下，避免极端案例，退化成 O(N^2)冒泡算法

**非递归**


```cpp
class Solution {
public:
    int partition(vector<int>& nums,int left,int right){
        int randIndex = rand()%(right-left+1)+left;
        swap(nums[left], nums[randIndex]);
        int key = nums[left];

        while(left<right){
            while(left<right && nums[right] >= key) right--;
            nums[left] = nums[right];
            while(left<right && nums[left] <= key) left++;
            nums[right] = nums[left];
        }
        nums[left] = key;
        return left;
    }

    int findKthLargest(vector<int>& nums, int k) {
        
        int len = nums.size();
        if(!len) return 0;

        srand(time(NULL));

        typedef pair<int,int> P;
        stack<P> ms;
        ms.push(P(0,len-1));
        while(!ms.empty()){
            int left = ms.top().first;
            int right = ms.top().second;
            ms.pop();
            if(left > right) continue;
            
            int mid = partition(nums,left,right);
            if(mid == len-k){
                return nums[mid];
                break;
            }
            if(mid < len-k) ms.push(P(mid+1,right));
            else ms.push(P(left,mid-1));
        }

        return -1;
    }
};

```

**递归**
```swift
class Solution {
public:
    int partition(vector<int>& nums,int left,int right){
        int randIndex = rand()%(right-left+1)+left;
        swap(nums[left], nums[randIndex]);
        int key = nums[left];

        while(left<right){
            while(left<right && nums[right] >= key) right--;
            nums[left] = nums[right];
            while(left<right && nums[left] <= key) left++;
            nums[right] = nums[left];
        }
        nums[left] = key;
        return left;
    }

    int dfs(vector<int>& nums, int left,int right,int k){
        if(left > right) return -1;
        int mid = partition(nums,left,right);
        if(mid == nums.size()-k) return nums[mid];
        else if(mid < nums.size()-k) return dfs(nums,mid+1,right,k);
        else return dfs(nums,left,mid-1,k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        
        int len = nums.size();
        if(!len) return 0;

        srand(time(NULL));
        return dfs(nums,0,len-1,k);
    }
};

```



**小顶堆**

手动维护一个大小为k小顶堆，最后弹出堆顶元素 即为小顶堆中最小的元素  也是整个数组中第k大的元素

```cpp
class Solution {
public:
    void adjust_heap(vector<int>& nums,int index){
        int left = 2*index + 1;
        int right = 2*index + 2;
        int len = nums.size();
        int maxindex =index;

        if(left<len && nums[left] < nums[maxindex]) maxindex = left;
        if(right<len && nums[right] < nums[maxindex]) maxindex = right;
        if(index!=maxindex){
            swap(nums[index],nums[maxindex]);
            adjust_heap(nums,maxindex);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int res = 0;
        if(len<0) return res;
        
        vector<int> tmp(nums.begin(),nums.begin()+k);

        for(int i=tmp.size()/2;i>=0;i--)
            adjust_heap(tmp,i);
        
        for(int i=k;i<len;i++){
            if(nums[i] > tmp[0]){
                tmp[0] = nums[i];
                adjust_heap(tmp,0);
            }
        }
        return tmp[0];
    }
};
```
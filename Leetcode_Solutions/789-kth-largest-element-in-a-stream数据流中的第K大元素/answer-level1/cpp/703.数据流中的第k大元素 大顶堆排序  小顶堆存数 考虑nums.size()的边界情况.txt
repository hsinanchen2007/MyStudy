### 解题思路
此处撰写解题思路

（1）大顶堆排序取前k大的元素
（2）悉数入小顶堆
（3）add时的数比堆顶小，忽略
（4）add时的数比堆顶大，则重新建立堆

对于出错的示例
需要考虑，输入数据中：
（1）nums.size() == 0 的情况
（2）nums.size() < k的情况，导致add时数比小顶堆小也不能忽略


### 代码

```cpp
#include <vector>
#include <algorithm>

//取最大的k个元素，得容量为k的小顶堆
//满足的元素即在堆顶部
//其余的忽略
//每次新增，若更大，则入堆，否则忽略

//nums 初始为空的情况


class KthLargest {
    int kVal;
    vector<int> myHeap ={};

public:
    KthLargest(int k, vector<int>& nums) {
        kVal = k;
        if(0 == nums.size()){
            return;
        }


        //大顶堆
        make_heap(nums.begin(), nums.end(), less<int>());
        //堆排序，取较大的K个/size个
        k = (k < nums.size()) ? k : nums.size();
        for(int i = 0; i < k; i++){
            myHeap.push_back(*nums.begin());
            pop_heap(nums.begin(), nums.end()-i, less<int>());  //pop_heap之后在容器的尾部
                //nums.pop_back();
        }

        //小顶堆
        make_heap(myHeap.begin(), myHeap.end(), greater<int>());
    }
    
    int add(int val) {
        if(0 == myHeap.size()){
            myHeap.push_back(val);
             //小顶堆
            make_heap(myHeap.begin(), myHeap.end(), greater<int>());
            if(1 == kVal){
                return *myHeap.begin();
            }
        }

        if( myHeap.size() < kVal){
            myHeap.push_back(val);
            push_heap(myHeap.begin(), myHeap.end(), greater<int>());
        }
        else if(val < *myHeap.begin() ){
            1;
            //return *myHeap.begin();
        }
        else{
            pop_heap(myHeap.begin(), myHeap.end(), greater<int>());
            myHeap.pop_back();
            myHeap.push_back(val);
            push_heap(myHeap.begin(), myHeap.end(), greater<int>());
        }
        return *myHeap.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```


这是之前超时的一种做法：
```cpp
#include <vector>
#include <algorithm>

//每次add都得for k次，导致超时
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        nums_p = &nums;
        make_heap((*nums_p).begin(), (*nums_p).end(), less<int>());
        kVal = k;
    }
    
    int add(int val) {
        make_heap((*nums_p).begin(), (*nums_p).end(), less<int>());
        (*nums_p).push_back(val);
        push_heap((*nums_p).begin(), (*nums_p).end(), less<int>());
        for(int i = 0; i < kVal-1; ++i){
            pop_heap((*nums_p).begin(), (*nums_p).end()-i, less<int>());  //-i是关键
        }
        return *(*nums_p).begin();
    }

private:
    vector<int> *nums_p;
    int kVal;

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```
### 解法一:
##### 采用大顶堆和小顶堆的方式，求数据中的中位数，具体见[295.数据流的中位数](https://leetcode-cn.com/problems/find-median-from-data-stream/solution/da-ding-dui-xiao-ding-dui-by-jarvis1890/)。这里不再赘述！该题和[295.数据流中的中位数]不同的是，该题有个窗口，需要从堆里删除元素。而堆只能从删除堆顶元素！因此在这里先用map将需要删除的元素记录起来，等它出现在堆顶时，就删除它。
#####    初始化的时候，会使得大顶堆中元素的个数等于小顶堆元素的个数或者比小顶堆中元素的个数多一，这里可以求出初始的中位数。那么在滑动窗口后，如何保证这两个堆之间仍然具有初始化的时候的特性？右移窗口后，会删掉之前窗口的最左边的元素，还要加入当前窗口的最右边的元素。假如需要删除的元素要从大顶堆中删除，新增元素也是假如大顶堆中，很明显它仍具有初始化的时候的属性。假如删除在大顶堆，加入在小顶堆，那么只要把小顶堆的堆顶元素加入到大顶堆即能事它们俩具有初始的特性。反之亦然。


### 解法一代码：
```
class Solution {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

    //用于存储待删除的元素
    unordered_map<int, int> _map;

    vector<double> ans;
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // 初始化
        for(int i=0;i<k;i++){
            small.push(nums[i]);
        }
        for(int i=0;i<k/2;i++){
            large.push(small.top());
            small.pop();
        }

        //滑动窗口
        int left = 0, right = k;
        while(true){
            if(k%2==1){
                ans.push_back(small.top());
            }  
            else {
                ans.push_back((double(small.top()) + double(large.top())) * 0.5);
            }
            //当right = num.size()时，以上代码还需要执行一次，把最后一个中位数加入ans
            //但是窗口不能再右移了，因此break

            if(right >= nums.size()) break;
            int balance = 0;

            //窗口右移，右移删除的元素加入待删除的map中，后面有代码会删除
            int _old = nums[left++];
            _map[_old] ++;
            balance += (_old <= small.top() ? -1 : 1);

            //右移将新元素加入到堆中
            int _new = nums[right++];
            if(!small.empty() && _new <= small.top()){
                balance ++;
                small.push(_new);
            }
            else{
                balance --;
                large.push(_new);
            }
            // 上述几行代码执行之后，可以知道balance可以取3个值，-2, 0, 2

            // balance > 0意味滑动窗口后，small在原来的基础上比large多了两个元素 (原来small大小可能等于large或者small大小等于large+1)
            // 从large取出一个加入到small，这样large元素个数-1，small元素个数+1，达到平衡
            if(balance > 0){
                large.push(small.top());
                small.pop();
            }

            //balance < 0意味着滑动窗口后，large比small多了两个元素
            if(balance < 0){
                small.push(large.top());
                large.pop();
            }

            //删除元素
            while(!small.empty() && _map[small.top()]){
                _map[small.top()] --;
                small.pop();
            }
            while(!large.empty() && _map[large.top()]){
                _map[large.top()] --;
                large.pop();
            }
        }
        return ans;
    }
};
```


### 解法二：

##### 采用c++ stl 中的multiset。因为multiset是具有排序功能的,我们只需要初始化的时候找到其中位数，设为mid。以后每加入一个中位数进来，就和当前的mid指向的中位数进行比较，如果新加入的较大，则mid++指向下一位，否则不做改变。删除时，如果待删除元素比mid指向的还小，mid++，否则不做改变。如此修改mid，知道访问完所有元素！由于erase函数采用key的方式删除会删除所有为key的元素，因此采用下标删除方法。具体见[erase传送门](https://en.cppreference.com/w/cpp/container/multiset/erase)。此外，对stl算法模板next不熟悉可以看[next传送门](https://en.cppreference.com/w/cpp/iterator/next)


### 解法二代码

```cpp
class Solution {
public:
    vector<double> ans;
    multiset<int> _set;

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for(int i=0;i<k;i++){
            _set.insert(nums[i]);
        }
        auto mid = next(_set.begin(), k/2);
        int left = 0, right = k;
        while(true){
            double median = (double(*mid) + double(*next(mid, k%2-1))) * 0.5;
            ans.push_back(median);
            if(right >= nums.size())  break;
            _set.insert(nums[right]);
            if(nums[right++] < *mid)   mid --;
            if(nums[left++] <= *mid)  mid++;
            _set.erase(_set.lower_bound(nums[left-1]));
        }
        return ans;
    }
};

```
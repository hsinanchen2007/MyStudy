### 解题思路
// 方法1: 冒泡+二分
/*
 * 建立滑动窗口vec; 将前k个元素入vec，并排序;
 * 随着窗口滑动，窗口左侧元素滑出，窗口右侧元素滑入
 *      1. 对于左侧元素，其值为nums[cnt-k],我们通过二分查找找到其在有序窗口vec中的位置index， 复杂度为logK
 *      2. 替换vec[index]=nums[cnt],即将右侧元素放入原先左侧元素所在的位置
 *      3. 因为目前只有index下标处的一个元素可能无序，vec中其他元素都是有序的，因此我们可以通过冒泡的方式将vec[index]左移或右移至vec有序，复杂度为O(K)
 *      4. 因为vec是有序的，取中位数入ans，复杂度O(1)
 *
 *  综上，时间复杂度为O(N)*(O(logK)+O(K)) = O(N*K)
 *  空间复杂度为O(K)
 */

### 代码

```cpp
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        if (nums.empty() || nums.size() < k) return vector<double>();
        int N = nums.size();
        vector<double> ans;

        map<int, int> hash;  // hash[x].first表示被删除元素，hash[x].second表示该元素被删除过几次

        // 建立两个堆，heap_left.size()-heap_right.size() = 1 or 0
        priority_queue<int, vector<int>, less<int>> heap_left;  // 记录左侧一半元素，top为最大
        priority_queue<int, vector<int>, greater<int>> heap_right;  // 记录右侧一半元素，top为最小

        // 初始化堆
        int cnt = 0;
        while(cnt < k){
            heap_left.push(nums[cnt]);
            cnt++;
        }
        for(int i = 0; i < k/2; i++){
            heap_right.push(heap_left.top());
            heap_left.pop();
        }

        int balance = 0;  // 记录两个堆是否平衡，若插入左侧则balance++,反之balance--

        // 主程序
        while(cnt <= N){
            // 注: 每轮循环结束后(或说每轮循环开始之初)，balance==0 && heap_left.top() heap_right.top()均为有效元素
            ans.push_back((k%2==1)?heap_left.top():((double)heap_left.top()+(double)heap_right.top())*0.5);
            if(cnt == N) break;
            int out_num = nums[cnt-k];
            int in_num = nums[cnt];
            cnt++;

            // 1. 记录删除的out_num,修改balance
            hash[out_num]++;
            if(out_num <= heap_left.top()) balance--;
            else balance++;

            // 2. 加入in_num, 修改balance
            if(heap_left.empty() || in_num <= heap_left.top()){
                heap_left.push(in_num);
                balance++;
            }else{
                heap_right.push(in_num);
                balance--;
            }

            // 3. 调整balance
            /* 这里涉及到一个逻辑问题:
             *     如果in_num和out_num都在同一个heap,那么balance==0,不必调整，只需要调整heap.top()为有效元素即可
             *     如果in_num在左，out_num在右，那么必然balance==2,需要从heap_left调往heap_right 1个元素  
             *           --注意是1个不是2个，这1个元素的调动实际上会引起balance变化2
             *           --且由于heap_left本轮没有执行删除操作，heap_left.top()必然是有效元素，直接调度即可
             *     反之，从heap_right调往heap_left 1个元素
             */  
            if(balance > 0){
                heap_right.push(heap_left.top());
                heap_left.pop();
            }
            if(balance < 0){
                heap_left.push(heap_right.top());
                heap_right.pop();
            }
            balance = 0;
            
            // 4. 调整heap.top()为有效元素
            while(!heap_left.empty() && hash[heap_left.top()] > 0){
                hash[heap_left.top()]--;
                heap_left.pop();
            }
            while(!heap_right.empty() && hash[heap_right.top()] > 0){
                hash[heap_right.top()]--;
                heap_right.pop();
            }
        }
        return ans;
    }
};
```

### 解题思路
// 方法2: 涉及到动态数组 -- 使用堆
/*
 * 我们前面使用堆的时候大多数是在数组递增的情况下的，即没有考虑删除元素
 * 而本处需要从堆中删除元素，因此我们采用"延迟删除的方法"
 */

### 代码
```
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        if (nums.empty() || nums.size() < k) return vector<double>();
        int N = nums.size();
        vector<double> ans;

        map<int, int> hash;  // hash[x].first表示被删除元素，hash[x].second表示该元素被删除过几次

        // 建立两个堆，heap_left.size()-heap_right.size() = 1 or 0
        priority_queue<int, vector<int>, less<int>> heap_left;  // 记录左侧一半元素，top为最大
        priority_queue<int, vector<int>, greater<int>> heap_right;  // 记录右侧一半元素，top为最小

        // 初始化堆
        int cnt = 0;
        while(cnt < k){
            heap_left.push(nums[cnt]);
            cnt++;
        }
        for(int i = 0; i < k/2; i++){
            heap_right.push(heap_left.top());
            heap_left.pop();
        }

        int balance = 0;  // 记录两个堆是否平衡，若插入左侧则balance++,反之balance--

        // 主程序
        while(cnt <= N){
            // 注: 每轮循环结束后(或说每轮循环开始之初)，balance==0 && heap_left.top() heap_right.top()均为有效元素
            ans.push_back((k%2==1)?heap_left.top():((double)heap_left.top()+(double)heap_right.top())*0.5);
            if(cnt == N) break;
            int out_num = nums[cnt-k];
            int in_num = nums[cnt];
            cnt++;

            // 1. 记录删除的out_num,修改balance
            hash[out_num]++;
            if(out_num <= heap_left.top()) balance--;
            else balance++;

            // 2. 加入in_num, 修改balance
            if(heap_left.empty() || in_num <= heap_left.top()){
                heap_left.push(in_num);
                balance++;
            }else{
                heap_right.push(in_num);
                balance--;
            }

            // 3. 调整balance
            /* 这里涉及到一个逻辑问题:
             *     如果in_num和out_num都在同一个heap,那么balance==0,不必调整，只需要调整heap.top()为有效元素即可
             *     如果in_num在左，out_num在右，那么必然balance==2,需要从heap_left调往heap_right 1个元素  
             *           --注意是1个不是2个，这1个元素的调动实际上会引起balance变化2
             *           --且由于heap_left本轮没有执行删除操作，heap_left.top()必然是有效元素，直接调度即可
             *     反之，从heap_right调往heap_left 1个元素
             */  
            if(balance > 0){
                heap_right.push(heap_left.top());
                heap_left.pop();
            }
            if(balance < 0){
                heap_left.push(heap_right.top());
                heap_right.pop();
            }
            balance = 0;
            
            // 4. 调整heap.top()为有效元素
            while(!heap_left.empty() && hash[heap_left.top()] > 0){
                hash[heap_left.top()]--;
                heap_left.pop();
            }
            while(!heap_right.empty() && hash[heap_right.top()] > 0){
                hash[heap_right.top()]--;
                heap_right.pop();
            }
        }
        return ans;
    }
};
```
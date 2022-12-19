## 解法1：堆

对于这种求topk或者第k个数的问题，都可以借助堆（优先队列）来实现。使用堆或优先队列保存前k个数即可。

* 如果要求的是topk个最小的数，则使用大顶堆，当当前值小于大顶堆的最大值时，将堆顶元素弹出，插入当前元素；
* 如果要求的是topk个最大的数，则使用小顶堆，当当前值大于小顶堆的最小值时，将堆顶元素弹出，插入当前元素。

代码如下：

```c++
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k >= arr.size())
            return arr;
        if (k == 0)
            return vector<int>();
        priority_queue<int> k_min;
        for (int i = 0; i < arr.size(); i++){
            int num = arr[i];
            if (i < k){
                k_min.push(num);
            } else {
                if (num < k_min.top()){
                    k_min.pop();
                    k_min.push(num);
                }
            }
        }
        vector<int> result;
        while (!k_min.empty()){
            result.push_back(k_min.top());
            k_min.pop();
        }
        return result;
    }
};
```

时间复杂度：$O(nlogk)$；

空间复杂度：$O(k)$。

## 解法2：快速排序变体

注意：快排有一个很有用的特性，即左侧元素都是小于当前被选中值的，右侧元素都是大于等于当前被选中值的。利用该特性很容易处理这种Top k问题。

在原始的快速排序中，我们需要对整个序列进行排序，因而需要对当前被选中值的左右两侧都进行递归处理。但对于Top k问题，如果当前被选中值的下标大于k，只需要递归处理左侧部分元素，如果当前被选中值的下标小于k，只需要递归处理右侧部分元素即可。

代码如下：

```c++
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0)
            return vector<int>();
        if (k == arr.size())
            return arr;
        
        int start_index = 0;
        int end_index = arr.size() - 1;
        int selected_index = partition(arr, 0, arr.size() - 1); // 前k个最小元素的结束下标应该是k-1
        while (selected_index != k - 1){  // 直到被选中的元素位于k-1位置
            if (selected_index < k - 1){
                start_index = selected_index + 1;
                selected_index = partition(arr, start_index, end_index);
            } else {
                end_index = selected_index - 1;
                selected_index = partition(arr, start_index, end_index);
            }
        }
        return vector<int>(arr.begin(), arr.begin() + k);
    }

    int partition(vector<int>& arr, int start_index, int end_index){
        int selected_index = randomSelectedIndex(start_index, end_index);
        swap(arr[selected_index], arr[end_index]);
        // 将小的元素放到左侧，大的元素放到右侧
        int smaller_index = start_index - 1;
        for (int i = start_index; i < end_index; i++){
            if (arr[i] >= arr[end_index]){
                continue;
            } else {
                swap(arr[smaller_index + 1], arr[i]);
                smaller_index++;
            }
        }
        
        swap(arr[smaller_index + 1], arr[end_index]);
        return smaller_index + 1;
    }

    int randomSelectedIndex(int start_index, int end_index){
        return random() % (end_index - start_index + 1) + start_index;
    }
};
```

时间复杂度：$O(n)$，每次需要遍历的元素的个数为上一次的$\frac{1}{2}$，所有总共需要遍历的元素的个数为$N+N/2+N/4+...+1=2N$。

空间复杂度：常数级，主要内存消耗来自于递归时的函数栈。
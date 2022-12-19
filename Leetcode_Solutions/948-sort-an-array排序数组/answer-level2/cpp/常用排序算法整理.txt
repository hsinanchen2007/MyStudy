### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums);
        heap_sort(nums);
        return nums;
    }
private:
    void swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }

    //选择排序: 结果超时9/10
    void selection_sort(vector<int> &nums){
        for(int i = 0; i < nums.size() - 1; ++i){
            int t = i;
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[j] < nums[t])
                    t = j;
            }
            swap(nums[i], nums[t]);
        }
    }
    
    //直接插入 9/10
    void insert_sort(vector<int> &nums){
        for(int i = 1, j; i < nums.size(); ++i){
            int t = nums[i];
            for(j = i; j > 0; --j){
                if(t < nums[j - 1]){
                    nums[j] = nums[j - 1];
                }
                else
                    break;
            }        
            nums[j] = t;       
        }
    }
    
    //归并 40.39%
    void merge_sort(vector<int>& nums, vector<int> &temp, int s, int e){
        if(s >= e)
            return;
        int m = (s + e) >> 1;
        merge_sort(nums, temp, s, m);
        merge_sort(nums, temp, m + 1, e);

        //归并过程
        int l = m, r = e;
        int k = e;
        while((l >= s) && (r >= m + 1)){
            if(nums[l] > nums[r]){
                temp[k--] = nums[l--];
            }
            else
            {
                temp[k--] = nums[r--];
            }        
        }
        while(l >= s){
            temp[k--] = nums[l--];
        }
        while(r >= m + 1){
            temp[k--] = nums[r--];
        }
        for(int i = s; i <= e; ++i)
            nums[i] = temp[i];

    }
    //交换类排序：冒泡 稳定 9 / 10
    void swap_sort(vector<int> &nums){
        for(int i = 0; i < nums.size() - 1; ++i){
            for(int j = 0; j < nums.size() - i - 1; ++j){
                if(nums[j] > nums[j + 1])
                    swap(nums[j], nums[j + 1]);
            }
        }

    }
    
    //交换类排序：快速排序：不稳定O（nlogn）51.09%
    void fast_sort(vector<int> &nums, int s, int e){
        if(s >= e)
            return;
        int flag = nums[s];
        int l = s, r = e;
        while(l < r){
            while(l < r && nums[r] >= flag)
                --r;
            nums[l] = nums[r];
            while(l < r && nums[l] < flag)
                ++l;
            nums[r] = nums[l];
        }
        nums[l] = flag;

        fast_sort(nums, s, l - 1);
        fast_sort(nums, l + 1, e);
    }
    
    //选择类排序：堆排序（O（nlogn）,不稳定）32.63%
    void heap_sort(vector<int>& nums){
        //将初始序列调整成大根堆
        for(int i = nums.size() / 2 - 1; i >= 0; --i){
            adjust_heap(nums, i, nums.size());
        }

        //将最后一个未排序的节点和根节点交换，调整堆
        for(int i = nums.size() - 1; i >= 0; --i){
            swap(nums[0], nums[i]);
            adjust_heap(nums, 0, i);
        }
    }
    void adjust_heap(vector<int>& nums, int i, int len){
        //由于每次调整堆时，并不是需要调整整个堆，只调整那些未排好序的就可以,因此这里传入了参数len
        for(int k = 2 * i + 1; k < len; k = 2 * k + 1){
            if(k + 1 < len && nums[k] < nums[k + 1])
                ++k;
            if(nums[i] < nums[k]){
                swap(nums[i], nums[k]);
                i = k;//调整完当前的根后，需要继续调整与其交换的孩子节点
            }
            else
            {
                break;
            }

        }
    }

};
```
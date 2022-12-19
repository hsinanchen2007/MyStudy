[toc]
### 排序算法

#### 1. 冒泡排序
```cpp
// 1. 冒泡排序
void bubble_sort(vector<int>& nums){
    int size = nums.size();
    for(int i = 0; i<size; ++i){
        bool is_swap = false;
        for(int j = 0; j< size - 1 - i; ++j){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
                is_swap = true;
            }
        }
        if(!is_swap) break;
    }
}
```

#### 2. 选择排序
```cpp
// 2. 选择排序
void select_sort(vector<int>& nums){
    int size = nums.size();
    for(int i = 0; i<size - 1; ++i){
        int min_index = i;
        for(int j = i + 1; j<size; ++j){
            if(nums[min_index] >= nums[j]){
                min_index = j;
            }
        }
        swap(nums[min_index], nums[i]);
    }
}
```

#### 3. 快速排序
```cpp
// 3. 快速排序
void quick_sort(vector<int>&nums){
    quick_sort(nums, 0, nums.size() - 1);
}

void quick_sort(vector<int>& nums, int start, int end){
    int left = start, right = end;
    if(left < right){
        int pivot = nums[left];
        while(left < right){
            // 快速排序为什么从右边开始, 需要理解一下昂
            while(left<right && nums[right]>pivot){ --right; }
            while(left<right && nums[left]<=pivot){ ++left; }
            if(left<right) swap(nums[left], nums[right]);
        }
        swap(nums[left], nums[start]);
        quick_sort(nums, start, left - 1);
        quick_sort(nums, left + 1, end);
    }
}
```

#### 4. 计数排序
```cpp
// 4. 计数排序
void count_sort(vector<int>& nums){
    int size = nums.size();
    int min_val = nums[0], max_val = nums[0];
    for(int item : nums){
        min_val = min(min_val, item);
        max_val = max(max_val, item);
    }
    vector<int> counter(max_val - min_val + 1);
    for(int item : nums){
        counter[item - min_val] += 1;
    }
    for(int i = 0, cur = 0; i<counter.size(); ++i){
        while(counter[i]--){
            nums[cur++] = i + min_val;
        }
    }
}
```

#### 5. 插入排序
```cpp
// 5. 插入排序
void insert_sort(vector<int>& nums){
    int size = nums.size();
    for(int i = 1; i<size; ++i){
        int j = i - 1, tmp = nums[i];
        while(j>=0 && tmp < nums[j]){
            nums[j+1] = nums[j]; --j;
        }
        nums[j + 1] = tmp;
    }
}
```

#### 6. 堆排序
```cpp
// 6. 堆排序
    void heap_sort(vector<int>& nums){
        int size = nums.size();
        for(int i = (size - 2)/2; i>=0; --i){
            adjust(nums, i, size);
        }
        // 将堆顶元素和最后一个元素交换, 数组大小减一, 重新调整堆
        for(int i = size - 1; i>=1; --i){
            swap(nums[0], nums[i]);
            adjust(nums, 0, i);
        }
    }

    void adjust(vector<int>& nums, int index, int size){
        int parent = nums[index];
        int child_index = 2*index + 1;
        while(child_index < size){
            if(child_index + 1 < size && nums[child_index + 1] > nums[child_index]) child_index+=1;
            if(nums[index] > nums[child_index]) break;
            nums[index] = nums[child_index];
            index = child_index;;
            child_index = 2*child_index + 1;
        }
        nums[index] = parent;
    }
```

#### 7. 归并排序
```cpp
    // 7. 归并排序
    void merge_sort(vector<int>& nums){
        vector<int> dest(nums.size());
        merge_sort(nums, dest, 0, nums.size() - 1);
    }

    void merge_sort(vector<int>& nums, vector<int>& dest, int left, int right){
        if(left >= right) return;
        int mid = (left + right) / 2;
        merge_sort(nums, dest, left, mid);
        merge_sort(nums, dest, mid + 1, right);
        merge(nums, dest, left, mid, right);
    }

    void merge(vector<int>& nums, vector<int>& dest, int left, int mid, int right){
        int l = left, r = mid + 1, cur = 0;
        while(l<=mid || r<=right){
            if(l>mid){
                dest[cur++] = nums[r++];
            }else if(r>right){
                dest[cur++] = nums[l++];
            }else if(nums[l] <= nums[r]){
                dest[cur++] = nums[l++];
            }else{
                dest[cur++] = nums[r++];
            }
        }
        std::copy(dest.begin(), dest.begin() + cur, nums.begin() + left);
    }
```

#### 8. 上述排序算法的使用
```cpp
class Solution {
private:
    /*
        ...
    */
public:
    vector<int> sortArray(vector<int>& nums) {
        // bubble_sort(nums);
        // select_sort(nums);
        // quick_sort(nums);
        // count_sort(nums);
        // insert_sort(nums);
        // heap_sort(nums);
        // merge_sort(nums);
        return nums;
    }
};
```
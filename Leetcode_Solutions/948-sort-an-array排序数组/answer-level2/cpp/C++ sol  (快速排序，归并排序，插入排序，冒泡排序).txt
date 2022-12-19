### 解题思路

1. 需要提醒的是，对于”插入排序“来说，链表的版本需要多练习一下（需要注意！）
2. 链表版本的插入排序需要多加练习，因为 1）加深对链表操作的理解 2）熟悉如何在链表中进行节点交换 3）熟悉插入排序
3. 可以参考 [https://leetcode-cn.com/problems/insertion-sort-list/solution/c-sol-by-silverblg-51/](https://leetcode-cn.com/problems/insertion-sort-list/solution/c-sol-by-silverblg-51/)

### 代码

```cpp
// 快速排序 O(nlgn), 空间复杂度 O(lgn) <- 每次操作的空间复杂度是O(1)，因此单纯取决于栈深度
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sortArray(nums, 0, nums.size()-1);
        return nums;
    }

    void sortArray(vector<int>& nums, int l , int r) {
        if (l>=r) return;

        int p = partition(nums, l, r);
        sortArray(nums, l, p-1);
        sortArray(nums, p+1, r);
    }

    int partition(vector<int>& nums, int l, int r) {
        srand(time(0));
        swap(nums[(rand()%(r-l+1))+l], nums[r]); // put partition at last
        
        int i = l, j = l;
        for (; j < r; j++) {
            if (nums[j] <= nums[r]) {
                swap(nums[i++], nums[j]);
            }
        }

        swap(nums[i], nums[r]);
        return i;
    }
};

/* 归并排序 （基于文件流的, fstream based merge sort） O(nlgn)
string createTempFileName(int l, int r) {
    return "temp" + to_string(l) + "-" + to_string(r) + ".dat";
}

template <class T>
void setData(ostream& os, int index, T data) {
    os.seekp(index * sizeof(T), ios_base::beg); // seek put
    os.write(reinterpret_cast<char*>(&data), sizeof(T));
}

template <class T>
T getData(istream& is, int index) {
    is.seekg(index * sizeof(T), ios_base::beg); // seek get

    T data;
    is.read(reinterpret_cast<char*>(&data), sizeof(T));

    return data;
}

class Solution {
public:
    void sortArray(fstream& nums, int size) {
        sortArray(nums, 0, size - 1);
    }

    void sortArray(fstream& nums, int l, int r) {
        if (l >= r) return;
        int mid = l + (r-l) / 2;
        sortArray(nums, l, mid);
        sortArray(nums, mid + 1, r);

        // merge array
        int i = l, m = mid;
        int j = mid + 1, n = r;

        string tempFileName = createTempFileName(l, r);
        fstream tmp(tempFileName.c_str(), ios_base::binary | ios_base::out | ios_base::in | ios_base::trunc);
        
        int k = 0;
        while (i <= m && j <= n) {
            setData(tmp, k++, getData<int>(nums, i) < getData<int>(nums, j) ? getData<int>(nums, i++) : getData<int>(nums, j++) );
        }

        while (i <= m) setData<int>(tmp, k++, getData<int>(nums, i++));
        while (j <= n) setData<int>(tmp, k++, getData<int>(nums, j++));

        // update nums array
        for (i = 0; i < k; i++) setData<int>(nums, l+i, getData<int>(tmp, i));
    }
};
*/

/* 归并排序（merge sort）  O(nlgn)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sortArray(nums, 0, nums.size()-1);
        return nums;
    }

    void sortArray(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = l+ (r-l)/2;
        sortArray(nums, l, mid);
        sortArray(nums, mid+1, r);
        
        // merge array
        int i = l, m = mid;
        int j = mid+1, n = r;

        vector<int> tmp(r-l+1); int k = 0;
        while (i<=m && j<=n) tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        while (i<=m) tmp[k++] = nums[i++];
        while (j<=n) tmp[k++] = nums[j++];

        // update nums array
        for (i = 0; i < k; i++) nums[l+i] = tmp[i];
    }
};
*/

/* 插入排序 (timeout, O(n^2))
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 1, j = 0; i < nums.size(); i++) {
            int current = nums[i];
            for (j = i-1; j >= 0 && nums[j] > current; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = current;
        }

        return nums;
    }
};
*/

/* 冒泡排序 (timeout, O(n^2))
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) { 
        bool hasChanged = true;
        for (int i = 0; i < nums.size()-1 && hasChanged; i++) {
            hasChanged = false;
            for (int j = 0; j < nums.size()-1-i; j++) {
                if (nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                    hasChanged = true;
                }
            }
        }

        return nums;
    }
};
*/
```
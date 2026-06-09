### 解题思路
此处只讨论快排和最大堆排序。其中快排需要注意的问题是各种判断条件（包括循环）确保不要超出数组边界和书写正确，以及为了减少递归层数，可以用if语句
先行判断，再进行递归，例如if(star>=small-1){QuickSort()}
最大堆排序是利用最大堆的性质，首先应该还原出最大堆，然后每次弹出根节点放置在队列最后，对剩下的堆进行重排，重复上述过程，就自然实现了升序排序。
当然最大堆或者二叉树其实都可以拿数组来直接表示，思路是每次先从最后的节点开始查看，看子节点和父节点谁大，然后把大的挪到父节点上来，当出现了移动，
由于子节点的值被更新，如果子节点有子节点的话也需要继续判断新来的节点是不是要比子节点大，如果小的话还要被挪下去，所以才有maxHeapify的for循环。
buildMaxHeap的for循环是用来重复上述步骤的，注意初始的Len给的是size()-1

### 代码

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.empty())
            return {};
        int vec_size = nums.size();
        QuickSort(nums,0,vec_size-1);
        return nums;
    }

private:
    int getRandom(int a , int b){
        srand(time(0));
        return rand()%(b-a+1)+a;
    }

    void swap(int& a,int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void QuickSort(vector<int>& nums,int star,int end){
        if(star >= end)
            return;
        int random_num = getRandom(star,end);
        swap(nums[random_num],nums[end]);
        int small=star-1;
        for(int i = star;i<end;i++){
            if(nums[i]<=nums[end]){
                small++;
                if(small != i)
                    swap(nums[i],nums[small]);
            }
        }
        small++;
        swap(nums[small],nums[end]);

        QuickSort(nums,star,small-1);
        QuickSort(nums,small+1,end);
    }
};
```
```cpp
class Solution {
    void maxHeapify(vector<int>& nums, int i, int len) {
        for (; (i << 1) + 1 <= len;) {
            int lson = (i << 1) + 1;
            int rson = (i << 1) + 2;
            int large;
            if (lson <= len && nums[lson] > nums[i]) {
                large = lson;
            }
            else {
                large = i;
            }
            if (rson <= len && nums[rson] > nums[large]) {
                large = rson;
            }
            if (large != i) {
                swap(nums[i], nums[large]);
                i = large;
            }
            else break;
        }
    }
    void buildMaxHeap(vector<int>& nums, int len) {
        for (int i = len / 2; i >= 0; --i) {
            maxHeapify(nums, i, len);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int len = (int)nums.size() - 1;
        buildMaxHeap(nums, len);
        for (int i = len; i >= 1; --i) {
            swap(nums[i], nums[0]);
            len -= 1;
            maxHeapify(nums, 0, len);
        }
        return nums;
    }
};
```
### 解题思路
借鉴快速排序的思想，快排是通过分治法思想，将大于某数的数组值移到右面，小于移到左面，所以快排思想可用于找无顺序的k个最小或最大数。
快排主要是定义small，然后当出现small和遍历序数j不一样且遍历到小于该随机数的数时交换。
注意srand()和rand的使用
当然还有最大根堆方法，也就是prior_queue，先建立一个k个根的优先队列，然后将剩余的数与根节点比较，当小于根节点，把该点push到根节点，再Pop()即可

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k == 0){
            return {};
        }
        k_=k;
        random_partition(arr,0,arr.size()-1);
        vector<int> ans;
        for(int j = 0;j<k;j++){
            ans.push_back(arr[j]);
        }
        return ans;
    }
private:

    int random_num(int l,int r){
        srand((unsigned int)time(0));
        return (rand()%(r-l+1)+l);
    }

    void random_partition(vector<int>& arr, int l,int r){
        if (l>r)
            return;
        int i = random_num(l,r);
        int small = l;
        swap(arr[i],arr[r]);
        for(int j = l;j<r;j++){
            if(arr[j]<arr[r]){
                if(small != j)
                    swap(arr[j],arr[small]);
                small++;
            }
        }
        swap(arr[small],arr[r]);
        if(small == k_)
            return;
        else if (small<k_)
            random_partition(arr,small+1,r);
        else if(small>k_)
            random_partition(arr,l,small-1);
    }

    int k_;
};
```
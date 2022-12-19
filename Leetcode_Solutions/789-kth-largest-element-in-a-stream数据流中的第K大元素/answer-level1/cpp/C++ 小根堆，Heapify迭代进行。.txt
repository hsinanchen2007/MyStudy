### 解题思路
#### 遍历数组，把元素存进大小为k的小根堆，可保证队头元素是第k大元素；如arr = [9,10,3,5,8], k = 3(4) MinHeap中包含前k大的元素：8,9,10(8,9,10,5),并且队头为第k大元素。一般Heapify使用递归或迭代，递归写法简单且容易理解，但效率比迭代低。

### 代码

```cpp
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        height = k;
        for(int i=0;i<nums.size();i++)
            add(nums[i]);
    }
    
    int add(int val) {
        if(pQue.size()< height){
            pQue.push_back(val);
            if(pQue.size() == height){
                // 初始化最小堆
                initMinHeap(pQue);
            }
        }else{
            // 进来一个比队头 大的
            if(val > pQue[0]){
                pQue[0] = val;
                // 调整最小堆
                Heapify(pQue,0);
            }
        }
        return pQue[0];
    }

    void Heapify(vector<int>& nums,int position){
        int lchild = 2*position + 1; // 左孩子
        int rchild = lchild + 1; //右孩子
        int min = position;
        int parent = position;
        // 循环迭代进行
        while(lchild < height){
            // 右节点存在 且比 左节点小
            if(rchild < height && (nums[rchild] < nums[lchild])){
                min = rchild;
            }else{
                min = lchild;
            }
            // 比较 子节点和父节点 谁小
            min = nums[min] < nums[parent] ? min : parent;
            // 没改变即已完成
            if(min == parent) break;
            else{
                // 交换位置
                int tmp = nums[parent];
                nums[parent] = nums[min];
                nums[min] = tmp;

                // 下潜
                parent = min;
                lchild = 2*parent + 1;
                rchild = lchild + 1;
            }
        }

        return;

    }

    void initMinHeap(vector<int>& nums){
        // 从最后一个非叶子节点开始
        for(int i=(height/2)-1; i>=0; i--){
            Heapify(pQue,i);
        }
    }
private:
    vector<int> pQue;
    int height;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```
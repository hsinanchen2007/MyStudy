注意：利用小顶堆，size=k 也就是堆顶就是要找的k最大元素 (C++实现)

 第一种：直接利用priority_queue小顶堆实现
```
    KthLargest1(int k, vector<int>& nums) {
        this->size = k;
        pq = new priority_queue<int, vector<int>, greater<int>>(size, INT_MIN);
        for(int &a:nums) {
            add(a);
        }        
    }

    int add1(int val) {
        if (val <= pq->top()) {
            return pq->top();
        }

        pq->pop();
        pq->push(val);

        return pq->top();
    }
```



第二种：利用二叉堆实现 （注意是小顶堆，判断细节不要搞错）
```
     KthLargest(int k, vector<int>& nums) {
         size = k;
         vet = new vector<int>(size,INT_MIN);

        int numsSize = nums.size();
         for(int i=0; i<numsSize; i++) {
             add(nums[i]);
         }
     }

    int add(int val) {
        if (val <= (*vet)[0]) return (*vet)[0];

        (*vet)[0] = (*vet)[size-1];
        (*vet).erase((*vet).begin() + size-1);
         siftDown((*vet),0);

        (*vet).emplace_back(val);
        siftUp((*vet),size-1); // 向后加

        return (*vet)[0];
    }

    void siftUp(vector<int>& nums, int index) {
         int element = nums[index];
         while(index > 0) {
             int parentIndex = (index-1) >> 1;  // 父节点index
             int parent = nums[parentIndex];
             if(element >= parent) break;

             // 这是element < 父节点要上虑（因为是小顶堆）
            nums[index] = parent;
            nums[parentIndex] = element;
            index = parentIndex;
         }
         nums[index] = element;
    }

   void siftDown(vector<int>& nums, int index) {
        int element = nums[index];
        int size = nums.size();
        int half = size >> 1;
        while (index < half) {  // index 必须是非叶子
            int leftChildIndex = (index<<1)+1;
            int rightChildIndex = leftChildIndex +1;

            //  左子节点  > 右子节点  (这里要拿到最小子节点交换)
            if (rightChildIndex < size && nums[leftChildIndex] > nums[rightChildIndex]) {
                leftChildIndex = rightChildIndex;
            }

            // 如果左右子节点不大于它就停
            if (element <= nums[leftChildIndex]) break;

            // 交换子父节点
            nums[index] =  nums[leftChildIndex];
            nums[leftChildIndex] = element;
            index = leftChildIndex;
        }
        nums[index] =  element;
    }
```

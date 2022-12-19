主要思路：从数组中选出k个最大的数，建立一个含有k个元素的堆，堆顶保存其中的最小值
```
int findKthLargest(int* nums, int numsSize, int k){
    int heap[k];
    int ipos, ppos, lpos, rpos, mpos, temp;
    
    for (int i = 0; i < k; i++) { // 建立一个堆，堆顶保留最小值
        heap[i] = nums[i];

        ipos = i; // 当前元素在堆中的位置
        ppos = (ipos - 1) / 2; // heap[ipos]的parent的位置
        while (ipos > 0 && heap[ipos] < heap[ppos]) {
            temp = heap[ipos];
            heap[ipos] = heap[ppos];
            heap[ppos] = temp;

            ipos = ppos;
            ppos = (ipos - 1) / 2;
        }
    }

    for (int i = k; i < numsSize; i++) {
        if (nums[i] > heap[0]) { // 将堆顶与剩余元素挨个儿比较，堆顶元素小于nums[i]时就替换堆顶，并重新排列堆的结构
            heap[0] = nums[i];

            ipos = 0;
            while (1) {
                lpos = 2 * ipos + 1; // heap[ipos]的left child的位置
                rpos = 2 * ipos + 2; // heap[ipos]的right child的位置

                if (lpos < k && heap[lpos] < heap[ipos]) {
                    mpos = lpos;
                }
                else {
                    mpos = ipos;
                }

                if (rpos < k && heap[rpos] < heap[mpos]) {
                    mpos = rpos;
                }

                if (ipos == mpos) {
                    break;
                }
                else {
                    temp = heap[ipos];
                    heap[ipos] = heap[mpos];
                    heap[mpos] = temp;

                    ipos = mpos;
                }
            }
        }
    }

    return heap[0];
}
```

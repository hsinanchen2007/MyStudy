```
int lastStoneWeight(int* stones, int stonesSize){
    int heap[stonesSize];
    int ipos, ppos, lpos, rpos, mpos, temp, x, y, z, heapSize;

    // 将stones最大堆化，存储在heap中
    for (int i = 0; i < stonesSize; i++) {
        heap[i] = stones[i];
        ipos = i; // 新插入heap中元素的位置
        ppos = (ipos - 1) / 2; // heap[ipos]的父元素的位置

        while (ipos > 0 && heap[ipos] > heap[ppos]) { // 最大堆化（堆顶元素为全部元素最大值）
            temp = heap[ipos];
            heap[ipos] = heap[ppos];
            heap[ppos] = temp;

            ipos = ppos;
            ppos = (ipos - 1) / 2;
        }
    }

    heapSize = stonesSize; // 堆中元素的个数

    while (heapSize > 1) { 

        y = heap[0]; // 提取heap中最大元素
        heap[0] = heap[heapSize - 1]; // 将堆底的元素复制到堆顶
        heap[heapSize - 1] = 0; // 将堆底的元素置0
        heapSize--; // 堆的大小减1

        ipos = 0;
        
        while (1) { // 最大堆化
            lpos = 2 * ipos + 1; // heap[ipos]的left child的位置
            rpos = 2 * ipos + 2; // heap[ipos]的right child的位置

            if (lpos < heapSize && heap[ipos] < heap[lpos]) {
                mpos = lpos;
            }
            else {
                mpos = ipos;
            }

            if (rpos < heapSize && heap[mpos] < heap[rpos]) {
                mpos = rpos;
            }

            if (mpos == ipos) {
                break;
            }
            else {
                temp = heap[ipos];
                heap[ipos] = heap[mpos];
                heap[mpos] = temp;

                ipos = mpos;
            }
        }

        x = heap[0];
        heap[0] = heap[heapSize - 1];
        heap[heapSize - 1] = 0;
        heapSize--;

        ipos = 0;
        
        while (1) {
            lpos = 2 * ipos + 1;
            rpos = 2 * ipos + 2;

            if (lpos < heapSize && heap[ipos] < heap[lpos]) {
                mpos = lpos;
            }
            else {
                mpos = ipos;
            }

            if (rpos < heapSize && heap[mpos] < heap[rpos]) {
                mpos = rpos;
            }

            if (mpos == ipos) {
                break;
            }
            else {
                temp = heap[ipos];
                heap[ipos] = heap[mpos];
                heap[mpos] = temp;

                ipos = mpos;
            }
        }

        if ((z = y - x) > 0) { // 如果z = y-x不为0
            heap[heapSize] = z; // 将z插入堆底
            ipos = heapSize;
            ppos = (ipos - 1) / 2;

            while (ipos > 0 && heap[ipos] > heap[ppos]) { // 最大堆化
                temp = heap[ipos];
                heap[ipos] = heap[ppos];
                heap[ppos] = temp;

                ipos = ppos;
                ppos = (ipos - 1) / 2;
            }
            heapSize++; // 堆的大小加1
        }
    }
    return heap[0];
}
```

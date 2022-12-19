给定元素后，求得第k大个元素。只要创建一个k大小的小顶堆，每次添加数据不停的进行堆化，保持小顶堆的特性。那么堆顶的数据即为第k大元素。

前面几次提交错误原因：
1. 堆结构体定义比较简单，使用了需设置固定大小的int数组，所以多次数组大小不够。
2. 堆内有k个元素时，再次添加数据与堆顶元素比较大小后，若满足条件应替换堆顶元素，进行从上往下的堆化处理。
3. 堆内有小于k个元素时，添加数据应在数组已有值的最大下标+1处填充值，并从下往上的进行堆化处理。
4. 第2和3需分开考虑处理。

代码：

    typedef struct {
        int s[20000];
        int k;
        int index;
    } KthLargest;

    void minHeap(KthLargest* obj, int num) {
        //已存在k个数，且小顶堆的堆顶元素 大于等于 新元素，则不进行处理

        int flag;
        if (obj->k == obj->index + 1 && obj->s[0] >= num) {
            return;
        } else if (obj->k == obj->index + 1 && obj->s[0] < num) {
            flag = 1;
            obj->s[0] = num;
        } else {
            flag = 2;
            obj->s[++obj->index] = num;
        }

        //第一个数不需要进行最小堆堆化处理
        if (obj->index == 0) {
            return;
        }

        //heapify
        int i,temp;
        if (flag == 2) {
            i = obj->index;
            while ((i - 1) / 2 >= 0) {
                temp = (i - 1) / 2;
                if (obj->s[temp] > obj->s[i]) {
                    int data = obj->s[temp];
                    obj->s[temp] = obj->s[i];
                    obj->s[i] = data;

                    i = (i - 1) / 2;
                } else {
                    break;
                }
            }
        } else {
            i = 0;
            while (1) {
                int left = i * 2 + 1;
                int right = i * 2 + 2;
                temp = i;
                if (left <= obj->index && obj->s[temp] > obj->s[left]) {
                    temp = left;
                }
                if (right <= obj->index && obj->s[temp] > obj->s[right]) {
                    temp = right;
                }
                if (temp == i) {
                    break;
                }
                int data = obj->s[temp];
                obj->s[temp] = obj->s[i];
                obj->s[i] = data;

                i = temp;
            }
        }
    }

    KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
        KthLargest *kL = (KthLargest *)malloc(sizeof(KthLargest));
        kL->k = k;
        kL->index = -1;

        int i;
        for (i=0; i<numsSize; i++) {
            minHeap(kL, nums[i]);
        }
        return kL;
    }

    int kthLargestAdd(KthLargest* obj, int val) {
        minHeap(obj, val);
        return obj->s[0];
    }

    void kthLargestFree(KthLargest* obj) {
        obj->index = -1;
    }

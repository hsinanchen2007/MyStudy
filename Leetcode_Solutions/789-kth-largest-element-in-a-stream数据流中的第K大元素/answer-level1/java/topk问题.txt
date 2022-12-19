### 解题思路
topK问题一般是维护一个含有k个元素的小顶堆，堆顶元素就是要求的解

### 代码

```java
class KthLargest {

    int k = 0;
    int [] otherHeap = null;
    public KthLargest(int k, int[] nums) {
        this.k = k;
        buildHeap(k,nums);
    }

    private void buildHeap( int k, int[] nums ) {
        int size = nums.length;
        if(size<k){
            otherHeap = new int[size+1];
            for(int i=0;i<size;i++){
                otherHeap[i+1] = nums[i] ;
            }
            //构建小顶堆
            buildSmallHeap(otherHeap);
        }else{
            otherHeap = new int[k+1];
            for(int i=0;i<k;i++){
                otherHeap[i+1] = nums[i];
            }
            //构建k个元素的小顶堆
            buildSmallHeap(otherHeap);
            for(int i=k;i<size;i++){
                if(nums[i]>otherHeap[1]){
                    otherHeap[1] = nums[i];
                    heapifyOfSmall( otherHeap );
                }

            }
        }

    }


    ///自上而下构建堆
    private void buildSmallHeap( int[] otherHeap ) {
        int size = otherHeap.length;
        for(int i=size/2;i>0;i--){
            int index = i;
            while(true){
                int minPos = index;
                if(2*index<size && otherHeap[2*index]<otherHeap[index]){
                    minPos = 2*index;
                }
                if(2*index+1<size && otherHeap[2*index+1]<otherHeap[minPos]){
                    minPos = 2*index+1;
                }
                if(minPos==index){
                    break;
                }
                swap( otherHeap,minPos,index );
                index = minPos;

            }
        }
    }

    private void swap( int[] array, int maxPos, int index ) {
        int tmp = array[maxPos];
        array[maxPos] = array[index];
        array[index] = tmp;
    }

    public int add(int val) {
        int j = otherHeap.length;
        //如果小顶堆实际元素小于k个，则插入小顶堆
        if(j<k+1){
            int[] tmp = new int[j+1];
            for(int i=0;i<j;i++){
                tmp[i] = otherHeap[i];
            }
            tmp[tmp.length-1] = val;
            //插入新叶子节点进行堆化
            heapifyOfSmall2(tmp);
            otherHeap = tmp;

        }else if(val>otherHeap[1] ){
            //如果元素大于小顶堆堆顶元素,则替换堆顶元素并堆化
           otherHeap[1] = val;
            //插入新叶子节点进行堆化
            heapifyOfSmall(otherHeap);

        }
        return otherHeap[1];
    }

    //小顶堆更新了堆顶元素，所以进行自上而下的堆化
    private void heapifyOfSmall( int[] otherHeap) {
        int index = 1;
        int size = otherHeap.length;
        while(true){
            int minPos = index;
            if(2*index<size && otherHeap[2*index]<otherHeap[index]){
                minPos = 2*index;
            }
            if(2*index+1<size && otherHeap[2*index+1]<otherHeap[minPos]){
                minPos = 2*index+1;
            }
            if(index/2>0 && otherHeap[index/2]>otherHeap[index]){
                minPos = index/2;
            }
            if(minPos == index){
                break;
            }
            swap( otherHeap,minPos,index );
            index = minPos;
        }
    }

    //小顶堆插入了新的叶子节点，所以进行自下而上的堆化
    private void heapifyOfSmall2( int[] otherHeap) {
        int index = otherHeap.length-1;
        while(true){
            int minPos = index;
            if(index/2>0 && otherHeap[index/2]>otherHeap[index]){
                minPos = index/2;
            }
            if(minPos == index){
                break;
            }
            swap( otherHeap,minPos,index );
            index = minPos;
        }
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```
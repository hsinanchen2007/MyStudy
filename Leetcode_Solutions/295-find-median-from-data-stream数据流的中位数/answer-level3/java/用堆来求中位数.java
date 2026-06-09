### 解题思路
维护两个堆，一个最大堆，一个最小堆.
假设第一个元素先往小堆中放，那么如果总元素为奇数，那么中位数就是小堆堆顶那个元素，如果总元素为偶数，那么中位数就是小堆堆顶和大堆堆顶元素之和除以2.
addNum方法时间复杂度为O(log n),findMedian方法时间复杂度为O(1).

### 代码

```java
class MedianFinder {

    int size = 0;
    PriorityQueue<Integer> bigHeap = new PriorityQueue( Comparator.reverseOrder() );
    PriorityQueue<Integer> smallHeap = new PriorityQueue(  );
    public MedianFinder() {

    }

    public void addNum(int num) {
        size += 1;
        //第一个元素往小堆放
        if(size==1){
            smallHeap.offer( num );
        }else{
            //总数为偶数时，往大堆加元素
            if(size%2==0){
                //先拿num与小堆中最小的元素peek比较，如果比peek大，则num入小堆，peek入大堆
                //否则num直接入大堆
                Integer peek = smallHeap.peek();
                if(num>peek){
                    peek = smallHeap.poll();
                    smallHeap.offer( num );
                    bigHeap.offer( peek );
                }else{
                    bigHeap.offer( num );
                }
            }else{
             //如果总数为奇数时，要往小堆加元素
             //拿num与大堆中最大的元素peek比较，如果比peek大，则直接入小堆，
             //如果peek比较大，则peek入小堆
                Integer peek = bigHeap.peek();
                if(num>peek){
                    smallHeap.offer( num );
                }else{
                    peek = bigHeap.poll();
                    bigHeap.offer( num );
                    smallHeap.offer( peek );
                }

            }

        }

    }

    public double findMedian() {
        if(size==0){
            return 0.0;
        }
        if(size%2!=0){
            Integer peek = smallHeap.peek();
            return peek.doubleValue();
        }else{
            Integer big = bigHeap.peek();
            Integer small = smallHeap.peek();
            return (big.doubleValue()+small.doubleValue())/2;
            
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```
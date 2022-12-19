### 解题思路
看完不懂来打我
https://zhuanlan.zhihu.com/p/102182602

### 代码

```java
class MedianFinder {

    PriorityQueue<Integer> min=null;
    PriorityQueue<Integer> max=null;
    /** initialize your data structure here. */
    public MedianFinder() {
        min=new PriorityQueue<>();
        max=new PriorityQueue<>(new Comparator<Integer>(){
            @Override
            public int compare(Integer o1,Integer o2){
                return o2-o1;
            }
        });
    }
    
    public void addNum(int num) {
        if(max.size()==0||max.peek()>num){
            max.add(num);
        }else{
            min.add(num);
        }
        if(max.size()-min.size()>1){
            min.add(max.poll());
        }
        if(min.size()-max.size()>1){
            max.add(min.poll());
        }
    }
    
    public double findMedian() {
        int count=max.size()+min.size();
        if((count&1)==0){
            return (max.peek()+min.peek())/2.0;
        }else{
            if(max.size()>min.size()){
                return max.peek()/1.0;
            }else{
                return min.peek()/1.0;
            }
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
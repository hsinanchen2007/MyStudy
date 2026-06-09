### 解题思路
此处撰写解题思路

### 代码

```java
class MedianFinder {
    ArrayList<Integer> list = new ArrayList<>();
    /** initialize your data structure here. */
    public MedianFinder() {
        
    }
    
    public void addNum(int num) {
        list.add(num);
        list.sort(((o1, o2) -> {
            if (o1 > o2) return 1;
            if(o1 < o2) return -1;
            return 0;
        }));
    }
    
    public double findMedian() {
        int len = list.size();
        double res = 0;
        if(list.size() % 2 == 0){
            //偶数
            res = ((double)(list.get(len/2) + list.get(len/2 - 1)))/2;
        }else {
            //奇数
            res = list.get(len/2);
        }
        return res;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```
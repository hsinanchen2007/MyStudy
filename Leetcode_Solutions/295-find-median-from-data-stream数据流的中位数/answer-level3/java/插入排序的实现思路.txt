### 解题思路
二分法获取要插入的索引位置，然后插入元素，所以addnum的时间复杂度为O(n)+O(logn);

### 代码

```java
class MedianFinder {
    List<Integer> list;
    /** initialize your data structure here. */
    public MedianFinder() {
        list = new ArrayList<>();
    }
    
    public void addNum(int num) {
        if(list.size()==0) list.add(num);
        else {
            int j = floor(list,0,list.size()-1,num);
            list.add(j+1,num);
        }
    }
    //二分法获取要插入的索引位置
    public static int floor(List<Integer> nums, int low, int high, int num) {
        if (low > high) return -1;
        int mid = low + (high - low) / 2;
        if (nums.get(mid) == num) return mid;
        else if (nums.get(mid) > num) return floor(nums, low, mid - 1, num);
        int temp = floor(nums, mid + 1, high, num);
        return temp == -1?mid:temp;
    }

    
    public double findMedian() {
        if(list.size()%2==0) return (list.get(list.size()/2)+list.get(list.size()/2-1))*0.5;
        else return list.get(list.size()/2);

    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```
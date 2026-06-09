使用插入排序的方法，每次添加的复杂度为O(N),查找中位数的复杂度为O(1)
### 代码

```cpp
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> Stream;
    MedianFinder() {

    }
    
    void addNum(int num) {
        Stream.push_back(num);
        for(int i=Stream.size()-1;i>=1;i--){
            if(Stream[i]<Stream[i-1]){
                swap(Stream[i],Stream[i-1]);
            }
            else{
                break;
            }
        }
    }
    
    double findMedian() {
        double res;
        if(Stream.size()%2==0){
            res = Stream[Stream.size()/2] + Stream[Stream.size()/2 - 1];            
            res = res/2;

        }
        else
            res = Stream[(Stream.size()-1)/2];
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```
二分插入
```
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    vector<int>a;
    void addNum(int num) {
        if(a.size()==0||num>=a[a.size()-1]){
            a.push_back(num);
            return;
        }
        if(num<=a[0]){
            a.insert(a.begin(),1,num);
            return;
        }
        int l=0,r=a.size()-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(a[mid]==num||mid-1>=0&&a[mid-1]<=num&&a[mid]>=num){
                a.insert(a.begin()+mid,1,num);
                return;
            }
            if(mid+1<a.size()&&a[mid+1]>=num&&a[mid]<=num){
                a.insert(a.begin()+mid+1,1,num);
                return;
            }
            if(a[mid]>num)r=mid;
            else{
                l=mid;
            }
            
        }
    }
    
    double findMedian() {
        if(a.size()%2==1)return a[a.size()/2];
        else{
            return (a[a.size()/2-1]+a[a.size()/2])/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```


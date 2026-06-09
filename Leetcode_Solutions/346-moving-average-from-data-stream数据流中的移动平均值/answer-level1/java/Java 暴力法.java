```
class MovingAverage {
    int len;
    int sum = 0;
    double result;
    ArrayList<Integer> arr = new ArrayList<>();
    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        len = size;
    }
    
    public double next(int val) {
        Integer tmp = val;
        arr.add(tmp);
        
        if (arr.size() >= len) {
            for (int i = 0; i <len; i++) {
                sum += arr.get(arr.size()-1-i);
                result = (double)sum / (double)len;
            }
        }
        if (arr.size() < len) {
            for (int i = 0; i <arr.size(); i++) {
                sum += arr.get(i);
                result = (double)sum / (double)arr.size();
            }
        }
        sum = 0;
        return result;
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
```

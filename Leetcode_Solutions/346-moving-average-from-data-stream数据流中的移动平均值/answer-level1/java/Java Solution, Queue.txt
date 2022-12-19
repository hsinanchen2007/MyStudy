```
class MovingAverage {

    private Queue<Integer> q;
    private int sum;
    private int size;

    public MovingAverage(int size) {
        q = new LinkedList<Integer>();
        this.size = size;
    }
    
    public double next(int val) {
        if (q.size() == size) {
            sum -= q.remove();
        }
        q.offer(val);
        sum += val;
        return (double) sum / q.size();
    }
}
```

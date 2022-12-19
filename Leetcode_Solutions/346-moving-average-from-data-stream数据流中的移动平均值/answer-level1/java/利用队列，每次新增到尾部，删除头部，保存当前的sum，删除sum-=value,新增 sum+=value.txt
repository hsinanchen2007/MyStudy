
class MovingAverage {

    LinkedList<Integer> queue =null;
    int size;
    int sum=0;
    /** Initialize your data structure here. */
    public MovingAverage(int size) {
      queue =new LinkedList<Integer>();
      this.size=size;
    }
    public double next(int val) {

        if(queue.size()==size){
          sum -= queue.remove();
        }
        queue.offerLast(val);
        sum+=val;
        return (double)sum/(double)(queue.size());

    }
}
只要使用java自带的优先队列,我的主要想法就是把integer数据类型自己化简一下.
使得其包含成员val值和下标,重写该类的equals方法使得下标相等对象就相等.然后再优先队列里面存放自己带下标的"int"类型.之后调用remove(Obj)方法.
```
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

public class question_239 {
    public int[] maxSlidingWindow(int[] nums, int k) {
//        int[] results=new int[100];
        if(nums.length==0 || k==0){
            return new int[0];
        }
        ArrayList<Integer> results=new ArrayList();
        PriorityQueue<myInt> maxHeap=new PriorityQueue<myInt>(k, new Comparator<myInt>() {
            @Override
            public int compare(myInt o1, myInt o2) {
                return o2.getVal()-o1.getVal();
            }
        });
        for(int i=0;i<nums.length;i++){
            if(maxHeap.size()<k)
                maxHeap.offer(new myInt(nums[i],i));
            else{
                maxHeap.remove(new myInt(0,i-k));
                maxHeap.offer(new myInt(nums[i],i));
                results.add(maxHeap.peek().getVal());
            }

        }
        int[] temp=new int[results.size()];
        int i=0;
        for (Integer n:results){
            temp[i]=n;
            i++;
        }
        return temp;
    }
}
class myInt{
    private int val;
    private int index;
    myInt(int val,int index){
        this.val=val;
        this.index=index;
    }

    public int getIndex() {
        return index;
    }

    public void setIndex(int index) {
        this.index = index;
    }

    public int getVal() {
        return val;
    }

    public void setVal(int val) {
        this.val = val;
    }
    @Override
    public boolean equals(Object obj){
        // 如果为同一对象的不同引用,则相同
        if (this == obj) {
            return true;
        }
        // 如果传入的对象为空,则返回false
        if (obj == null) {
            return false;
        }

        // 如果两者属于不同的类型,不能相等
        if (getClass() != obj.getClass()) {
            return false;
        }
        myInt other=(myInt) obj;
        return other.getIndex()==this.getIndex();
    }
}
```
实际效果并不好,速度不快,自己只是采用这种思路实现一下,比自己写一个堆简单不少.
```
class Solution {
    int size;
    int[] stones;
    public int lastStoneWeight(int[] stones) {
        this.size = stones.length;
        this.stones = stones;
        for(int i = (size>>1)-1;i>=0;i--)//建堆
            siftDown(i,stones[i]);
        while(size>1){
            int x = poll();//取出当前最大的两个值
            int y = poll();
            if(x!=y)//不相同则添加新值
                add(Math.abs(x-y));
        }
        return size==0?0:stones[0];
    }
    private void add(int x){
        
        stones[size]=x;
        
        siftUp(size++,x);
        
    }
    private int poll(){
        
        int result = stones[0];
        
        stones[0]=stones[--size];
        
        siftDown(0,stones[0]);
        
        return result;
    }
    private void siftUp(int k,int x){
        while(k>0){
            int father = (k-1)>>1;
            int y = stones[father];
            if(y>=x)break;
            stones[k] = y;
            k = father;
        }
        stones[k]=x;
    }
    private void siftDown(int k,int x){
        int half = size>>1;
        while(k<half){
            int child = (k<<1)+1;
            int y = stones[child];
            int right = child+1;
            if(right<size&&stones[right]>y)y = stones[child=right];
            if(x>=y)break;
            stones[k] = y;
            k = child;
        }
        stones[k]=x;
    }
}
```


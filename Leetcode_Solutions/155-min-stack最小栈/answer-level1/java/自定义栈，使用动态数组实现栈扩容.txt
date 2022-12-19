class MinStack {
    private int data[];
    private int size;
    /** initialize your data structure here. */
    public MinStack() {
        data=new int[100];
        size=0;
    }

    public void push(int x) {
        if(size==data.length){//动态扩容
            int newData[]=new int[size*2];
            for(int i=0;i<size;i++){
                newData[i]=data[i];
            }
            data=newData;
        }
        data[size]=x;
        size++;
    }

    public void pop() {
        if(size>0){
            size--;
        }
        

    }

    public int top() {
        if(size>0){
            return data[size-1];
        }
        return 0;
    }

    public int getMin() {
        int min=data[0];
        for(int i=0;i<size;i++){
            if(data[i]<min){
                min=data[i];
            }
        }
        return min;
    }
}
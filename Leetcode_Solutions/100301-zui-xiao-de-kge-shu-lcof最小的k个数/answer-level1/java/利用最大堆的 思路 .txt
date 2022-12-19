### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    class heap{
      public  int data[]; //存储数据的数组 
        int count; //当前有多少个元素  
        int capacity; //总共容量 代表k

        public heap(int capacity){
            this.capacity=capacity;
            this.count=0;
            data=new int[capacity+1] ;  //初始化为capacity+1 是为了 从数组的1下标开始存储元素 方便就算堆元素的位置
        }

        public void  insert(int value){
            if(count>=this.capacity){
                    return ;
            }
            this.data[++count]=value;
            heapFyB2T(this.data,this.count);
        }

        public void heapFyB2T(int []data,int end){
            int i=end;
            while(i/2>0&&data[i]>data[i/2]){
                swap(data,i,i/2);
                i=i/2;
            }
        }

        public int reMoveMax(){
            if(this.count<1){
                return -1;
            }
            int max=data[1];
            this.data[1]=this.data[count--];
            heapFyT2B(this.data,1,this.count);
            return max;
        }
        public void heapFyT2B(int data[],int begin,int end){
            int maxPos=begin;
                while(true){
                    if(2*begin<=end&&data[maxPos]<data[2*begin]){
                        maxPos=2*begin;
                    }
                    if(2*begin+1<=end&&data[maxPos]<data[2*begin+1]){
                        maxPos=2*begin+1;
                    }
                    if(maxPos==begin){
                        break;
                    }
                    swap(data,maxPos,begin);
                    begin=maxPos;
                }
        }
        public int getMax(){
            return data[1];
        }
        public void swap(int []arr,int l,int r){
        int tmp=arr[l];
        arr[l]=arr[r];
        arr[r]=tmp;
    }
    }
    public int[] getLeastNumbers(int[] arr, int k) {
        if(k<=0){
            return new int[]{};
        }
            heap h=new heap(k);
            for(int i=0;i<k;i++){
                h.insert(arr[i]);
            }
            for(int i=k;i<arr.length;i++){
                int max=h.getMax();
                if(arr[i]<max){
                    h.reMoveMax();
                    h.insert(arr[i]);
                }else{
                    continue;
                }
            }
            int[] res=Arrays.copyOfRange(h.data,1,h.data.length);
        return  res;
    }
    /*
  public int[] getLeastNumbers(int[] arr, int k) {
        if(arr.length==0||k==0||k>arr.length){
                return new int[]{};
        }
        int begin=0;
        int end=arr.length-1;
        int index=  quickSort(arr,begin,end);
//2   2
        while(index!=k-1){
            if(index>k-1){
                    end=index-1;
                   index=quickSort(arr,begin,end);
            }else{
                begin=index+1;
                index=quickSort(arr,begin,end);
            }
        }

        return Arrays.copyOfRange(arr,0,k);//2 1 4 3

    }
    public int quickSort(int []arr,int begin,int end){//1 4 3 1 5 2
        //默认数组中待分区区间的最后一个是pivot元素  当然也可以随机指定pivot元素
        int  pivot = arr[end];
        //定义分区后pivot元素的下标
        int pivotIndex = begin;
        for(int i= begin;i< end;i++){
            //判断如果该区间内如果有元素小于pivot则将该元素从区间头开始一直向后填充 有点类似选择排序
            if(arr[i] < pivot){

                if(i>pivotIndex){
                    swap(arr,i,pivotIndex);
                }
                pivotIndex++;
            }
        }
        swap(arr,pivotIndex,end);
        return pivotIndex;
    }
    public void swap(int []arr,int l,int r){
        int tmp=arr[l];
        arr[l]=arr[r];
        arr[r]=tmp;
    }*/
}
```
import java.util.*;

class KthLargest {
    int[] kheap;   //小顶堆
    int capacity;  //记录堆的大小，就是k
    int count=0;   //记录堆中有几个有效的数，无效的数理解为数组初始化时候的0
    
    public KthLargest(int k, int[] nums) {
        capacity=k;
        kheap = new int[capacity];
        
        for(int i=0;i<nums.length;i++)
            add(nums[i]);        
    }
    
    public int add(int val) {
        if(count < capacity){
            kheap[count++]= val;
            MinHeapify_adjustup(kheap,count-1);
        }
        else{
            if(val > kheap[0]){
                kheap[0]=val;
                MinHeapify_adjustdown(kheap,0);
            }
        }      
        return kheap[0];   
    }
    
    //从指定位置向下调整为小顶堆
    public static void MinHeapify_adjustdown(int[] array, int i){
        if(array == null || array.length <= 1)
            return;
        int left = 2*i +1;
        int right = 2*i+2;
        int min = i;
        int len = array.length;
       
        if(left < len && array[i] > array[left])
            min = left;
        if(right < len && array[min] > array[right])
            min = right;
        
        if(min != i){
            int temp;
            temp = array[i];
            array[i] = array[min];
            array[min]= temp;   
            MinHeapify_adjustdown(array, min);
        }
    }
    
    //从指定位置向上调整为小顶堆
    public static void MinHeapify_adjustup(int[] array,int i){

        //向上调整到下标为0的位置就不调整了
        if(i==0){
            return;

        }
        //其父亲结点
        int parent=(i-1)/2;

        //与父亲结点相比较
        //如果父亲节点的值大，就交换位置，否则就不调整了
        if(array[parent]>array[i]){
            int t=array[parent];
            array[parent]=array[i];
            array[i]=t;

            //继续向上调整
            MinHeapify_adjustup(array,parent);
        }
    }

}
首先创建大根堆，将最大值赋值给a，接着将stones[0]=0后再对堆进行调整为大根堆，将得到的最大值赋值给b，若a=b，则重新赋值stones[0]=0调整堆，否则赋值stones[0]=（a-b）调整堆;直到数组stones[1]和stones[2]值都为0时，返回stones[0]的值。
```
class Solution {
    public int lastStoneWeight(int[] stones) {
        if(stones.length==1)return stones[0];
        buildMaxHeap(stones);
        if(stones.length==2)return stones[0]-stones[1];
        int l=stones.length;
        while(stones[1]!=0||stones[2]!=0){
            int a = stones[0];
            stones[0]=0;
            adjustDown(stones,0,l);
            int b = stones[0];
            if(a==b){
                stones[0]=0;
                adjustDown(stones,0,l);
            }else{
                stones[0]=a-b;
                adjustDown(stones,0,l);
            }
        }
        return stones[0];
    }
    //建立大顶堆
    public static void buildMaxHeap(int[] a) {
        for(int i=(a.length/2)-1;i>=0;i--) {
            adjustDown(a,i,a.length);
        }
    }
    //向下调整
    public static void adjustDown(int[] a,int i,int len) {
        int temp,j;
        temp=a[i];
        for(j=2*i+1;j<len;j=2*j+1) {       //j为当前i的子节点，默认为左节点
            if(j+1<len&&a[j+1]>a[j])       //如果右节点大，则选右节点
                j++;
            if(a[j]<=temp)                 //若子节点都比初始值temp小，说明找到了位置
                break;
            else {                           
                a[i]=a[j];                   //如果没有终止，那么将子节点中数值大的上调至i处    
                i=j;                       //同时i下降到j这个位置
            }
        }
        a[i]=temp;                           //将temp放在最终的位置
    }
}
```

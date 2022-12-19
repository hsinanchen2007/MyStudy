### 解题思路
此处撰写解题思路
自定义了一个堆结构来实现，没有使用原生的PriorityQueue,纯练习，高工勿喷，有错误欢迎指点
### 代码

```java
class Solution {
    private int[] headArray;
    private int currentSize;
    public int findKthLargest(int[] nums, int k) {
        headArray=new int[k+1];
        for(int d:nums){
            insert(d);
            if(currentSize>k){
                 revomeTopData();
            }
        }
         return revomeTopData();
    }


    void insert(int data){
        headArray[currentSize]=data;
        trickleUp(currentSize++);
    }

    int revomeTopData(){
        int topData=headArray[0];
        headArray[0]=headArray[currentSize-1];
        trickleDown();
        currentSize--;
        return topData;

    }

    private void trickleUp(int index){
        int parentIndex=(index-1)>>1;
        int currentData=headArray[index];
        while(index>0&&headArray[parentIndex]>currentData){
            headArray[index]=headArray[parentIndex];
            index=parentIndex;
            parentIndex=(index-1)>>1;
        }
        headArray[index]=currentData;
    }


    private void trickleDown(){
        int index=0;
        int currentData=headArray[index];
        int smallChildIndex;
        while(index<currentSize/2){
        int leftChildIndex=(index<<1)+1;
        int rightChildIndex=leftChildIndex+1;

        if(rightChildIndex<currentSize&&headArray[leftChildIndex]<headArray[rightChildIndex]){
            smallChildIndex=leftChildIndex;
        }else{
            smallChildIndex=rightChildIndex;
        }
        if(currentSize<=smallChildIndex||currentData<=headArray[smallChildIndex])
        break;
        headArray[index]=headArray[smallChildIndex];
        index=smallChildIndex;
        }
        headArray[index]=currentData;
    }
}
```
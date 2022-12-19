### 解题思路
此处撰写解题思路
实现堆结构，使用堆解决该问题
### 代码

```java
class Solution {

private int currentSize;
private int[] headArray;
    public int[] getLeastNumbers(int[] arr, int k) {
        if(arr==null)return null;
        headArray=new int[arr.length];
        for(int i=0;i<arr.length;i++){
            inster(arr[i]);
        }

        int [] returnDataArray=new int[k];
        for(int x=0;x<headArray.length;x++){
            if(x==k)break;
            int minData = removeMinData();
                returnDataArray[x]=minData;

        }


        return returnDataArray;
    }

    boolean inster(int data){
        //获取节点的索引
      if(currentSize==headArray.length)return false;
        headArray[currentSize]=data;
        trickleUp(currentSize);
        currentSize++;
        return true;
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


    private int removeMinData(){
        if(currentSize==0)return 0;
        int minData=headArray[0];
        headArray[0]=headArray[--currentSize];
        trickleDown();
        return minData;
    }


    private void trickleDown(){
    int currentIndex=0;
    int currentData=headArray[currentIndex];
    int smallChildIndex;
    while(currentIndex<currentSize/2){
        int leftChildIndex=(currentIndex<<1)+1;
        int rightChildIndex=leftChildIndex+1;
        if(rightChildIndex<currentSize&&headArray[leftChildIndex]<headArray[rightChildIndex]){
            smallChildIndex=leftChildIndex;
        }else{
            smallChildIndex=rightChildIndex;
        }
        if(currentData<=headArray[smallChildIndex])break;
        headArray[currentIndex]=headArray[smallChildIndex];
        currentIndex=smallChildIndex;
    }
    headArray[currentIndex]=currentData;

    }
}
```
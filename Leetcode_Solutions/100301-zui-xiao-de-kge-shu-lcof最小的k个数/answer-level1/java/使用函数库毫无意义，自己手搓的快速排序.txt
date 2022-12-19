### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        
        quickSort(arr,0,arr.length-1);
        
        return getMinNumber(arr,k);
        
    }
    
    
    
    //取前k个最小数
    public int[] getMinNumber(int[] arr,int k){
        int[] minValue = new int[k];
        for(int i=0;i<k;i++){
            minValue[i]=arr[i];
        }
        return minValue;
    }
    
    
    
    
    //递归执行排序
    public void quickSort(int[] arr,int low,int hight){
        
        if(low<hight){
            int index = getIndex(arr,low,hight);
            quickSort(arr,low,index-1);
            quickSort(arr,index+1,hight);
        }
        
    }
    
       
    
    //寻找基准数索引方法
    public int getIndex(int[] arr,int low,int hight){
        
        //设定基准数
        int temp = arr[low];
      
        while(low<hight){
            
        //当尾指针数值大于基准值，尾指针向后移一位
        while(low<hight && temp<=arr[hight]){
            hight--;
        }
      //当尾指针数值小于基准值，尾指针值赋给头指针值
        arr[low]=arr[hight];
        
        
        //当头指针数值小于基准值，头指针前移一位
        while(low<hight && temp>=arr[low]){
            low++;
        }
        //当头指针数值大于基准值，头指针值赋给尾指针值
        arr[hight]=arr[low];  
    }   
        arr[low]=temp;
        return low;
 }
     
    
}
```
### 解题思路
堆的
1.父结点索引：(i-1)/2（这里计算机中的除以2，省略掉小数）
2.左孩子索引：2*i+1
3.右孩子索引：2*i+2

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        int n = arr.length;
        //n表示数组内元素个数
        creatHeap(n, arr);
        int m = n - 1;
        //m是数组坐标，堆顶和最后一个记录交换，交换后n减1。最后一次的根就不用动了。
        while(m > 0){
            int temp = arr[0];
            arr[0] = arr[m];
            arr[m] = temp;
            Sink(0, m, arr);
            m--;
        }

        int[] result = new int[k];
        for(int i= 0; i < k; i++){
            result[i] = arr[i];
        }
        return result;
    }

    //大堆
    public void creatHeap(int n, int[] arr){
        //从最后一个分支结点n/2开始调整为堆，直到第一个结点
        for(int i = n/2 - 1; i >= 0; i--){ 
            Sink(i, n, arr);
        }
    }

    public void Sink(int i, int n, int[] arr){
        while(2*i + 1 < n){  //如果有左孩子2j+1
            int j = 2*i + 1;
            if(j + 1 < n && arr[j] < arr[j+1]){
                j++;
            }
            if(arr[i] >= arr[j]){  //大堆是>号
                break;
            }
            else{
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            i = j;
        }
    }
    
}
```
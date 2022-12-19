### 解题思路
此处撰写解题思路

topK应该有别的优解的，没想起来怎么搞，就使用快排序取前K个数

快排基本思路
    1.使用一个基准数，将数组分成两部分，前半部分是小于这个基准数，后半部分大于这个基准数，一般都选择第一个数字做基准数
    2.各自递归两部分数组，左边部分将再分为两部分，小于基准数放左边，大于基准数放右边，基准数放中间，右边也一样
    3.当左边索引大于或者等于右边所索引时，退出递归

有些人可能会开始疑惑直接arr[low] = arr[high];  其实这块相当于一个换位置的操作，看到arr[high] = arr[low];和arr[low] = index;就会明白了，相当于交换位置，使用了temp临时变量一个道理

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        int[] result = new int[k];
        if(k<0 || arr.length>10000){
            return null;
        }
        quickSort(arr,0,arr.length - 1);
        
        for(int i = 0;i<k; i++){
            result[i] = arr[i];
        }
        return result;
    }

    public static void quickSort(int[] arr,int left,int right){
        if(left<right){
            int index = arr[left];
            int low = left,high = right;
            
            while(low<high){
                while(low<high && index <= arr[high]){
                    high --;
                }
                arr[low] = arr[high];
                while(low<high && index >= arr[low]){
                    low++;
                }
                arr[high] = arr[low];
            }
            arr[low] = index;

            quickSort(arr, left, low);
            quickSort(arr, low + 1,right);
        }
    }
}
```
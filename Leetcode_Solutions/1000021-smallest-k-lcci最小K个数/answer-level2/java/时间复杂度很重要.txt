### 解题思路
此处撰写解题思路
我的思路:
    一开始的时候使用选择排序的，发现算法不是能优化，会超过时间限制的，又用了冒泡，发现也没什么用
后来用这个插入的方法，还真的比较快！
### 代码

```java
class Solution {
    public int[] smallestK(int[] arr, int k) {
        for(int i=1;i<arr.length;i++){
            int temp=arr[i];
            int index=i-1;
            while(index>=0 && temp<arr[index]){
                arr[index+1]=arr[index];
                index--;
            }
            arr[index+1]=temp;
        }
        int c[]=new int[k];
        int j=0;
        while(j<k){
            c[j]=arr[j];
            j++;
        }
        return c;
    }
}
```
### 解题思路
本题我有两种做法，第一种顺序求解，每一次都找出右侧数组中最大的值，然后遍历完后给最末尾的赋值-1.这种太慢了
第二种做法就是逆序求解，定义一个max指针，永远指向最大值。然后创建一个和原数组相同大小的数组，去承载max指向的值。

### 代码

```java
class Solution {
    public int[] replaceElements(int[] arr) {
        int max=0;
        int[] newArray = new int[arr.length];
        newArray[arr.length-1]=-1;
        if(arr.length==1) return newArray;
        for(int i=arr.length-1;i>0;i--){
            if(arr[i]>max)
                max=arr[i];
            newArray[i-1]=max;
        }
        return newArray;
    }
}
```
### 解题思路
此处撰写解题思路
我的思路:
    用比较排序法，创建一个max变量赋初值为0，然后用比较算法，用后面的一个值和这个max比较
如果比max大，那么就直接辅助到max变量中，后面的循环完了以后，直接将max放入到arr[0]中，max
还要赋初值为0，不重新赋初值的话会导致max里面就是最大的值，
再最后我们将-1放到数组的最后一个！就ok;
### 代码

```java
class Solution {
    public int[] replaceElements(int[] arr) {
        int max=0;
            for(int i=0;i<arr.length-1;i++){
                for(int j=i+1;j<arr.length;j++){
                        if(arr[j]>max){
                            max=arr[j];
                        }
                }
                arr[i]=max;
                max=0;
            }
            arr[arr.length-1]=-1;
            return arr;
    }
}
```
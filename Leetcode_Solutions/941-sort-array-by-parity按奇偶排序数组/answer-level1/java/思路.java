### 解题思路
此处撰写解题思w路
我的思路:
    用新的数组来存放
    首先创建一个和原始数组一样长度的数组，然后判断原始数组中的值是否为偶数，如果是偶数就将值
放到最前面，然后递增，
    如果是奇数，我们从数组的最后一个位置往前放置奇数的值，然后递减；
最后返回的就是新数组的首地址;ok

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
  
        int arr[]=new int[A.length];
        int k=0,p=0;
        for(int i=0;i<A.length;i++){
            if(A[i]%2==0)
            {
                arr[k]=A[i];
                k++;
            }else{
                arr[arr.length-p-1]=A[i];
                p++;
            }
        }
        return arr;
    }
}
```
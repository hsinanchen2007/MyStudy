### 解题思路
此处撰写解题思路
我的思路:
    新创建一个和原始数组长度一样的数组，然后把偶数放在新数组的前面，把奇数都放在新数组的后面。
    再创建一个新的数组
    然后遍历原始数组，判断下标是否是奇数还是偶数，如果下标是奇数，那么我将把第二个数组的最后一个长度的位置给
这个新数组的当前下标的位置，如果是偶数，那么就直接将第二个数组的前面的到后面偶数赋值给这个新数组。
    最后返回这个新数组，就ok;
### 代码

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int ou,j;
        ou=j=0;
        int arr[]=new int[A.length];
        for(int i=0;i<A.length;i++){
            if(A[i]%2==0){
                arr[ou]=A[i];
                ou++;
            }else{
                arr[arr.length-j-1]=A[i];
                j++;
            }
        }
        int k,p=0;
        k=0;
        int b[]=new int[arr.length];
        for(int i=0;i<arr.length;i++){
            if(i%2==0){
                b[i]=arr[k];
                k++;
            }else{
                b[i]=arr[arr.length-p-1];
                p++;
            }
        }
        return b;
    }
}
```
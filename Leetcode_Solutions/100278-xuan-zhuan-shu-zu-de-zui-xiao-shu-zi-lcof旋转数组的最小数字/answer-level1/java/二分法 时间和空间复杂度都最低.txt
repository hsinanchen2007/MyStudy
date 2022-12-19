### 解题思路
旋转数组，获得最小值。
想要获得logn级别的时间复杂度，通过二分法查找 
本题规律是，作为旋转轴的那个数在最右边，所以每次二分时，mid和最右边的数字进行比较
arr[mid]>arr[right]，递归时在mid右边查找；
arr[mid]<arr[right],递归时，在mid左边查找；
相等时，right往前挪一位，缩小范围


### 代码

```java
class Solution {
    int partition(int left,int right,int arr[])
    {
    
    if(left==right)
    return arr[left];
    int mid=left+(right-left)/2;
    if(arr[mid]>arr[right])
    return partition(mid+1,right,arr);
    else if(arr[mid]<arr[right])
    return partition(left,mid,arr);
    else 
    {
        return partition(left,right-1,arr);
    }

    }
    public int minArray(int[] numbers) {
    int k= partition(0,numbers.length-1,numbers);
    return k;
    }

}
```
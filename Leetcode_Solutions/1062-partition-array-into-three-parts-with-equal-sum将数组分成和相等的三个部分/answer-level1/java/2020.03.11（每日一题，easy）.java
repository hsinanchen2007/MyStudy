### 解题思路
本题击败双100%用户

首先将整个数组的数组加起来看能不能除尽3，若不能则无法分组，若能则继续

使用双指针法分别在数组头和数组尾设立两个索引

头索引依次+后面的元素，直到满足三等分的第一组

同时，尾索引依次+前面的元素，直到满足三等分的第一组

第一组和第三组都划分好后，那么中间第二组也满足要求，这样就分好3组了。

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        
        for(int i:A){
            sum += i;
        }
        
        if(sum % 3 != 0){//整个数组加起来不能除尽3，则无法3等分
            return false;
        }
        
        int left = 0;
        int leftSum = A[left];//代表第一组
        int right = A.length - 1;
        int rightSum = A[right];//直接代表整个数组
        
        while(left + 1 < right){//中间可以留出一组
            if(leftSum == sum / 3 && rightSum == sum / 3){
                return true;
            }
            if(leftSum != sum / 3){//左边不满足就不断++，直到满足第一组等分
                leftSum += A[++left];
            }
            if(rightSum != sum / 3){
                rightSum += A[--right];
            }
        }
        return false;
    }
}
```
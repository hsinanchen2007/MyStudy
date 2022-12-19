![l.png](https://pic.leetcode-cn.com/369ec5deccc151aa26b1aef55b1b6140414c2ac2c5fde05ef97d50151abc2fa7-l.png)


### 解题思路
如果能等分，数组的所有元素和肯定能被3整除。所以在所有元素和能被3整除这个前提下，我们从数组左右两端分别找到使左右两边的子数组都等于等分和的索引位置。此时如果左右索引中间还有剩余元素，说明中间剩余元素的和也是等分和。

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int len=A.length;
        int sum=0;
        for(int i=0;i<len;i++){
            sum+=A[i];
        }
        //数组所有元素和不能被3整除，不满足等分要求
        if(sum%3!=0){
            return false;
        }
        int subSum=sum/3;
        //左右指针和左右等分和
        int left=1,leftSum=A[0],right=len-2,rightSum=A[len-1];
        //移动左边指针使左边子数组等于等分和
        while(leftSum!=subSum&&left<len){
            leftSum+=A[left];
            left++;
        }
        //移动右边指针使右边子数组等于等分和
        while(rightSum!=subSum&&right>=0){
            rightSum+=A[right];
            right--;
        }
        //此时左右指针中间还有剩余元素说明数组满足等分要求
        return left<=right;
    }
}
```
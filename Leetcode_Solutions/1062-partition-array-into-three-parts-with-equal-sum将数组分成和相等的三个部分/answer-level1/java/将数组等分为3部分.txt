### 解题思路
- 计算数组的总和，若不能被3整除返回false
- 双指针从两端往中间逼近，看是否能够两边的加和leftsum和rightsum都等于target

注意的点：此题不允许空的分组，因此若target为0时要注意不要让左右分组的大小为0
我的做法是把leftsum和rightsum的值提前加上一个，让left从1开始和right从len-2开始
另外最后找到之后，再次验证 中间的分组是否大小为0，因为可能只分了左右两组

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        int len = A.length;
        for(int i = 0; i <len; i ++){
            sum+=A[i];
        }
        if(sum%3 != 0)return false;
        int target = sum/3;
        int left = 0;
        int right = len-1;
        int leftsum = A[left++];
        int rightsum = A[right--];
        while(left < right){
            if(leftsum != target){
                leftsum += A[left++];
            }
            if(rightsum != target){
                rightsum += A[right--];
            }
            if(leftsum == target && rightsum == target) {
            	// System.out.println("left:"+left+",right"+right);
            	return right - left >=0;
            }
        }
        return false;
    }
}
```
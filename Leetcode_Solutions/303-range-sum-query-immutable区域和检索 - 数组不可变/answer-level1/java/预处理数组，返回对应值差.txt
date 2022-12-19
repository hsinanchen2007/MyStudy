### 解题思路
首先在初始化的阶段，将数组遍历前 i 个的和保存至数组的第 i 个位置
在调用 sumRange(i,j) 方法时，返回数组第 j 个和第 i-1 个的差值 

### 代码

```java
class NumArray {

    int[] numArray;
    public NumArray(int[] nums) {
        numArray = nums;
        
        for(int i = 1;i<numArray.length;i++) {
            numArray[i] = numArray[i]+numArray[i-1];
        }

    }
    
    public int sumRange(int i, int j) {
        return i == 0 ? numArray[j]:numArray[j]-numArray[i-1];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```
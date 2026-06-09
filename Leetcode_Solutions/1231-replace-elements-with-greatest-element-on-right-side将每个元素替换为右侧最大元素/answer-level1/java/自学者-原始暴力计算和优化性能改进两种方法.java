### 解题思路
方法一、暴力计算法
* 用暴力计算当前位置之后的最大元素
* 最后一位直接替换为-1
方案二、O(1)空间复杂度 O(n)时间复杂度
* 一次迭代计算法

### 代码

```java []
// 方案一、最原始最大计算方案
class Solution {
    public int[] replaceElements(int[] arr) {
        int len = arr.length;
        int anchor = 0;
        int left = 0;
        int right = len-1;
        int[] ans = new int[arr.length];
        while (anchor < len) {
            left = anchor + 1;
            int max = Integer.MIN_VALUE;
            while (left <= right) {
                max = Math.max(max,arr[left++]);
            }
            ans[anchor++] = max;
        }
        ans[ans.length-1] = -1; 
        //System.out.println(Arrays.toString(ans));
        return ans;
    }
}
```

```java []
// 方案二 算法优化版，直接修改了arr的内容，一次遍历高效计算
class Solution {
    public int[] replaceElements(int[] arr) {
        int len = arr.length;
        int rightMax = arr[len - 1];
        arr[len-1] = -1;
        for (int rightIndex = len - 2; rightIndex >= 0; rightIndex--) {
            int curValue = arr[rightIndex];
            arr[rightIndex] = rightMax;
            rightMax = Math.max(curValue,rightMax);
        }
        return arr;
    }
}
```
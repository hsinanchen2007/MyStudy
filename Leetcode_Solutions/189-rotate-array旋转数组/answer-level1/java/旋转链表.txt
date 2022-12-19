### 解题思路
根据题目要求查看，可以通过不断反转获得结果

### 代码

```java
class Solution {
    public void rotate(int[] nums, int k) {

        // 处理一下k值输入【用例: [-1] 、2】
        k = k % nums.length;  // 取模，保证输入的正确性（不超过数组长度）

        // 新思路分析观察特征： k后面的、k前面的
        // 1. 数组倒置——7 6 5 4 3 2 1
        reverse(nums, 0, nums.length-1);
        // 2. k之前的倒置--5 6 7
        reverse(nums, 0, k-1);
        // 3. k之后的倒置--567 1 2 3 4
        reverse(nums, k, nums.length-1);



        for (int num : nums) {
            System.out.print(num+" ");
        }

    }

    private void reverse(int[] arr, int start, int end){
        while (start < end){
            // 首尾互换
            int tmp = arr[start];
            arr[start] = arr[end];
            arr[end] = tmp;
            start++;
            end--;
        }
    }
}
```
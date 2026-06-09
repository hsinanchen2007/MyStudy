### 解题思路
1.求出新数组长度
2.添加数据,统计循环次数和带循环数

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
     if (nums.length < 2 || nums.length > 100 || nums.length % 2 != 0) {
            return null;
        }
        // 求新数组长度（统计循环次数）
        int len = 0;
        for (int i=0;i<nums.length;i+=2){
            len +=nums[i];
        }
        int[] res = new int[len];
        int k = 0,j=0;// 变量
        while (k < len) {
            int count = nums[j]; // 获取循环次数
            while (count--!=0){
                res[k] = nums[j+1]; // 获取待循环数
                k++;
            }
            j+=2;
        }
//        System.out.println(Arrays.toString(res));
        return res;
    }
}
```
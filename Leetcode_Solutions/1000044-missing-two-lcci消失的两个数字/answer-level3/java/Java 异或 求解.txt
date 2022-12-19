### 解题思路
异或思路： 其他数字只出现2次，有两个数出现一1的情况



### 代码

```java
class Solution {
    public int[] missingTwo(int[] nums) {


        int n = nums.length;
        int num=0;
// 只有遍历这两个数组，才会出现，
        for(int i=1;i<(n+3);i++){
            num^=i;
        }
        for (int i=0;i<n;i++) {
            num^=nums[i];
        }
        int posindex = num&(-num);
        int one = 0;
        int two = 0;
//只有遍历这两个数组，才会出现，
        for (int i=1;i<(n+3);i++) {
            if ((posindex & i) == posindex) {
                one^=i;
            }else {
                two^=i;
            }
        }
        for (int i=0;i<n;i++) {
            if ((posindex & nums[i]) == posindex) {
                one^=nums[i];
            }else {
                two^=nums[i];
            }
        }
        int[] res = new int[2];
        res[0]=one;
        res[1]=two;
        return res;
    }
}
```

也可以把代码整合一下，整合成一个数组，来处理！
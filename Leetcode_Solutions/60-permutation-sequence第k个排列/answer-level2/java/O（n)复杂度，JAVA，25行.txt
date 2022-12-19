### 解题思路
从高位到低位，使用同余的思想，依次求出数字下标，并从nums数组中取出。

### 代码

```java
class Solution {
    public String getPermutation(int n, int k) {
        List<Integer> nums = new LinkedList<>();
        for (int i = 1; i <= n; i++){
            nums.add(i);
        }

        StringBuilder ans = new StringBuilder();
        int index = k - 1;
        int funcValue = func(n);
        for (int i = n; i > 0; i--){
            funcValue /= i;
            int temp = index / funcValue;
            ans.append(nums.remove(temp) + "");
            index = index % funcValue;
        }

        return ans.toString();
    }

    public int func(int i){
        if (i == 0 || i == 1) return 1;
        return i * func(i - 1);
    }
}
```
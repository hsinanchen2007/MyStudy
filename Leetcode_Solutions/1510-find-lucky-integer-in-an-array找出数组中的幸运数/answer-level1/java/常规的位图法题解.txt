
> 100 / 100 个通过测试用例
> 状态：通过
> 执行用时：1 ms
> 内存消耗：39.6 MB

提示信息很重要：
> - 1 <= arr.length <= 500
> - 1 <= arr[i] <= 500

常规的位图法解决即可

```java
class Solution {
    public int findLucky(int[] arr) {
        int[] count = new int[510];
        for(int a: arr) {
            count[a] ++;
        }
        for(int i = count.length -1; i > 0; i --) {
            if(i == count[i]) {
                return i;
            }
        }
        return -1;
    }
}
```
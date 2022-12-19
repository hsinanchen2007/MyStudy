### 解题思路
方法一 维护三个最大数的数组，最后根据数组size进行返回判断
（整形类型是有范围的，最大值为Integer.MAX_VALUE，即2147483647，最小值为Integer.MIN_VALUE -2147483648）

方法二 用TreeSet来完成

### 代码
方法一：
```java
class Solution {
    public int thirdMax(int[] nums) {
        //只需要维持三个数的数组，最大的数保存到ans[0]中，然后做三个判断。
        //可能会出现的情况就是，Integer.MIN_VALE越界的问题
        long[] ans = {Long.MIN_VALUE, Long.MIN_VALUE, Long.MIN_VALUE};
        int count = 0;
        for(int num:nums){
            if(num > ans[0]){
                ans[2] = ans[1];
                ans[1] = ans[0];
                ans[0] = num;
                count++;
            }else if(num < ans[0] && num > ans[1]){
                ans[2] = ans[1];
                ans[1] = num;
                count++;
            }else if(num < ans[1] && num > ans[2]){
                ans[2] = num;
                count++;
            }
        }

        if(count<3){
            return (int)ans[0];
        }else{
            return (int)ans[2];
        }
    }
}
```
方法二
```java
class Solution {
    public int thirdMax(int[] nums) {
        TreeSet<Integer> tree = new TreeSet();

        for(int num:nums) tree.add(num);

        if(tree.size() < 3) return tree.last();
        else{
            tree.remove(tree.last());
            tree.remove(tree.last());
            return tree.last();
        }  
        
    }
}
```
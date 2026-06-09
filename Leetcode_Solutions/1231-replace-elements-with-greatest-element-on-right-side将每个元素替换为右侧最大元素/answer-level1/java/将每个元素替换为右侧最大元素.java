### 解题思路
    从最后一个元素遍历起，最大值初始为-1，首先利用一个寄存变量保存遍历到的元素arr[i]，之后将arr[i]替换为max(它右边的最大元素)。再比较，如果寄存的变量temp大于max，更新max
### 代码

```java
class Solution {
    public int[] replaceElements(int[] arr) {
        //思路：从后往前排，定义一个变量跟踪最大值
        int max=-1;
        for(int i=arr.length-1;i>=0;i--)
        {
            int temp=arr[i];
            arr[i]=max;
            if(temp>max)
                max=temp;
        }
        return arr;
    }
}
```
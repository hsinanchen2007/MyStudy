### 解题思路
此处撰写解题思路
使用for循环，分别求每个数的二进制1的位数
### 代码

```java
class Solution {
    public int[] countBits(int num) {
        // 方法1：
        int arr[] = new int[num+1];
        arr[0] = 0;
        for(int i=1;i<=num;i++){
            int sum = 0;// 每个数的二进制1的位数
            int index = i;
            while(index != 0){
                sum++;
                index &= (index-1);// 每执行一次消除掉低位的一个1，直到所有的1被消除
            }
            arr[i] = sum;
        }
        return arr;
    }
}
```
### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] singleNumbers(int[] nums) {
        //异或取两个数
        int a = 0;
        for(int n:nums){
            a ^= n;
        }
        //取a 最右边的 1,这个1 在两个数中只有一个有，假如都有的话话就异或为 0 
        int b = a&-a;

        //通过最右边这个 1 过滤掉其中一个数，在剩下的数里面找到另外一个数
        int c =0;
        for(int n:nums){
            //不止是另外一个数，只要这个位置为1都会过滤，但是是成组的
            if((b & n) != 0){
                c ^=n;
            }
        }
        
        int[] re = {c,c^a};
        return re;
    }
}
```
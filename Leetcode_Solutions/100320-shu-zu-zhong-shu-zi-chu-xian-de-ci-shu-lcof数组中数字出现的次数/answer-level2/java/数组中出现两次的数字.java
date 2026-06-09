### 解题思路
首先对所有的数字，进行异或处理，a^a = 0;
a^a^b = b,b^a^b = a;
因为这两个数字a b不同，所以二者肯定可以根据最低位的bit 将其分为两部分即可
### 代码

```java
class Solution {
    public int[] singleNumbers(int[] nums) {
        int temp = 0;
        int[] array = new int[2];
        for(int num:nums){
            temp^=num;
        }
        int flag = temp&-temp;
        for(int num:nums){
            if((num&flag)==0)
                array[0]^=num;
            else
                array[1]^=num;    
        }
        return array;
    }
}
```
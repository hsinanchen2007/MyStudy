### 解题思路
一开始的思路太复杂，一看到这个题我就想着用两个循环，先把数组中的每遍历一个数就拿出来，然后再遍历除这个数
之外的数，可是当这个想法付诸实践的时候出现了很多问题，需要考虑的条件有太多了，所以为了寻找最优解，我开始了深思，又去学习了一些算法才回来解这个题，最后我选用了XOR算法，说白了就是异或的方式，且这个算法满足交换律，结合律，根据a^a=0,a^0=a,且有a^b^b=a^(b^b)=a,由此写下了一下代码

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        int temp=0;
        for(int i=0;i<nums.length;i++){
            temp^=nums[i];
        
        }
        return temp;
    }
}
```
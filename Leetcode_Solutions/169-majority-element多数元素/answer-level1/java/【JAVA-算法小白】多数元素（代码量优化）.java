### 解题思路
如代码中注解，在评论区找到的更好的解法，简化代码，比自己原版少了至少10行代码。

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        /**思路：第一个想到的是用HashMap来做，因为key值不允许重复，我修改value值来统计出现次数
         *HashMap 是一个散列表，它存储的内容是键值对(key-value)映射。
         *该类实现了Map接口，根据键的HashCode值存储数据，具有很快的访问速度，最多允许一条记录的键为null，不支持线程同步。
         *算法垃圾小白进化史。。。。。勿喷
         */

        /**
         *评论区看见一个大佬更好的实现，(比我的原版少了至少十行代码)附上链接： 
         *https://leetcode-cn.com/problems/majority-element/solution/ru-he-yong-kuai-pai-onjie-jue-di-kda-wen-ti-jian-d/
         */
        HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
        for(int i:nums)
        {
            map.put(i,map.getOrDefault(i,0)+1);
            if (map.get(i)>nums.length/2)   //这是我认为大佬设计最妙的地方，一个数超过规定的一半，直接return结束程序
                return i;
        }
        return 0;
    }
}
```
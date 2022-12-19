### 解题思路
只是为了熟悉HashMap用法，自己在项目中没用过HashMap，这个解法不仅暴力，而且耗时耗空间，但是对程序员感觉友好，，，，不烧脑。。。。。。

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        //思路：第一个想到的是用HashMap来做，因为key值不允许重复，我修改value值来统计出现次数
        //HashMap 是一个散列表，它存储的内容是键值对(key-value)映射。
        //该类实现了Map接口，根据键的HashCode值存储数据，具有很快的访问速度，最多允许一条记录的键为null，不支持线程同步。
        //算法垃圾小白进化史。。。。。勿喷
        HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++)
        {
            int key=0,times=0;
            key=nums[i];
            if (map.containsKey(key)){
                times=map.get(nums[i]);
                map.put(key,times+1);
            }else{
                map.put(key,1);
            }
        }
        for (Integer key:map.keySet()){
            if (map.get(key)>nums.length/2){
                return key;
            }
        }
        return 0;
    }
}
```
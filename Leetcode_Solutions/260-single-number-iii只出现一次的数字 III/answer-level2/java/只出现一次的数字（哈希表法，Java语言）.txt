### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] singleNumber(int[] nums) {
        //哈希表法
        int [] result=new int [2];
        int index=0;
        HashMap <Integer,Integer> map=new HashMap<>();
        for(int num:nums)
        {
            if(map.containsKey(num))
                map.put(num,map.get(num)+1);
            else
                map.put(num,1);
        }
        //从哈希表中将key存到集合中
        Set <Integer> keySet=map.keySet();
        for(int i:keySet)
        {
            if(map.get(i)==1)
                result[index++]=i;
        }
        return result;
    }
}
```
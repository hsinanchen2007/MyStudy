### 解题思路
错了好多次才发现,在计数器加一的时候我写的是times++，然后就一直没看出来。。。
还有就是有个问题，为何leetcode中没法用keyset()遍历key呢？想用keyset的时候似乎报错是can not find symbol

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int length=nums.length;
        int result=0;
        int times;
        Map<Integer, Integer> ele=new HashMap<Integer,Integer>();
        for(int i=0;i<length;i++){
            if(!ele.containsKey(nums[i])){
                ele.put(nums[i],1);
            }
            else{
                times=ele.get(nums[i]);
                ele.put(nums[i],times+1);//problem 1
            }
        }
        Map.Entry<Integer, Integer> max=null;
        for(Map.Entry<Integer, Integer> entry: ele.entrySet())
        {
         //System.out.println("Key: "+ entry.getKey()+ " Value: "+entry.getValue());
            if(max==null||entry.getValue()>max.getValue()){
                max=entry;
            }
        }
        return max.getKey();
    }
}
```
### 解题思路
虽然不是用二分法写的，但还是把它做出来了，让我这个菜鸟开心一下，hhhh

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        Map<Integer,Integer> map=new HashMap<Integer,Integer>();
        int[] result=new int[2];
        for(int i=0;i<numbers.length;i++)
        {
            if(map.containsKey(numbers[i]))
            {
                result[0]=map.get(numbers[i])+1;
                result[1]=i+1;
            }
            map.put(target-numbers[i],i);
        }
        return result;
    }
}
```
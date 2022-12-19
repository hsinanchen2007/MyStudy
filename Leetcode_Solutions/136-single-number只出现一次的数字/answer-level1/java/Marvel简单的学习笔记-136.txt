多种解法，逐步优化，值得回味的题。
### 解法一：哈希表
执行用时：14ms
内存消耗：40MB

代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer,Integer> map=new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++)
        {
            int key=nums[i];
            if(map.containsKey(key))    map.remove(key);
            else                        map.put(key,1);
        }
        for(int i : map.keySet())
            return i;
        return -1;//do not exist
    }
}
```
### 解法二：数学
执行用时：15ms
内存消耗：39MB

代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        int a=0,b=0;
        Set<Integer> set=new TreeSet<Integer>();
        for(int i=0;i<nums.length;i++)
        {
            a += nums[i];
            set.add(nums[i]);
        }
        for(int i : set)
            b += i;
        return 2*b-a;
    }
}
```
### 解法三：位运算（XOR按位异或）
执行用时：1ms
内存消耗：39MB

代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        int ans=0;
        for(int i : nums)
            ans=ans ^ i;
        return ans;
    }
}
```
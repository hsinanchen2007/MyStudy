## 第一种：全部放进set中，比较原数组与set集合的长度
```
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<Integer>();
		for(int i : nums) {
			set.add(i);
		}
		return nums.length > set.size() ? true : false ;
    }
}
```
这种方法的结果：
![image.png](https://pic.leetcode-cn.com/77c7d4114763bebbed7aae01bc9db6dd9ca39c06d0a843d8da371681c1e06cdd-image.png)

## 第二种：插入进set集合时判断是否有重复元素，如有直接返回
```
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>(nums.length);
        for (int x: nums) {
            if (set.contains(x)) return true;
            set.add(x);
        }
        return false;
    }
}
```
这种方法的结果：
![image.png](https://pic.leetcode-cn.com/61507b49a928527ef759118bfa1dcad862eb0e7024e62b781c8eca6cbde03822-image.png)
**想知道为什么第一种比第二种方式快**



### 解题思路
![1306.png](https://pic.leetcode-cn.com/c6231edf3c4909eefbfbcbeee2628908ef0ca87352ede75d0695290dacc29616-1306.png)
### 代码

```java
class Solution {
    HashSet<Integer> set = new HashSet<>() ;
    public boolean canReach(int[] arr, int start) {
        if(start < 0 || start >= arr.length) {   // 判断下标是否合法
    		return false ;
    	}
    	if(arr[start] == 0) {         // 找到target 返回true
    		return true ;
    	}else if(!set.add(start)) {   
    		return false ;			//表明当前位置已访问过，直接返回false
    	}
    	return canReach(arr,start+arr[start]) || canReach(arr,start-arr[start]) ;
    }
}
```
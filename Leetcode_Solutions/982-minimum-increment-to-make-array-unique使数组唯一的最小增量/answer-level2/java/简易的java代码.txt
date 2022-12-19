### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A){
		if(A.length == 1){
			return 0;
		}
		Arrays.sort(A);
		int count = 0;
		for(int i=1;i<A.length;i++){
			while(A[i]<=A[i-1]){
				A[i]++;
				count++;
			}
		}
		return count;
	}
}
```

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/8439667f163a80373e465fd0d8188a3f1534ca3ffed9f85dd97cd8c63f46bffc-wechat.png)

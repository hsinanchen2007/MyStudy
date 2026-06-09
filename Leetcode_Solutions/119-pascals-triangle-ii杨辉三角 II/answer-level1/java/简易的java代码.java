### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex){
		// 使用递归
		List<Integer> res = new ArrayList<>();
		if(rowIndex == -1){
			return res;
		}else if(rowIndex == 0){
			res.add(1);
			return res;
		}
		// 其它行：至少都包含左右两个元素“1”
		res.add(1);
		// 递归得到前一行的元素
		List<Integer> previous = getRow(rowIndex - 1);
		for(int i=0;i<previous.size()-1;i++){
			res.add(previous.get(i)+previous.get(i+1));
		}
		res.add(1);
		return res;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/5eb03c3b9a666cf3615eea4eb933620d16ace9100d98160e9569dda4ac40bcac-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/cbd63b8f99901a92c9fa4c15b00942a6f385253c7201b76e6eddbfd3214c9365-wechat.png)

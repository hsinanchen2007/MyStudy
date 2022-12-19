### 解题思路
循环list n-1次，依次删除每一个数字，最后一个是剩下的数字就是结果。

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
    	ArrayList<Integer> arrayList = new ArrayList<Integer>();
    	for (int i = 0; i < n; i++) {
    		arrayList.add(i);
		}
    	int i = m - 1;
    	while (arrayList.size() > 1) {
    		i %= arrayList.size();
    		arrayList.remove(i);
    		i += (m -1);
		}
    	return arrayList.get(0);
    }
}
```
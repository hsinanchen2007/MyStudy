### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        List<Integer> list = new ArrayList<Integer>();
		for(int i=0;i<n;i++) {
			list.add(i);
		}
		int index=0;
		int length = list.size();
		while(length!=1) {
			index=(index+(m-1))%(length--);
			list.remove(index);
		}
		return list.get(0);
    }
}



```
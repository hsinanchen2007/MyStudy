### 解题思路
此处撰写解题思路
把这些数放在列表里，不停地删掉，删掉的位置应该相对于上一次的位置再往前m-1个位置。
### 代码

```java
class Solution {
  public static int lastRemaining(int n, int m) {
	        List<Integer> l = new ArrayList<Integer>();
         int mid = 0;
	        for(int i=0;i<n;i++) {
	        	l.add(i);
	        }
	        while(l.size()>1) {
	        	int size = l.size();
	        	l.remove((mid+(m-1))%l.size());
	        	mid = (mid+(m-1))%size;
	        }
	        return l.remove(0);
	    }
}
```
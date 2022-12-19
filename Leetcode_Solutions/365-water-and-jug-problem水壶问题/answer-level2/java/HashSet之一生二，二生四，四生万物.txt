
![fd.jpg](https://pic.leetcode-cn.com/54265c346352098905bfda6e1af5dae4f3af03fa3e7dd46fb5282d1132ed0fcf-fd.jpg)

### 解题思路
### 一生二，二生四，四生万物

- **我的想法：x、y、x+y、|x-y|是四个基本数（去重后可能更少），若再更相递减能再获得一个不重复数（总数大于4个），说明由xy能获得的z范围是[1,x+y],否则z的值只能由四个基本数组合获得；**

- **按想法实现的算法通过了，效率不高，但是我好像不会证明这个东西**


- **看了官解，感觉我这个跟贝祖定理有点靠近...有可以证明我这个想法数学实现的大佬麻烦指教一下**



### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
		if (z == 0 || z == x || z == y) {
			return true;
		}
		if (z > (x + y)) {
			return false;
		}
		TreeSet<Integer> treeSet = new TreeSet<Integer>();
		int a = Math.abs(x + y);
		int b = Math.abs(x - y);
		int c = Math.abs(x - b);
		int d = Math.abs(y - b);
		treeSet.add(a);
		treeSet.add(b);
		treeSet.add(c);
		treeSet.add(d);
		treeSet.add(x);
		treeSet.add(y);
		treeSet.remove(0);
		int min = treeSet.first();
		int size = treeSet.size();
		if (size > 4) {
			return true;
		} else if (z < min) {
			return false;
		} else {
			Iterator<Integer> ite = treeSet.iterator();
			while (ite.hasNext()) {
				if (treeSet.contains(z - ite.next().intValue())) {
					return true;
				}
			}
			return false;
		}
    }
}
```
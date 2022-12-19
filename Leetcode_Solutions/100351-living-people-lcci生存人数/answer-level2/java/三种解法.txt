### 解题思路
先统计，再从统计记录中找最大值。

#### 1. 逐年统计某年生存人数

``` java
public int maxAliveYear(int[] birth, int[] death) {
	int[] alive = new int[101];
	for (int i = 0; i < alive.length; i++) {//记录:逐年统计
		for (int j = 0; j < birth.length; j++) {
			if(birth[j]<=1900+i && death[j]>=1900+i)
				alive[i]++;
		}
	}
	
	int ans=1900, maxAlive=alive[0];
	for (int i = 1; i < alive.length; i++) {//查记录
		if(alive[i]>maxAlive) {
			maxAlive=alive[i];
			ans = 1900+i;
		}
	}
	return ans;
}
```
#### 2. 逐人统计某年生存人数

相较逐年统计，逐人统计，避免了无效遍历。

``` java
public int maxAliveYear(int[] birth, int[] death) {
	int[] alive = new int[101];
	for (int i = 0; i < birth.length; i++) {//统计：逐人统计
		for (int j = birth[i]-1900; j <= death[i]-1900; j++) {
			alive[j]++;
		}
	}
	
	int ans=1900, maxAlive=alive[0];
	for (int i = 0; i < alive.length; i++) {//查记录
		if(alive[i]>maxAlive) {
			maxAlive=alive[i];
			ans = 1900+i;
		}
	}
	return ans;
}
```

#### 3. 逐人统计某年变化人数

相较于“**逐人统计某年生存人数**”，“**逐人统计某年变化人数**”不再针对某人在一个大的区间内记录一串值，而是只记录两个值。

```java
class Solution {
    public int maxAliveYear(int[] birth, int[] death) {
		int[] changes = new int[102];
		for (int i = 0; i < birth.length; i++) {//存记录
			changes[birth[i]-1900]++;
			changes[death[i]-1900+1]--;
		}
		
		int ans=0, maxAlive=0, currAlive = 0;
		for (int i = 0; i < changes.length; i++) {//查记录
			currAlive += changes[i];
			if(currAlive>maxAlive) {
				maxAlive=currAlive;
				ans = 1900+i;
			}
		}
		return ans;
    }
}
```
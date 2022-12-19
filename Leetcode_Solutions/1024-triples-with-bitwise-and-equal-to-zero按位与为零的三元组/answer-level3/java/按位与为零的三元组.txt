### 方法一： 暴力法（超时）

#### 思路：
我们可以暴力枚举所有可能三元组，然后判断它们是否满足按位与为0的条件，由于问题的规模最大为$n=1000$,该算法的时间复杂度为$O(N^3)$，毫无疑问会超时。

```java []
class Solution {
    public int countTriplets(int[] A) {
        int ans = 0, N = A.length;
        for (int i = 0; i < N; i++) {
        	for (int j = 0; j < N; j++) {
        		for (int k = 0; k < N; k++) {
        			int res = A[i] & A[j] & A[k];
        			if (res == 0) ans++;
        		}
        	}
        }
        return ans;
    }
}
```

### 方法二：哈希表（通过）

#### 思路：
注意到题目给出的条件$0 <= A[i] < 2^{16}$，根据$&$运算的性质，任意的$A[i]*A[j]$产生的结果必然小于$2^{16}$, 因此我们可以先计算出数组中任意两个数$&$运算的值，利用一个哈希表来统计这个值出现的频率。然后我们对于数组中的每一个数，我们遍历哈希表的键值（根据上述分析，我们知道键值集合的size最大不超过$2^{16}$），对于每一个和该数$&$运算为$0$的键值，我们可以得到$map[key]$个按位与为$0$的三元组。

#### 算法：

- 统计任意两个数与运算产生的结果值出现的频率
- 对数组中的每个数，统计哈希表中所有和其与运算为$0$的$key$所对应的值

```java []
class Solution {
    public int countTriplets(int[] A) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int ans = 0, N = A.length;

        for (int i = 0; i < N; i++) {
        	for (int j = 0; j < N; j++) {
        		int temp = A[i] & A[j];
        		map.put(temp, map.getOrDefault(temp, 0)+1);
        	}
        }
        for (int key : map.keySet()) {
            // 一个优化，当key = 0时，数组中任何值与其&运算结果均为0
            if (key == 0) {
                ans += map.get(key) * N;
                continue;
            }
            for (int i = 0; i < N; i++)
                if ((A[i] & key) == 0) ans += map.get(key);
        }
        
        return ans;
    }
}
```
#### 复杂度分析：
- 时间复杂度:$O(n^2)$
- 空间复杂度:$O(2^{16})$

#### 优化

由于哈希表的键值位于$[0, 2^{16})$区间中，我们可以利用数组来优化查找效率。

 
```java []
class Solution {
    public int countTriplets(int[] A) {
        int ans = 0;
        int[] map = new int[1<<16];
        for(int i = 0; i < A.length; i++){
            for(int j = 0; j < A.length; j++){
                map[A[i] & A[j]]++;
            }
        }
        
        for(int i = 0; i < map.length; i++){
            if(map[i] == 0) continue;
            for(int j = 0; j < A.length; j++){
                if((A[j] & i) == 0){
                    ans += map[i];
                }
            }
        }
        return ans;
    }
}
```


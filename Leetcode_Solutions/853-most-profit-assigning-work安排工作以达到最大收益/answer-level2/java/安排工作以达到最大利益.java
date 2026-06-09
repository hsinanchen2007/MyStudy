### 方法一：暴力法（超时）

#### 思路：
由于一个工作可以被完成多次，对于每一个工人，我们都为该工人挑选其能力范围内利润最大的工作。从而获得最大利益。

#### 算法：
- 遍历数组$difficulty$和$profit$，当于某个工人$k$，当$difficulty[i] < worker[k]$时，我们用$profit[i]$来更新这个工人所能提供的最大利润。

```java []
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int sum = 0, N = difficulty.length;
        for (int w : worker) {
            int p = 0;
            for (int i = 0; i < N; i++) {
                if (difficulty[i] > w) continue;
                p = Math.max(p, profit[i]);
            }
            sum += p;
        }
        return sum;
    }
}
```
#### 复杂度分析：
我们记$difficulty$数组的长度为$N$,$worker$数组的长度为$M$
- 时间复杂度:$O(M*N)$
- 空间复杂度:$O(1)$

### 方法二：排序&双指针（通过）

#### 思路：
在方法一中我们对于每一个工人，都要从头开始遍历整个$difficulty$和$profit$来寻找这个工人所能提供的最大利润，显然这种方式太低效了,让我们来寻找一种只需遍历一次的方法。
- 注意到一个事实，如果$worker[j] \geq worker[i]$，那么$worker_j$所能提供的最大利润必然也$\geq worker_i$,因为他至少可以选择和$worker_i$完成同样的工作，并在此基础上去尝试其他利润更高的工作。
- 我们将$work$（即一对关联的$difficulty$和$profit$)和$worker$**都按照**$difficulty$**升序排列**。并设置两个指针$idx1$和$idx2$初始时分别指向这两个数组的头部。
- 我们固定$idx2$来指向一个$worker$，同时不断的右移$idx1$来更新这个$worker$能得到最大的利润。当$idx1$指向的$work$的$difficulty$大于$worker[idx2]$或其走到了$work$数组的末尾，我们则找到了这个$worker$所能提供利润的最大值$maxVal$，**因为$work$数组按照每个$work$的$difficulty$升序排列，当前$idx1$指向的及以后的所有$work$的$difficulty$必大于$worker[idx2]$**。然后对于下一个$worker$，我们也无需将$idx1$移回数组头部重新开始遍历，因为$worker$数组也是按照$difficulty$升序排列，根据第一条的事实，此时得到$maxVal$也适用于$worker[idx2]$，我们只要继续右移$idx1$更新$maxVal$即可。
- 综上，数组经过排序后，只需要一次遍历即可获得结果，下面以`difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]`为例,给出图示。
- 
![WX20190823-105829@2x.png](https://pic.leetcode-cn.com/95b70503000717f841c64f3690bdb0da38026b5240698bef75542dc17f92a56e-WX20190823-105829@2x.png){:width=500}{:height=250}
- 
![11.png](https://pic.leetcode-cn.com/ef74b738af9aa7dc893c13a56784c4ca033480df6f94be9365b89b19cdad4082-11.png)
- 
![33.png](https://pic.leetcode-cn.com/fdede3c434b6f47c7ad9a76f1f814756ebe1985c568dd752b1a297e0102923fa-33.png)


#### 算法：
- 为了维护每个$difficulty$和其$profit$的对应关系，我们定义一个$work$类，并生成其数组。
- 先排序$works$数组和$worker$数组，进行预处理。
- 定义指针$idx1$指向$works$数组头部，$idx2$指向$worker$数组头部，不断移动$idx1$，更新$maxVal$,直到$work[idx1]$的$difficulty > worker[idx2]$。
- 更新结果变量$ans$，$idx2$右移一步选择一个新的工人，继续第二步的循环。
- 循环退出后，尚未安排工作的工人均可取得目前为止的最大利润$maxVal$，加入结果变量中。
```java []
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int N = difficulty.length;
        Work[] works = new Work[N];
        for (int i = 0; i < N; i++) 
        	works[i] = new Work(difficulty[i], profit[i]);
        // 按照difficulty升序排列
        Arrays.sort(works, (o1, o2) -> o1.difficulty - o2.difficulty);
        Arrays.sort(worker);

        int idx1 = 0, idx2 = 0, maxVal = 0, ans = 0;

        while (idx1 < works.length && idx2 < worker.length) {
        	if (works[idx1].difficulty <= worker[idx2]) {
        		maxVal = Math.max(maxVal, works[idx1].profit);
        		idx1++;
        	} else {
        		ans += maxVal;
        		idx2++;
        	}
        }
        // 剩余未安排工作的工人均可取得最大利润
        ans += (worker.length - idx2) * maxVal;
        return ans; 
    }
}
class Work {
	int difficulty;
	int profit;
	public Work(int difficulty, int profit) {
		this.difficulty = difficulty;
		this.profit = profit;
	}
}
```

#### 复杂度分析：
我们记$works$数组的长度为$N$，$woker$数组长度为$M$
- 时间复杂度：$O(NlogN + MlogM)$，排序时间复杂度为$O(NlogN + MlogM)$，遍历一次数组的时间复杂度为$O(N + M)$，我们选取其中较大者。
- 空间复杂度：$O(N)$
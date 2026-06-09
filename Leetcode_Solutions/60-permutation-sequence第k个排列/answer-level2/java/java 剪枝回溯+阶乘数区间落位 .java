1.这道题dfs可以做，只不过需要剪枝，判断第k个会是数字几开头，然后从那一位开始dfs
```java []
class Solution {
    int num = 1;
	String res;
	public String getPermutation(int n, int k) {
        //定义阶乘数组
		int[] factorial = new int[n + 1];
		factorial[0] = 1;
		for (int i = 1; i <= n; i++) {
			factorial[i] = factorial[i - 1] * i;
		}
        //定义首位经过多少次编号会改变，3的话是6/3=2；123，132这样
		int perNum = factorial[n] / n;
        //开头的数字
		int first=(k % perNum == 0) ? k / perNum : k / perNum + 1;
        //剩下的k
		int remain=k-(first-1)*perNum;
		dfs(n, remain, 1, new String(Integer.toString(first)));
		return res;
	}

	private void dfs(int n, int k, int index, String temp) {
		// TODO Auto-generated method stub
		if (index == n) {
			if (num == k) {
				res = new String(temp);
			}
			num++;
		}
		for (int i = 1; i <= n; i++) {
			if (temp.indexOf(Integer.toString(i)) != -1)
				continue;
			temp += Integer.toString(i);
			dfs(n, k, index + 1, temp);
			if (temp.length() > 1) {
				temp = temp.substring(0, temp.length() - 1);
			} else {
				temp = "";
			}

		}

	}
}
```
这样做游走在超时边缘，其实不需要排列，只需要计算每个位置出现的数字，拼出来就好了，因为每次计算都相当于n-1

```java []
class Solution {
  public String getPermutation(int n, int k) {
		String res="";
		int[] factorial = new int[n + 1];
		factorial[0] = 1;
		List<Integer> nums = new ArrayList<Integer>();
		nums.add(1);
		for (int i = 1; i <= n; i++) {
			factorial[i] = factorial[i - 1] * i;
			nums.add(i + 1);
		}
		while (n > 0) {
			int perNum = factorial[n] / n;
            //这次计算出的是每个数字将要出现的位置，去nums里找对应位置的数字，这一步是看着官方题解给的灵感，还是很巧妙的
			int first = (k % perNum == 0) ? k / perNum : k / perNum + 1;
			k = k > perNum ? k - (first - 1) * perNum : k;
			res+=Integer.toString(nums.get(first-1));
			nums.remove(first-1);
			n--;
		}
		return res;
	}
}
```

现在一看到这种排列就想dfs，一方面是想理解透了深度优先搜索，剪枝，和记忆表形式的动态规划，另一方面也是有些思维定势了，以后看到题目要仔细分析，在想解决办法。



**解题思路：**

1、由于皇后们是不能放在同一行的， 所以我们可以去掉“行”这个因素，即我第1次考虑把皇后放在第1行的某个位置， 第2次放的时候就不用去放在第一行了， 因为这样放皇后间是可以互相攻击的。
2、第2次我就考虑把皇后放在第2行的某个位置，第3次我考虑把皇后放在第3行的某个位置， 这样依次去递归。 每计算1行，递归一次，每次递归里面考虑n列， 即对每一行皇后有n个可能的位置可以放。
3、找到一个与前面行的皇后都不会互相攻击的位置， 然后再递归进入下一行。 找到一组可行解即可输出，然后程序回溯去找下一组可靠解。
4、我们用一个一维数组来表示相应行对应的列，比如c[i]=j表示， 第i行的皇后放在第j列。 
5、如果当前行是r，皇后放在哪一列呢？c[r]列。一共有n列，所以我们要让c[r]依次取第0列，第1列，第2列……一直到第n-1列， 每取一次我们就去考虑， 皇后放的位置会不会和前面已经放了的皇后有冲突。
6、怎样是有冲突呢？同行，同列，对角线。 由于已经不会同行了，所以不用考虑这一点。 同列：c[r]==c[j]; 同对角线有两种可能，即主对角线方向和副对角线方向。主对角线方向满足，行之差等于列之差：r-j==c[r]-c[j]; 副对角线方向满足， 行之差等于列之差的相反数：r-j==c[j]-c[r]。
7、只有满足了当前皇后和前面所有的皇后都不会互相攻击的时候，才能进入下一级递归。

**附上代码如下：**

```
class Solution {
	public List<List<String>> solveNQueens(int n)
	{
		List<List<String>> result = new ArrayList<>();
		
		int[] queen = new int[n];
		search(0, n, queen, result);
		
		return result;
	}
	
	private void search(int start, int n, int[] queen, List<List<String>> result)
	{
		if (n == 0)
		{
			int2List(queen, result);
			return;
		}
		
		for (int i = 0; i < queen.length; i++)
		{
			queen[start] = i;
			boolean flag = true;
			for (int j = 0; j < start; j++)
			{
				if (checkIsNotMatch(start, j, queen))
				{
					flag = false;
					break;
				}
			}
			
			if (flag)
			{
				search(start + 1, n - 1, queen, result);
			}
		}
	}
	
	private void int2List(int[] queen, List<List<String>> result)
	{
		List<String> list = new ArrayList<String>();
		
		for (int i = 0; i < queen.length; i++)
		{
			int num = queen[i];
			StringBuilder stringBuilder = new StringBuilder();
			for (int j = 0; j < queen.length; j++)
			{
				if (num == j)
				{
					stringBuilder.append("Q");
				}
				else
				{
					stringBuilder.append(".");
				}
			}
			list.add(stringBuilder.toString());
		}
		
		result.add(list);
	}
	
	private boolean checkIsNotMatch(int i, int j, int[] queen)
	{
		if (queen[i] == queen[j] || Math.abs(i - j) == Math.abs(queen[i] - queen[j])) { return true; }
		
		return false;
	}
}
```

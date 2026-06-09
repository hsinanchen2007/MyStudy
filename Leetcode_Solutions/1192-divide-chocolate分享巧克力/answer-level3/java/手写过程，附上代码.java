![TIM截图20191020184111.png](https://pic.leetcode-cn.com/d224eeb4c6c50e805cfca7f98d582734019229494486dd6e8e591a1da19cbdbe-TIM%E6%88%AA%E5%9B%BE20191020184111.png)
L是指一定能满足的，R是一定不能满足的，因为为结果一定是整数。这就相当于试结果，用二分法提高效率。
下面附上代码
```
class Solution {
	public int maximizeSweetness(int[] sweetness, int K) {
		int res=0;
		if (sweetness.length == K + 1)
        {
            Arrays.sort(sweetness);
            return sweetness[0];
        }
		int r = 0;
		for (int i : sweetness)
			r += i;
        if(K==0) return r;
		int l = 0;
		while (l + 1 < r) {
			int m = (l + r) / 2, cnt = 0, cuur = 0;
			for (int i : sweetness) {
				cuur += i;
				if (cuur >= m) {
					cnt++;
					cuur = 0;
				}
			}
			if(cuur>=m) cnt++;
			if(cnt<K+1) r=m;
			else 
			{
				l=m;
				res=m;
			}
		}
		return res;
	}
}
```

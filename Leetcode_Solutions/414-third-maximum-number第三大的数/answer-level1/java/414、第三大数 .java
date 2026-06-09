解题思路是：巧用快速排序算法，查找出最大的前三个数，然后进行判断是否存在第三大数，如果存在，则返回第三大数，否则返回最大的。
用时击败99.26%
```
class Solution {
    public int thirdMax(int[] nums) {
        int len = nums.length;
		int max1 = quickSelect(nums,0, len - 1, 1);
		if (len < 3) {
			return max1;
		}
		int count = 1;
		int max2 = quickSelect(nums,0, len - 1, 2);
		if (max1 > max2) {
			count++;
		}
		int i = 3;
		while (count < 3 && i <= len)
		{
			int tmp = quickSelect(nums,0, len - 1, i++);
			if (max2 > tmp) 
			{
				count++;
				max2 = tmp;
			}
		}
		if (count == 3) {
			return max2;
		}
		return max1;
    }

    public int quickSelect(int a[], int l, int r, int k) {
		Random rand = new Random();
		int p = rand.nextInt(r - l + 1) + l;
		int x = a[p];
		int tmp = a[p]; a[p] = a[r]; a[r] = tmp;
		int i = l, j = r;
		while(i < j)
		{
			while(i < j && a[i] > x) i++;
			if(i < j)
			{
				a[j] = a[i];
				 j--;
			}
			while(i < j && a[j] < x) j--;
			if(i < j)
			{
				a[i] = a[j];
				i++;
			}
		}
		a[i] = x;
		p = i;
		if(i - l + 1 == k) return a[i];
		if(i - l + 1 < k) return quickSelect(a,i+1,r,k-(i-l+1));
		else return quickSelect(a, l, i - 1, k);
	}
}
```

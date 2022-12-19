![捕获.PNG](https://pic.leetcode-cn.com/13f915aad7fd3f5c0f68a0a845ccd30f29d2e65b32ac68d85944830f0a95ab84-%E6%8D%95%E8%8E%B7.PNG)
简单的桶排序在这道题里面表现还不错！

public static int[] getLeastNumbers(int[] arr, int k) {
		 int tong[] = new int[10001];	 
		 int re[] = new int[k];
		 int j = 0;
		 for (int i = 0; i < arr.length; i++) {
			++tong[arr[i]];
		}
		for (int i = 0; i < re.length; i++) {
			while (0 == tong[j]) {
				++j;
			}
			re[i] = j;
			--tong[j];
		}
		 return re;
}

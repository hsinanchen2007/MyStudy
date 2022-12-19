- 参考评论某大佬的思路，如果不知道10000000到100000000之间没有素数，那么暴力解法是过不了的
```

#define MAX_SIZE (100)
#define TRUE     (1)
#define FALSE    (0)

int IsPrime(int N)
{
	int i;
	if (N < 2) {
		return FALSE;
	}
	if ((N == 2) || (N == 3)) {
		return TRUE;
	}
	for (i = 2; i * i <= N; i++) {
		if (N % i == 0) {
			return FALSE;
		}
	}
	return TRUE;
}

int IsPalindrome(int N)
{
	int left = 0;
	int right;
	char nums[MAX_SIZE];
	sprintf(nums, "%d", N);
	right = strlen(nums) - 1;
	while (left < right) {
		if (nums[left] != nums[right]) {
			return FALSE;
		}
		left++;
		right--;
	}
	return TRUE;
}

int primePalindrome(int N) 
{	
	int i = N;
	while (1) {
        if ((i > 10000000) && (i < 100000000)) {
			i = 100000000;
		}
		if (IsPrime(i) == FALSE) {
			i++;
			continue;
		}
		if (IsPalindrome(i) == FALSE) {
			i++;
			continue;
		}
		break;
	}
	return i;
}
```

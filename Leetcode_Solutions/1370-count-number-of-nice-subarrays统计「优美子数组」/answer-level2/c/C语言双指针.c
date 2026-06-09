```

int numberOfSubarrays(int* nums, int numsSize, int k){

	int n = 0;
	int *s = &(nums[0]);
	int *e = s;
	int sum = 0;
	int win = 0;
	int *end = &(nums[numsSize - 1]);

	while (e <= end) {
		if ((*e) % 2 != 0) {
			n++;
			if (n == k) {
				break;
			}
		}
		e++;
	}

	if (n != k) {
		return 0;
	}
	win = 1;
	while (s < e) {
		if ((*s) % 2 != 0) {
			break;	
		}
		win++;
		s++;
	}

	sum += win;
	e++;
	while (e <= end) {
		if ((*e) % 2 == 0) {
			sum += win;
		} else {
			win = 1;
			s++;
			while (s < e) {
				if ((*s) % 2 != 0) {
					break;	
				}
				s++;
				win++;
			}

			sum += win;
		}
		e++;
	}

	return sum;
}

```

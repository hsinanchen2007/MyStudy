int reverse(int x) {
	int ret = 0;
	while (x != 0) {
		ret += x % 10;
		x /= 10;
		if (x != 0) {
			if (ret > INT_MAX / 10 || ret < INT_MIN / 10)
				return 0;
			ret *= 10;
		}
	}
	return ret;	
}
    // 来回倒腾 得出的是一堆x与y线性组合的数（而且是所有线性组合的数都能得到），同时这些线性组合的数是gcd(x,y)的整数倍
    // 如果能倒腾出 z，z即x与y线性组合的数，z必定是gcd（x,y）的倍数
    public boolean canMeasureWater(int x, int y, int z) {
		if(x < y) {
			return canMeasureWater(y, x, z);
		}
		if(z == 0) {
			return true;
		}
		if(x + y < z) {
			return false;
		}
		int gcd = gcd(x, y);
		return z % gcd == 0;
	}

	public int gcd(int x, int y) {
		if(y == 0) {
			return x;
		}
		return x % y == 0 ? y : gcd(y, x % y);
    }
	
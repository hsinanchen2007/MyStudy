class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
		int sum = 0;
		for (int i = 0; i < A.size(); i++) {
			sum += A[i];
		}
		if (sum % 3 != 0) {
			return false;
		}
		int part = sum / 3;
		int i = 0, j = A.size() - 1, sumi = A[i], sumj = A[j];
		while (i < j-1 && (sumi != part || sumj != part)) {
			if (sumi != part) {
				sumi += A[++i];
			}
			if (sumj != part) {
				sumj += A[--j];
			}
		}
		if (i < j-1 && sumi == part && sumj == part) return true;
		return false;
	}
};
class Solution {
public:
	static bool searchMatrix(vector<vector<int>>& matrix, int target) {
		auto iRow = upper_bound(matrix.begin(), matrix.end(), vector<int>{target}, [&](auto& a, auto& b) {
			return !a.empty() && !b.empty() && a[0] < b[0];
			});
		if (iRow == matrix.begin()) {
			return false;
		}
		--iRow;
		auto iCol = lower_bound(iRow->begin(), iRow->end(), target);
		if (iCol == iRow->end()) {
			return false;
		}
		return *iCol == target;
	}
};
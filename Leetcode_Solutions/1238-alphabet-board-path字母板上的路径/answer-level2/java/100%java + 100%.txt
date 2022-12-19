要先按左 上 下 右
```
class Solution {

	public String alphabetBoardPath(String target) {
		int x = 0, y = 0, nx = 0, ny = 0;
		StringBuffer ans = new StringBuffer("");
		for (int i = 0; i < target.length(); i++) {
			int temp = target.charAt(i) - 'a' ;
			if (i > 0 && target.charAt(i) == target.charAt(i - 1)) {
				ans.append("!");
			} else {
				nx = temp / 5;
				ny = temp % 5;
				if (ny < y) {
					for (int z = 0; z < y - ny; z++)
						ans.append("L");
				}
				if (nx < x) {
					for (int z = 0; z < x - nx; z++)
						ans.append("U");
				}
				if (nx > x) {
					for (int z = 0; z < nx - x; z++)
						ans.append("D");
				}
				if (ny > y) {
					for (int z = 0; z < ny - y; z++)
						ans.append("R");
				}
				
				ans.append("!");
				x = nx;
				y = ny;
				
			}
		}
		return ans.toString();
	}
}
```
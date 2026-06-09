```java
class Solution {
    public int numJewelsInStones(String J, String S) {
		// 分割
		String[] gemstone = J.split("");
		String[] stone = S.split("");
		int count=0;
		for (int i = 0; i < gemstone.length; i++) {
			for (int k = 0; k < stone.length; k++) {
				if (gemstone[i].equals(stone[k])) {
					count++;
				}
			}
		}
		return count;       
    }
}

class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        if (m==0 || m==n) {
			return m;
		}
		int resultM = (int)Math.floor(Math.log(m)/Math.log(2));
		int resultN = (int)Math.floor(Math.log(n)/Math.log(2));
		
		if (resultM == resultN) {
            int result = (int)Math.pow(2, resultM);
			return result + rangeBitwiseAnd(m-result, n-result);
		}else {
			return 0;
		}
    }
}
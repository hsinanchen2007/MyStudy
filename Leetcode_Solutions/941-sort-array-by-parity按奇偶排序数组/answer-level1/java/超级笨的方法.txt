class Solution {
    public int[] sortArrayByParity(int[] A) {
         ArrayList<Integer> arrayList = new ArrayList<Integer>();
	        for (int i = 0; i < A.length; i++) {
				if (A[i] % 2 == 0) {
					arrayList.add(A[i]);
				}
			}
	        for (int i = 0; i < A.length; i++) {
				if (A[i] % 2 == 1) {
					arrayList.add(A[i]);
				}
			}
	        int p = 0;
	        for (Integer integer : arrayList) {
				A[p] = arrayList.get(p);
				p++;
			}
	        return A;
    }
}
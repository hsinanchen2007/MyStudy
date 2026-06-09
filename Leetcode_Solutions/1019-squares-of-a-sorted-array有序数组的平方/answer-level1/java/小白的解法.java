思路：先算出数组中每个元素的平方，然后使用Arrays的sort方法，时间复杂度为O(N).
class Solution {
    public int[] sortedSquares(int[] A) {
        for(int i=0;i<A.length;i++){
            A[i]=A[i]*A[i];
        }
        Arrays.sort(A);
        return A;
    }
}
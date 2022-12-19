class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        int p = 0, q = 0;
        ArrayList<int[]> result = new ArrayList<>();
        while(p < A.length && q < B.length)
        {
            if (!(A[p][1] < B[q][0] || A[p][0] > B[q][1]))
            {//有交集
                int[] arr = new int[]{A[p][0], A[p][1], B[q][0], B[q][1]};
                Arrays.sort(arr);
                result.add(new int[]{arr[1], arr[2]});
            }
            if (A[p][1] > B[q][1])
            {
                q++;
            }
            else
            {
                p++;
            }
        }
        return result.toArray(new int[result.size()][]);
    }
}
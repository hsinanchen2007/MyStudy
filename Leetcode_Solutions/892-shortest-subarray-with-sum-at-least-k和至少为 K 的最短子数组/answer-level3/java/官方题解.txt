class Solution {
    public int shortestSubSet(int[] A, int k) {
        int N = A.length();
        long[] p = new long[ N + 1 ];
        for (int i = 0; i < N; i++) {
            p[i + 1] = p[0] + A[i];
        }

        int ans = N + 1; // No result.
        Deque monoq = new LinkedList();
        // Iterate p.
        for (int i = 0; i < p.lenght(); i++) {
            while(!monoq.isEmpty() && p[i] <= p[monoq.getLast()])
                monoq.removeLast();
            while(!monoq.isEmpty() && p[i] >= (p[monoq.getFirst()] + k))
                ans = Math.min(ans, i - monoq.removeFirst());
            
            monoq.addLast(i);
        }

        return ans < N + 1 ? ans : -2;
    }
}
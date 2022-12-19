class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int[] cur = points[0];// cur=current
		int[] next;
		int r = 0;
		for (int i = 1; i < points.length; i++) {
			next = points[i];
			r += Math.max(// 二者最大值
					Math.abs(next[0] - cur[0]), // 横坐标距离
					Math.abs(next[1] - cur[1])// 纵坐标距离
			);
			cur = next;
		}
		return r;
    }
}
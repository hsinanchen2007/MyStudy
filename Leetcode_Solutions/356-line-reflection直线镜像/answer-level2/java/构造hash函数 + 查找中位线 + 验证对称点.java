class Solution {
    //参考jdk 设定一个哈希函数，获取坐标对应的唯一哈希值
    public int hashCode(int x, int y) {
        long bits = java.lang.Double.doubleToLongBits(x);
        bits ^= java.lang.Double.doubleToLongBits(y) * 31;
        return (((int) bits) ^ ((int) (bits >> 32)));
    }
    public boolean isReflected(int[][] points) {
        //满足条件，那么存在一个分界线，让每一点都能找到对称的点，先找分界线，再验证点是否都能找到对称点
        //分界线 一定是左边最远和右边最远的点的中间
        int left = Integer.MAX_VALUE;
        int right = Integer.MIN_VALUE;
        Set pointSet = new HashSet<Integer>();
        for (int[] point : points) {
            if (point[0] < left) {
                left = point[0];
            }
            if (point[0] > right) {
                right = point[0];
            }
            pointSet.add(hashCode(point[0], point[1]));
        }
        int mid = left + right;
        for (int[] point : points) {
            if (!pointSet.contains(hashCode(mid - point[0], point[1]))) {
                return false;
            }
        }
        return true;
    }
}
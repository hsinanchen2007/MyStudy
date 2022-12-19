public class Subject009 {

    public static void main(String[] args) {

        Subject009 subject009 = new Subject009();

        int p1[] = {0,0};
        int p2[] = {1,1};
        int p3[] = {1,0};
        int p4[] = {0,1};

        System.out.println(subject009.validSquare(p1, p2, p3, p4));
    }

    /**
     *  按 x、y排序，然就计算四个边长相等且对角线相等即可判断为正方形且不存在为0的边长和对角线
     * @param p1
     * @param p2
     * @param p3
     * @param p4
     * @return
     */
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {

        int[][] point = {p1,p2,p3,p4};
        Arrays.sort(point,(a1,a2) -> (a1[0] == a2[0])? (a1[1] - a2[1]):(a1[0] - a2[0]));
        return distance(point[0],point[1])!=0
                && (distance(point[0],point[1]) == distance(point[1],point[3]))
                && (distance(point[1],point[3]) == distance(point[3],point[2]))
                && (distance(point[0],point[1]) == distance(point[0],point[2]))
                && (distance(point[0],point[3]) == distance(point[1],point[2]))
                ;
    }

    /**
     * 计算距离，这里不进行开方操作（避免出现小数）
     * @param a1
     * @param a2
     * @return
     */
    public long distance(int[] a1,int[] a2){
        int x = a1[0] - a2[0];
        int y = a1[1] - a2[1];

        long dist = x*x + y*y;
        return dist;
    }
}
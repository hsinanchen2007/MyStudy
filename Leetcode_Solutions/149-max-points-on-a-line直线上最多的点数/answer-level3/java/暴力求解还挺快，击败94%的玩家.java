    // 思路是先确定当前竖线的所有点，再暴力求解该直线右侧所有点连接直线某一点的直线长度
    // 该竖线都找完了，竖线右移
    class Solution {
        // 暴力求解
        public int maxPoints(int[][] points) {
            int len = points.length;
            if(len <= 2) {
                return len;
            }
            // 按横坐标排序
            for(int end = len - 1;end > 0;end--) {
                for(int j = 0;j < end;j++) {
                    if(points[j][0] > points[j + 1][0]) {
                        int[] temp = points[j];
                        points[j] = points[j + 1];
                        points[j + 1] = temp;
                    }
                }
            }

            int res = 2;    // 多于2个点的，肯定有两个点在一条直线上
            int left = 0;
            int right = 0;
            while(left < len) {
                // 先标出同一列的点的两端
                while(right < len && points[right][0] == points[left][0]) {right++;}
                res = Math.max(res, right - left);        // 按列看最长
                // 从右侧依次判断和该点相连的直线长度
                for(int i = left;i < right;i++) {
                    for(int j = len - 1;j >= right;j--) {
                        // 刚开始用求斜率double，但精度不够，换成BigDecimal不太划算
                        // 还是变相的用乘法吧
                        long up = points[j][1] - points[i][1];
                        long down = points[j][0] - points[i][0];
                        int count = 2;
                        for(int z = j - 1;z >= right;z--) {
                            long c_up = points[z][1] - points[i][1];
                            long c_down = points[z][0] - points[i][0];
                            if(up * c_down == down * c_up) {
                                count++;
                            }
                        }
                        // 处理左边left到right内相同的点
                        // 如(0,0)(0,0)(1,1)这就是三点在一条直线上
                        for(int z = left;z < right;z++) {
                            if(points[z][0] == points[i][0] && points[z][1] == points[i][1]) {
                                count++;
                            }
                        }
                        res = Math.max(res, count - 1);   // count再剪掉自身重复的
                    }
                }
                // 再找下一条竖线上的所有点
                left = right;
            }
            return res;
        }
    }
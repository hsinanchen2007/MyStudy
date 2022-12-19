思路：根据元素坐标可以判断下一个元素的坐标
图片不好画啊，有没有推荐的画图工具？
代码：
`
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        if(n == 0){
            return result;
        }
        int vCenter = n % 2 == 1 ? (n + 1) / 2 : n / 2;
        int hCenter = n % 2 == 1 ? (n + 1) / 2 : n / 2 + 1;
        move1(0,0,n,result,vCenter,hCenter, 1);
        return result;
    }

    private void move1(int x, int y, int n, int[][] arr, int vCenter, int hCenter, int count){
        arr[y][x] = count;
        count ++;
        if((y + 1) <= vCenter && y <= (x + 1) && (n - x - 1) > y){
            //右边移动一格
            move1(x + 1, y, n, arr, vCenter, hCenter, count);
        }
        if((y + 1) > vCenter && (n - x) >= (n - y) && x > (n - y - 1)){
            //左移动一格
            move1(x - 1, y, n, arr, vCenter, hCenter, count);
        }
        if((x + 1) < hCenter && (x + 1) < y && (n - y - 1) >= x){
            //上移动一格
            move1(x, y - 1, n, arr, vCenter, hCenter, count);
        }
        if((x + 1) >= hCenter && (n - x - 1) <= y && (n - x) < (n - y)){
            //下移动一格
            move1(x, y + 1, n, arr, vCenter, hCenter, count);
        }
    }
`
    public int minTimeToVisitAllPoints(int[][] points) {
         // 1.  判断相邻点 同x或者同y
         // 2.  三角形原理  a + b > c  (找目标点下方的点 继续向上走)
         int start =  0, times = points.length - 1, total = 0;
         int[] thisPoint , nextPoint;
         int thisX =  0, thisY = 0, nextX = 0, nextY, stepX = 0, stepY = 0;
         while (start < times) {
             thisPoint = points[start];
             nextPoint = points[start + 1];
             thisX = thisPoint[0];
             thisY = thisPoint[1];
             nextX = nextPoint[0];
             nextY = nextPoint[1];
             stepX = 0; // x方向
             stepY = 0; // y方向
            if (nextX > thisX ) {
                stepX = 1;
            } else if (nextX < thisX ) {
                stepX = -1;
            }
            if (nextY > thisY ) {
                stepY = 1;
            } else if (nextY < thisY ) {
                stepY = -1;
            }

            // 直角三角形斜边还未穿过目标x轴或y轴时
            while (thisX != nextX &&  thisY != nextY) {
                thisX += stepX;
                thisY += stepY;
                total += 1;
            }
            //  xy方向移动
            total += (Math.abs(thisX - nextX) + Math.abs(thisY - nextY));
            ++start;
        }
        return  total;
    }
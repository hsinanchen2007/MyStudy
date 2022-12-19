很简单的原理：
1、若终点和起点坐标一致，则返回true；
2、若终点不一致，此时判断起点与终点的方向关系：
（1）不一致，则一定可以在有限次执行指令后回到原点，返回true；
（2）一致，则无限远离起点，返回false；
```java
class Solution {
    public boolean isRobotBounded(String instructions) {
        Point p = new Point(0,0,0);
        for(int i=0; i<instructions.length(); i++) {
            p.move(instructions.charAt(i));
        }
        if (p.getX()==0 && p.getY()==0) {
            return true;
        }else if (p.getDerec() == 0) {
            return false;
        }
        return true;
    }
}

class Point {
    private int x;
    private int y;
    private int derec;//方向
    public Point(int x, int y, int derec) {
        this.x = x;
        this.y = y;
        this.derec = derec;
    }
    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }
    public void setDerec(int derec) {
        this.derec = derec;
    }
    public int getX() {
        return this.x;
    }
    public int getY() {
        return this.y;
    }
    public int getDerec() {
        return this.derec;
    }
    public void move(char c) {
        if (c == 'L') {
            derec=(derec+1)%4;//左转
        }else if (c == 'R') {
            derec = (derec+3)%4;//右转
        }else if (c == 'G') {
            switch (derec) {//在不同方向下前进一步的坐标变化
                case 0: this.x++;break;
                case 1: this.y++;break;
                case 2: this.x--;break;
                case 3: this.y--;break;
            }
        }
    }
}
```
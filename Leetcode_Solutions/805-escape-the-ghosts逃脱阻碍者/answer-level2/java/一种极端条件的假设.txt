我的思路是一种比较正常的思路
大家一块往终点走，如果我比所有ghost走过的距离都小，那么我就逃脱;
如果某个ghost先于我到达，那么我就一定会被这个ghost拦截(最差条件是这个ghost在target处等我)
举个例子
(1)比如我的目的地是[0,8],有一个ghost在[1,0]，我到target的距离是8，而ghost到target的距离是9，所以这个ghost永远在我后面;
(2)比如我的目的地是[0,8],有一个ghost在[1,8]，那么无论如何，只要我想到达重点，一定会被ghost拦截
代码如下：
```
    public boolean escapeGhosts(int[][] ghosts, int[] target) {

        int minSteps = Math.abs(target[0]) + Math.abs(target[1]);

        for(int[] ghost : ghosts){
            int curStep = Math.abs(ghost[0] - target[0]) + Math.abs(ghost[1] - target[1]);
            if(curStep <= minSteps) return false;
        }

        return true;
    }
```


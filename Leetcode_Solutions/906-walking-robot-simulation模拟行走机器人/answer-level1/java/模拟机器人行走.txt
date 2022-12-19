简单来说，首先存储障碍物的情况，使用两个map来存，空间换时间
然后依次运行指令。质量分两类：变换方向类和前进操作，分开考虑。
方向变换我通过两个变量来做，很简单的。
主要是方位变换，你要考虑是前进还是后退，考虑道路上有没有障碍物就好，第一次写题解，大家多多包涵
```
    public int robotSim(int[] commands, int[][] obstacles) {
        Map<Integer,List<Integer>> mapx = new HashMap<>(),mapy = new HashMap<>();
        if(obstacles.length!=0){
            for(int i=0;i<obstacles.length;i++){
                if(!mapx.containsKey(obstacles[i][0])){
                    List<Integer> l1 = new ArrayList<>();
                    l1.add(obstacles[i][1]);
                    mapx.put(obstacles[i][0],l1);
                }else{
                    mapx.get(obstacles[i][0]).add(obstacles[i][1]);
                }
                if(!mapy.containsKey(obstacles[i][1])){
                    List<Integer> l2 = new ArrayList<>();
                    l2.add(obstacles[i][0]);
                    mapy.put(obstacles[i][1],l2);
                }else{
                    mapy.get(obstacles[i][1]).add(obstacles[i][0]);
                }
            }
        }
        int x=0,y=0,dy=1,dx=0,max=0;
        for(int i=0;i<commands.length;i++){
            if(commands[i]==-1){
                if(dy!=0){
                    dx=dy;dy=0;
                }else{
                    dy = -dx;dx=0;
                }
            }else if(commands[i]==-2){
                if(dy!=0){
                    dx=-dy;dy=0;
                }else{
                    dy=dx;dx=0;
                }
            }else{
                if(mapx.size()==0){
                    x+=dx*commands[i];
                    y+=dy*commands[i];
                }else{
                    //沿x方向走
                    if(dx!=0){
                        int xx = x+dx*commands[i],flag=0;
                        if(mapy.containsKey(y)){
                            Collections.sort(mapy.get(y));
                            for(int xxx:mapy.get(y)){
                                if(xxx>x&&xxx<=xx){
                                    x = xxx-1;
                                    flag=1;
                                    break;
                                }else if(xxx>=xx&&xxx<x){
                                    x = xxx+1;
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==0)
                                x=xx;
                        }else{
                            x=xx;
                        }
                    }else{//沿y方向走
                        int yy = y+dy*commands[i],flag=0;
                        if(mapx.containsKey(x)){
                            Collections.sort(mapx.get(x));
                            for(int yyy:mapx.get(x)){
                                if(yyy>y&&yyy<=yy){
                                    y = yyy-1;
                                    flag=1;
                                    break;
                                }else if(yyy>=yy&&yyy<y){
                                    y = yyy+1;
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==0)
                                y=yy;
                        }else
                            y=yy;
                    }
                }
                max = Math.max(x*x+y*y,max);
            }
        }
        return max;
    }
```

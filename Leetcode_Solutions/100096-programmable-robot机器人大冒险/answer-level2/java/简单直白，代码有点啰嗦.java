class Solution {
     public boolean robot(String command, int[][] obstacles, int x, int y) {
        int numR = 0;
        int numU = 0;
        char currChar ;
        //计算U R的个数
        for(int i=0;i<command.length();i++){
            currChar = command.charAt(i);
            if('U' == currChar){
                numU++;
            }else {
                numR++;
            }
        }

        boolean checkRes = checkOnLine(new int[]{x,y},command,numU,numR);
        //不能到达终点，直接返回
        if(!checkRes){
            return checkRes;
        }
         boolean result = true;
        //如果有阻碍点，则进行循环判断，没有就直接返回true
        if(obstacles!=null && obstacles.length>0){

            for(int i=0;i<obstacles.length;i++){
                if(obstacles[i][0] > x || obstacles[i][1] > y ){//点越界，不校验
                    continue;
                }else{
                    //判断是否在轨迹路径上
                    checkRes = checkOnLine(obstacles[i],command,numU,numR);
                    if(checkRes){
                        result = false;
                        break;
                    }
                }
            }
        }

        return result;

    }

    public static boolean checkOnLine(int[] loc,String command,int numU,int numR){
        int step = (loc[0]+loc[1])/command.length() ;
        int currY = step * numU;
        int currX = step * numR;
        if(currX == loc[0] && currY == loc[1]){
            return true;
        }
        char currChar ;
        boolean result = true;
        for(int i=0;i<command.length();i++){
            if(currX>loc[0] || currY>loc[1]){
                result = false;
                break;
            }else if(currX==loc[0] && currY==loc[1]){
                result = true;
                break;
            }
            currChar = command.charAt(i);
            if('U' == currChar){
                currY++;
            }else {
                currX++;
            }
        }
        return result;
    }

}
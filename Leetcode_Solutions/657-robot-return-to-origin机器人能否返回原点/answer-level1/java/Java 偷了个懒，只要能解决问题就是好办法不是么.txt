![image.png](https://pic.leetcode-cn.com/f35a6d0917b3661395b937f2973e857ebea100bc1b3d9ca8e976d52ba1353e90-image.png)

class Solution {
    public boolean judgeCircle(String moves) {
        char[] moveSteps = moves.toCharArray();
        int location = 0;
        for(char step : moveSteps){
            switch (step){
                case 'R' :
                    location++;
                    break;
                case 'L' :
                    location--;
                    break;
                case 'U' :
                    location+=10;
                    break;
                case 'D' :
                    location-=10;
                    break;
            } 
                
        }
        if(location==0){
            return true;
        }
        return false;
    }
}
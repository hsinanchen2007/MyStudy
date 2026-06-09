无非运行完一次之后，有以下情况：
1.位移不为0，方向为北，一直位移离开，false
2.其它，至多四次后形成环，true

class Solution {
    public static boolean isRobotBounded(String instructions) {
        int pos_x=0,pos_y=0,dir=0;
        for(int i=0;i<=instructions.length()-1;i++) {
        	if(instructions.charAt(i)=='G') {
        		if(dir==0) pos_y++;
        		if(dir==1) pos_x++;
        		if(dir==2) pos_y--;
        		if(dir==3) pos_x--;
        	}else if(instructions.charAt(i)=='L')
        		dir=(dir+3)%4;
        	else
        		dir=(dir+1)%4;
        }
        if(dir==0 && (pos_x!=0 ||pos_y!=0))
        	return false;
        else
        	return true;
        
    }
}
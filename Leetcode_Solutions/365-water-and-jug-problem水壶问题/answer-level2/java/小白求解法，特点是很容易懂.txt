class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(z==0) return true;

        if(x+y<z) return false;

        if((x+y==z)&&(x==0||y==0))return true;

        if((x+y>z)&&(x==0||y==0))return false;
        //求解最大公约数
        int i = Math.min(x,y);
        while((x%i!=0)||(y%i!=0))
		{
			i--;
		}

        if(i==1)return true;
        else return z%i==0;

    }
}
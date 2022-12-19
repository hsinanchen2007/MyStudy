class Solution {
 public boolean canMeasureWater(int x, int y, int z) {
 if(x==0&&y==0) return z==0;
    if(z>x+y) return false;
    	int k =a(x,y);
        return z%k==0;
    }

	private int a(int x, int y) {
		// TODO Auto-generated method stub
		if(y==0) {
			return x;
		}
		return a(y,x%y);
	}
}
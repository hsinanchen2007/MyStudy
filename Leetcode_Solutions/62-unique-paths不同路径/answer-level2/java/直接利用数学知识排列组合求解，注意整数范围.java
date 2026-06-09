![image.png](https://pic.leetcode-cn.com/aa52e41824f424392989a2b6ab3723f355536c8cbf1ce9ce627ff6e634f71001-image.png)
class Solution {
        public  int uniquePaths(int m, int n) {
        //数学公式
        double down=n-1;
        double right=m-1;
        if(right>down) {
        	Double ans=new Double(jiecheng(down+right,right)/(jiecheng(down,0)));
        	return ans.intValue();
        }else {
        	Double ans=new Double(jiecheng(down+right,down)/(jiecheng(right,0)));
        	return ans.intValue();
		}
    }
    //计算阶乘到多少的函数
    public  double jiecheng(double i,double low){
        if(i==0){
            return 1.0;
        }
        double ans=1.0;
        for(double j=i;j>low;j--){
            ans*=j;
        }
        return ans;
    }
}
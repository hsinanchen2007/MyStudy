// ### 代码

// ```java

//又想复杂了，最大值问题只求经过，不求全求。
//本人的时间复杂度为0(nlogn)的方法：
class Solution {
    public class Heipos{
        int height;
        int position;
        public Heipos(int height,int position){
            this.height=height;
            this.position=position;
        }
    }
    static Comparator<Heipos> cmp = new Comparator<Heipos>() {
        public int compare(Heipos e1, Heipos e2) {
            return e1.height - e2.height;
        }
    };
    public int maxArea(int[] height) {
        int left=0;
        int right=height.length-1;
        int max=0;
        int currentheight,currentposition;
        boolean[] exist = new boolean[height.length];
        Queue<Heipos> q = new PriorityQueue<>(cmp);
        for(int i=0;i<height.length;i++){
            q.add(new Heipos(height[i],i));
            exist[i]=true;
        }
        while(q.size()>1)
        {
            currentheight=q.peek().height;
            currentposition=q.poll().position;
            exist[currentposition]=false;
            if(max<currentheight*Math.abs(currentposition-left))
                max=currentheight*Math.abs(currentposition-left);
            if(max<currentheight*Math.abs(currentposition-right))
                max=currentheight*Math.abs(currentposition-right);
            left=findleft(exist,left);
            right=findright(exist,right);
        }
        return max;
    }

    int findleft(boolean[] exist,int left)
    {
        for(int i=left;i<exist.length;i++)
        {
            if(exist[i]==true)
                return i;
        }
        return exist.length-1;
    }

    int findright(boolean[] exist,int right)
    {
        for(int i=right;i>=0;i--)
        {
            if(exist[i]==true)
                return i;
        }
        return 0;
    }
}

/*大佬的0(n)方法：转载自【望雪有感】
	public int maxArea(int[] a) {
		 int max = 0;
		 for(int i = 0, j = a.length - 1; i < j ; ){
			 int minHeight = a[i] < a[j] ? a[i ++] : a[j --];
			 max = Math.max(max, (j - i + 1) * minHeight);
		 }
		 return max;
	 }
     //右高左低，则弱右边的左移，则剩下的不可能有比原来的大的，只能左边的右移
     //如果两边一样高，则都往中间移以下，因为只移一边只会比原来小
     //👆或者移动任意一个也可以
*/
// ```
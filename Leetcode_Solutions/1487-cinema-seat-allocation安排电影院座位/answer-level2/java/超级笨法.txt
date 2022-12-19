```
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        int ans=0;
        int free=n;
        Arrays.sort(reservedSeats,new Comparator<int[]>() {
				public int compare(int[] o1, int[] o2) {
					return o1[0]-o2[0];
				}
			});
        int p=0;
        for(int i=0;i<reservedSeats.length;i+=p)//循环遍历订单数组，把座位号逐行收集，最后装成List送去getNum进行判断，
        {   p=0;
            free--;//没有订单的行就-1；
            int index=reservedSeats[i][0];// System.out.println(index);   
            ArrayList<Integer>a2=new ArrayList<Integer>();
            while(i+p<reservedSeats.length&&reservedSeats[i+p][0]==index)
            {   System.out.println(reservedSeats[i+p][1]);
                a2.add(reservedSeats[i+p][1]);
                p++;
            } 
         ans+=getNum(a2);
          System.out.println("`11111");
            
        }
    
     
      return  ans+free*2;
        
        

    }
    int getNum(ArrayList<Integer> a1){//判断该行有几个可坐的座位
        int flag=0; int ans=0;
        for(int j=2;j<=6;j+=2)
        {int i=0;
            for(;i<4;i++)
            {
                if(a1.contains(i+j))
                    break;
            }
            if(i==4)
            {
                if(j==2)
                {
                    ans++;
                    flag=2;
                }
                if(j==4&&flag==0)
                {       flag=1;
                        ans++;
                }
                if(j==6&&flag!=1)
                {
                        ans++;
                }
                
            }
         
        }
        return ans;
    }
}
```

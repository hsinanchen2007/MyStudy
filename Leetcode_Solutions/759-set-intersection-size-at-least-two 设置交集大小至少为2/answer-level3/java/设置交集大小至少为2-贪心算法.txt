### 解题思路
此处撰写解题思路

### 代码

```java
//本人的笨方法，时间复杂度为O(m²n),其中m为interval.length，n为整数区间的平均长度。

class Solution {
    private class Interval{
        int left;
        int right;
        int nownum;
        int num1;
        int num2;
        int i;
        public Interval()
        {
            super();
        }
        public Interval(Interval interval)
        {
            super();
            this.left=interval.left;
            this.right=interval.right;
            this.nownum=interval.nownum;
            this.num1=interval.num1;
            this.num2=interval.num2;
            this.i=interval.i;
        }
    }
    static Comparator<Interval> cmp = new Comparator<Interval>(){//比较器
        public int compare(Interval in1,Interval in2)
        {
            return in1.right-in2.right;                  //升序
        }
    };
    public int intersectionSizeTwo(int[][] intervals) {
        int length = intervals.length;
        Interval[] interval = new Interval[length];//创建对象数组的方法
        Queue<Interval> q = new PriorityQueue<>(cmp); 
        for(int i=0;i<length;i++)
        {
            interval[i]=new Interval();              //这里还要new以下↑
            interval[i].left=intervals[i][0];
            interval[i].right=intervals[i][1];
            interval[i].i=i;
            interval[i].nownum=0;
            q.add(new Interval(interval[i]));
        }
        int[] S = new int[2*intervals.length];
        int Snum=0;
        int presenti;
        for(;q.isEmpty()==false;)
        {
            presenti=q.poll().i;            
            if(interval[presenti].nownum<2)
            {
                for(int j=interval[presenti].right;j>=interval[presenti].left&&interval[presenti].nownum<2;j--)
                {
                    boolean flag = false;
                    for(int k=0;k<Snum;k++)
                    {
                        if(S[k]==j)
                        {
                            flag=true;
                            break;
                        }                           
                    }
                    if(flag==false)
                    {
                        S[Snum]=j;
                        Snum++;
                        insert1(interval,j,length);
                    }
                }
            }
        }
        return Snum;
    }
    public void insert1(Interval[] interval,int j,int length)
    {
        for(int i=0;i<length;i++)
        {
        	if(j<=interval[i].right&&j>=interval[i].left)
        	{
        		if(interval[i].nownum==0)
        		{
        			interval[i].num1=j;
        			interval[i].nownum++;
        		}
        		else
        		{
        			if(interval[i].num1!=j&&interval[i].nownum==1)
        			{
        				interval[i].num2=j;
        				interval[i].nownum++;
        			}                
        		}        		
        	}           
        }
    }
}

//大佬的解题方法，来自【liet.start】贪心算法，只看S[]中最右边两个数
/*
   public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[1]==o2[1]){
                    return o2[0]-o1[0];
                }
                return o1[1]-o2[1];
            }
        });
//解释：弹出的区间按右区间递增来看
//1.最右边两个数，如果新弹出区间包含两个，则直接看下一个区间
//2.如果新弹出的区间包含一个，那么肯定包含的是右边那个
//3.把原来右边的那个当成左边，再把区间右界的当成右边的
//4.如果都不包含，那么再新建  
//5.但3.有个条件，即原来右边的≠区间右边界
//6.所以在区间右界相等时，左界在右者优先，这样满足左界在右时，定能满足左界在左
//7.这样能直接满足1.，不用再判断5.的条件。
//8.如果不满足6.那么得加一条：当右界等于右边的时，左边的变为右界-1，总数+1
        int[] rec = {-1,-1};
        int res=0;
        for(int[] is : intervals){
            if(is[0]<=rec[0]){
                continue;
            }else if(is[0] <= rec[1]){
                res++;
                rec[0] = rec[1];
            }else{
                rec[0] = is[1]-1;
                res+=2;
            }
            rec[1] = is[1];
        }
        return res;
    }

*/
```
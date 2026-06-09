### 解题思路
1. 遍历所有点
2. 计算出经过每个点的所有直线的点数，取最大的点数line_max
3. 比较max与line_max
一开始用的是斜率值来存储每条直线的哈稀映射：<斜率值，点数>
但是斜率值用double也精度不够，不在同一个直线上的点计算出来的斜率值有可能因为精度不够而相同。
后来转换成分子分母来表示斜率，最直观的就像这样，用字符串格式来表示分子分母：
k=-0.5表示成"-1/2";k=2表示成"2/1"
当然，使用前必须先约分。
### 代码

```java
class Solution {
    /**获得最小公倍数**/
    private int gcd(int a,int b)
    {
        while(b!=0)
        {
            int temp=a%b;
            a=b;
            b=temp;
        }
        return a;
    }
    /**
    得到斜率，斜率标准格式：
    "符号"+"分子绝对值"+“/”+"分母绝对值"
    例如"-1/2","3/5"    
    **/
    private String getSlope(int[] point1,int[] point2)
    {
        int dx=point2[0]-point1[0];
        int dy=point2[1]-point1[1];
        if(dy==0)
            return "0";
        if(dx==0)
            return "infinity";
        int g=gcd(dx,dy);
        dx=dx/g;dy=dy/g;
        if(dx>0&&dy>0)
            return dy+"/"+dx;
        return "-"+Math.abs(dy)+"/"+Math.abs(dx);
    }
    public int maxPoints(int[][] points) {

        if(points.length<3)return points.length;
        Map<String,Integer> slopeMap=new HashMap<>();
        
        int max=1;
        for(int i=0;i<points.length;i++)
        {
            int[] node1=points[i];
            int extra=0,lineMax=1;
            slopeMap.clear();
            for(int j=i+1;j<points.length;j++)
            {
                int[] node2=points[j];
                //the same point,extra++/all line points++
                if(node2[0]==node1[0]&&node2[1]==node1[1])
                {
                    extra++;
                    continue;
                }

                String slope=getSlope(node1,node2);
                int times=slopeMap.getOrDefault(slope,0);
                if(times==0)
                {
                    times+=2;
                    slopeMap.put(slope,times);
                }
                else
                {
                    times++;
                    slopeMap.replace(slope,times-1,times);
                }
                lineMax=Math.max(lineMax,times);
            }
            max=Math.max(lineMax+extra,max);
            //System.out.println(slopeMap);
        }

        return max;

    }
}
```
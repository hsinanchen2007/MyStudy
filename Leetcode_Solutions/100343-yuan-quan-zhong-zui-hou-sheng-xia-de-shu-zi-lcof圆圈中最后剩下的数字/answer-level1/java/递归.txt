
10人环	0	1	2	3	4	5	6	7	8	9
9人环	6	7	8		0	1	2	3	4	5 减少一个人后，原位置上的人获得的新序号位置
8人环	2	3	4		5	6	7		0	1
7人环	6		0		1	2	3		4	5
6人环	2		3		4	5			0	1
5人环	4				0	1			2	3
4人环	0				1	2				3
3人环	0				1	2				
2人环					0	1				
1人环					0					
新位置：New =(old-position)%n
原来位置：Old= (new+position)%n
```
class Solution {
    public int lastRemaining(int n, int m) {
      if( n==1 )
            return 0;
        else
            return (lastRemaining(n-1,m)+m)%n;
    }
}
```

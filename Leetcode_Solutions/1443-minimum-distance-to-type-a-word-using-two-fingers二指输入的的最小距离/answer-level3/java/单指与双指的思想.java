### 解题思路
左指是较大的字母当前输入到的位数，右指是当前右指所在的位数，必定有左位数>右位数。且左右指不在同一位数上。
怎么从上一状态到这一状态呢？
1.由左指持续移动，则左指与当前最大位数紧邻，则右指（差至少为2）不进行移动。 由于紧邻直接加一，所以直接求值即可。
2.由右指移动到当前最大位置，则原来的左指（与当前最大值紧邻，可以作为右指直接变最大位数的跳板）不动，原来的左指变成右指，  由于有跳板，所以跳板前的所有位数情况均可直接到最大位数，有该情况下的最优解。

### 代码

```java
class Solution {
	
    public int minimumDistance(String word) {
    	
    	int result = 0;
    	int len = word.length();
    	if(len == 2) return result;
    	
    	int pos[][] = new int[len+1][len+1]; //使默认的左指所按下的最大位数能到达word的最大位数
    	pos[0][0] = 0; pos[1][0] = 0;
    	
    	//!!!!要按照word的顺序依次按下字母
    	for(int max = 2;max<=len;max++)//左指和右指在同一时刻不可能在同一位置
    		for(int min =0;min<max;min++) {
    			
    			if(max-1 != min)//右指的最小位数 不紧邻 max，max-->max，没有跳板
    				//只用到单指，又顺序输入，所以无局部最优解
    				pos[max][min] = pos[max-1][min]+distance(word.charAt(max-1),word.charAt(max-2));
    			
    			else //右指的最小位数 紧邻max, 任意min -->max,有此min作为跳板
    			{
    				//用到双指，有多种解法，有局部最优解
    				int mindis = Integer.MAX_VALUE;
    				for(int primary=0;primary<min;primary++) {//从原来没有按下(为0) 开始
    					int updis = primary==0?0:distance(word.charAt(primary-1),word.charAt(max-1));
    					mindis = Math.min(pos[min][primary] + updis, mindis) ;
    					
    				}
    				pos[max][min] = mindis;
    			}
    			
    			
    		}
    	
    	result = Integer.MAX_VALUE;
    	for(int i=0;i<len;i++)
    	result = Math.min(result, pos[len][i]);
    	
    	return result;
    	
    	
    }
    
    public int distance(char a,char b) {
    	int disA = a - 'A';
    	int disB = b - 'A';
    	int xA = disA/6; int yA = disA%6;
    	int xB = disB/6; int yB = disB%6;
    	return Math.abs(xA - xB)+Math.abs(yA - yB);
    }
}
    
```
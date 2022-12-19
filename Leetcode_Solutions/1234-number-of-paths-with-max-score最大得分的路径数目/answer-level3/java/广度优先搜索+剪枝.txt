比赛中我是通过广度优先搜索+状态标记强行撸过了这道题，后来赛后看了大家题解发现没人用广搜过的，于是这里我贴一下广搜的代码。
```
class Solution {
	
	class node{
		int x,y,val;
		public node(int x,int y,int val) {
			this.x=x;
			this.y=y;
			this.val=val;
		}
	}
	
	int[] dx= {0,-1,-1};
	int[] dy= {-1,0,-1};
	
    public int[] pathsWithMaxScore(List<String> board) {
        
    	Queue<node>q=new LinkedList<>();
    	//Map<Integer,Integer> map=new HashMap<>();
    	
    	int[] ans=new int[2];
    	int m=board.size(),maxvalue=-1;
    	int[][] sum=new int[m][m];
    	int[][] flag=new int[m][m];
    	sum[m-1][m-1]=1;
    	q.add(new node(m-1,m-1,0));
    	while(!q.isEmpty()) {
    		node now=q.poll();
    		if(board.get(now.x).charAt(now.y)=='E') {
    			//map.put(now.val,(map.getOrDefault(now.val, 0)+1)%1000000007);
    			//maxvalue=Math.max(maxvalue, now.val);
    			continue;
    		}
    		for(int i=0;i<3;i++) {
    			int x=now.x+dx[i];
    			int y=now.y+dy[i];
    			if(x<0 || y<0 || board.get(x).charAt(y)=='X') continue;
    			//System.out.println(now.val+board.get(x).charAt(y)-'0');
    			if(board.get(x).charAt(y)=='E') {
    				if(now.val>maxvalue) {
    					sum[x][y]=sum[now.x][now.y];
    					maxvalue=now.val;
    				}
    				else if(now.val==maxvalue) {
    					sum[x][y]=(sum[x][y]+sum[now.x][now.y])%1000000007;
    					continue;
    				}
    				q.add(new node(x,y,now.val));
    			}
    			else if(flag[x][y]<=now.val+board.get(x).charAt(y)-'0') {
    				if(flag[x][y]==now.val+board.get(x).charAt(y)-'0')
    					sum[x][y]=(sum[x][y]+sum[now.x][now.y])%1000000007;
    				else {
    					sum[x][y]=sum[now.x][now.y];
    					q.add(new node(x,y,now.val+board.get(x).charAt(y)-'0'));
    					flag[x][y]=now.val+board.get(x).charAt(y)-'0';
    				}
    			}
    		}
    	}
    	if(maxvalue==-1) {
    		ans[0]=ans[1]=0;
    	}
    	else {
    		ans[0]=maxvalue;
    		ans[1]=sum[0][0];
    	}
    	return ans;
    }
}
```

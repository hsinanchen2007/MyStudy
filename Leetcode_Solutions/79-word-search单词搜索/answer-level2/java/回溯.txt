
执行用时 :6 ms, 在所有 Java 提交中击败了98.92%的用户
内存消耗 :39 MB, 在所有 Java 提交中击败了96.26%的用户

删掉注释可以看控制台输出
```
class Solution {
    public boolean exist(char[][] board, String word) {
    	if(board.length==0)return false;
		//初始化
		char[][] temp=new char[board.length][];
		for(int k=0;k<board.length;k++){
			temp[k]=board[k].clone();
		}
    	for(int j=0;j<board.length;j++){
    		for(int i=0;i<board[j].length;i++){
    			//System.out.println("start at: "+"("+i+", "+j+")");
        		if(back(temp,word,i,j,0,0,board)==1)return true;
        		//System.out.println("--------------------");
    		}
    	}
    	return false;
    }

    public int back(char[][] temp,String word,int x,int y,int p1,int ok,char[][] board){
    	//System.out.println("("+x+", "+y+")");
    	char t=temp[y][x];
    	if(board[y][x]==word.charAt(p1)){
    		temp[y][x]='1';
    		ok=1;
    		//System.out.println("get "+word.charAt(p1));
    		if(p1==word.length()-1)
    		return 1;
    		else {
    			p1++;
    		}
    	}
    	else {
    		//System.out.println(board[y][x]+" don't match "+word.charAt(p1));
    		ok=0;
    	}
    	if(ok==1){
    		ok=0;

			//右
			if(x+1<board[y].length){
				if(temp[y][x+1]!='1'){
					ok=back(temp,word,x+1,y,p1,1,board);
				}
			}
			if(ok==1)return 1;

			//上
			if(y-1>-1){
				if(temp[y-1][x]!='1'){
		    		ok=back(temp,word,x,y-1,p1,1,board);
				}
			}
			if(ok==1)return 1;

			//下
			if(y+1<board.length){
				if(temp[y+1][x]!='1'){
		    		ok=back(temp,word,x,y+1,p1,1,board);
				}
			}
			if(ok==1)return 1;

			//左
			if(x-1>-1){
				if(temp[y][x-1]!='1'){
		    		ok=back(temp,word,x-1,y,p1,1,board);
				}
			}
			if(ok==1)return 1;
    	}
    	temp[y][x]=t;
    	return 0;
    }
}
```

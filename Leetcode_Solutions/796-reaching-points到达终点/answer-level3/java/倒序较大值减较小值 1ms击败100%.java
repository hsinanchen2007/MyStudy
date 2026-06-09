倒序如何操作可以去参考精选题解。我最开始的代码中是用较大值减去较小值，不断的循环。但是在测试中1 3 1000000000 3这个例子过不了，原因是超时，因为1000000000减去3要循环很久。因此我改进了代码。
```
class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
    	while(tx>=sx&&ty>=sy){
    		if(tx==sx&&ty==sy)
    			return true;
    		if(tx>ty){
    			int mid= (tx-sx)/ty;
    			tx=tx-ty*(mid==0?1:mid);
    		}
    		else{
    			int mid=(ty-sy)/tx;
    			ty=ty-tx*(mid==0?1:mid);
    		}
    	}
    	return false;
    }	
}
```

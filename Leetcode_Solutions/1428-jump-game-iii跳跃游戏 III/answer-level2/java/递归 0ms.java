```
class Solution {
	
	public boolean canReach(int[] arr, int start) {
		
		 if(canReach1(arr,start)){return true;}
		 else{return false;}
	}
    public boolean canReach1(int[] arr, int start) {
    	int len=arr.length;
    	if(start<0||start>=len){return false;}
    	if(arr[start]==-1){return false;}
      if(arr[start]==0){return true;}
      int tem=arr[start];
      arr[start]=-1;
      if(canReach(arr,start+tem))
      {	arr[start+tem]=-1;
    	  return true;
      }
      if(canReach(arr,start-tem))
      {arr[start-tem]=-1;
    	  return true;}
    return false;
    }
}
```
速度好像还挺快的，，，
刚开始接触编程，还望勿喷。。。
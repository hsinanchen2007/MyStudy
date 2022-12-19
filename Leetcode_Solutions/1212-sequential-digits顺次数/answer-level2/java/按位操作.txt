```
class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        
    	int len=0,sum=0,num=0;
    	List<Integer> list=new ArrayList<>();
    	for(int k=1;k<=9;k++) {
    		sum=0;
	    	for(int i=k;i<=9;i++){
	    		num=0;
	    		sum=sum*10+i;
	    		//for(int j=0;j<i;j++) num=num*10+1;
	    		if(sum>=low && sum<=high && !list.contains(sum)) {
	    			list.add(sum);
	    			int tmp=sum;
			    	while(tmp<=high && tmp%10+1<10) {
			    		int x=work(tmp,tmp%10+1);
			    		if(x<=high) list.add(x);
			    		tmp=x;
			    		if(tmp%10==9) break;
			    	}
	    		}
	    	}
    	}
    	Collections.sort(list);
    	return list;
    } 
    
    private int work(int x,int y) {
    	int xx=0;
    	while(x>10) {
    		xx=xx*10+x%10;
    		x/=10;
    	}
    	//xx=xx*10+y;
    	int yy=0;
    	while(xx>0) {
    		yy=yy*10+xx%10;
    		xx/=10;
    	}
    	yy=yy*10+y;
    	return yy;
    }
}
```

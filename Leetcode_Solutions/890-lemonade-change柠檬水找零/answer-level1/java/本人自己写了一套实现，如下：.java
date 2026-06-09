public static boolean findZero(int[] queue) {
	        int a5=0;int a10=0;int a20=0;
	        for(int i=0;i<queue.length;i++){
            	int le = queue[i]-5;
            	while(a10>0 && le>=10){
            		le -= 10;
            		a10--;
            	}
            	while(a5>0 && le>=5){
            		le -= 5;
            		a5--;
            	}
            	if(queue[i]==5){
	            	a5++;
	            }else if(queue[i]==10){
	            	a10++;
	            }else{
            	    a20++;
	            }
                if(le==0){
            		continue;
            	}else{
            		System.out.println("le="+le);
            		System.out.println("a5="+a5+";a10="+a10+";a20="+a20);
            		return false;
            	}
            }
	        System.out.println("leftAmt="+(a5*5+a10*10+a20*20));
	        return true;
	    }
### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    static Set<String> results;

    public static List<String> readBinaryWatch(int num) {
    	if(num==0){
    		ArrayList value= new ArrayList<String>();
            value.add("0:00");
            return value;
    	}
    	results=new HashSet<String>();
    	int total=0;
    	int [] time=new int[10];
        for(int i=1;i<((1<<10));i++){
        	time=new int[10];
        	int temp=i;
        	total=0;
        	for(int j=0;j<10;j++){
        		if((i>>j&1)==1){
        			time[j]=1;
        			total++;
        		}
        	}
        	int hour=0;
        	int mint=0;
            if(total>num){
                continue;
            }
        	if(total==num){
        		for(int h=6;h<time.length;h++){
        			if(time[h]==1){
        				hour+=1<<(h-6);
        			}
        		}
        		for(int m=0;m<6;m++){
        			if(time[m]==1){
        				mint+=(1<<(m));
        			}
        		}
        		if(hour<12&&mint<60){
        			StringBuffer sb = new StringBuffer();
        			Integer hou=hour;
        			Integer min=mint;
                    if(hour==12){
                        sb.append("0");
                    }else{
                        sb.append(hou.toString());
                    }
        			sb.append(":");
        			if(min<10){
        				sb.append("0");
        				sb.append(min.toString());
        			}else{
        				sb.append(min);
        			}
        			results.add(sb.toString());
        		}
        	}
        }
        return new ArrayList<String>(results);
    }
}
```
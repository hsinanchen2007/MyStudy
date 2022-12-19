
```
a b c d e
f g h i j
k l m n o 
p q r s t 
u v w x y 
z
```

```
class Solution {
    public String alphabetBoardPath(String target) {
        int x = 0,y = 0,dx = 0,dy = 0;
		
		StringBuilder build = new StringBuilder();
		
		for (int i = 0;i < target.length();i++){
            // 转变为0-25
			int temp = target.charAt(i) - 'a';
			
			dx = temp / 5;
			dy = temp % 5;
            // 优先x(// 因为有z行不全，所以优先级为向上和向左)
			if(dy < y){
				for(int j=0;j<y -dy;j++){build.append("L");}
			}
			if(dx < x){
				for(int j=0;j<x - dx;j++){build.append("U");}
			}
			if(dx > x){
				for(int j=0;j<dx -x;j++){build.append("D");}
			}
			if(dy > y){
				for(int j=0;j<dy - y;j++){build.append("R");}
			}
			build.append("!");
			
			x = dx;
			y = dy;
		}
		
		return build.toString();
    }
}
```

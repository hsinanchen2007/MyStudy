```
public static int[] asteroidCollision(int[] asteroids) {
		Stack<Integer> stack = new Stack<Integer>();
		for(int i=0;i<asteroids.length;i++){
			if(stack.isEmpty()){
				stack.push(asteroids[i]);
			}else{
				if((stack.peek() * asteroids[i] ) > 0){//同向，永不碰撞
					stack.push(asteroids[i]);
				}else{//会碰撞
					if(Math.abs(stack.peek()) > Math.abs(asteroids[i])){
						
						if(stack.peek()<0){
							stack.push(asteroids[i]);
						}else{
							//不处理
						}
					}else if(Math.abs(stack.peek()) < Math.abs(asteroids[i])){
						if(stack.peek()<0){
							stack.push(asteroids[i]);
						}else{
							stack.pop();
							while(true){
								if(!stack.isEmpty()){
									if((stack.peek() * asteroids[i] ) > 0){
										stack.push(asteroids[i]);
										break;
									}else{
										if(Math.abs(stack.peek()) > Math.abs(asteroids[i])){
											if(stack.peek()<0){
												stack.push(asteroids[i]);
											}else{
												//不处理
											}
											break;
										}else if(Math.abs(stack.peek()) < Math.abs(asteroids[i])){
											if(stack.peek()<0){
												stack.push(asteroids[i]);
											}else{
												stack.pop();//继续while循环
											}
											
										}else if(Math.abs(stack.peek()) == Math.abs(asteroids[i])){
											if(stack.peek() < 0){//方向相反不用管
												stack.push(asteroids[i]);
											}else{
												stack.pop();
											}
											break;
										}
									}
								}else{
									stack.push(asteroids[i]);
									break;
								}
							}
						}
						
						
					}else if(Math.abs(stack.peek()) == Math.abs(asteroids[i])){//抵消
						if(stack.peek() < 0){//方向相反不用管
							stack.push(asteroids[i]);
						}else{
							stack.pop();
						}
						
					}
				}
			}
		}
		int[] res = new int[stack.size()];
		int i= stack.size()-1;
		while(!stack.isEmpty()){
			res[i] = stack.pop();
			i--;
		}
		return res;
    }
```

### 解题思路
纯用栈，有点复杂，实在是不会map

### 代码

```java
class Solution {
    public boolean isValid(String s) {

        char x='(';
		char x1=')';
		char z='[';
		char z1=']';
		char d='{';
		char d1='}';
		if(s.equals("")){
            return true;
        }
		char arr[]=s.toCharArray();
		
		Stack<Character> stack=new Stack<Character>();
		
		for(int i=0;i<=arr.length-1;i++){
			if(arr[i]==x||arr[i]==z||arr[i]==d){
				stack.push(arr[i]);
				 continue;
			}else{
                if(stack.empty()){
                    return false;
                }
            }
			char peek=stack.peek();
			if(arr[i]==x1){
				if(peek==x){
					stack.pop();
				}else{
                    return false;
                }

			}
			if(arr[i]==z1){
				if(peek==z){
					stack.pop();
				}else{
                    return false;
                }	
			}
			if(arr[i]==d1){
				if(peek==d){
					stack.pop();
				}else{
                    return false;
                }
			}
			
			
		}
		return stack.empty();
    }
}
```
### 解题思路
由于只有四个方向，那么可以得知如果能回到原点，那么执行4次必然能够回到原点

### 代码

```java
class Solution {
    public boolean isRobotBounded(String instructions) {
          String str =instructions+instructions+instructions+instructions;
        int x=0;
        int y=0;
        int flag = 0;
		for(int i=0;i<str.length();i++) {
			char ch =str.charAt(i);
			switch(ch) {
				case('G'):
					switch(flag) {
					case(0):
						x++;
						break;
					case(1):
						y++;
						break;
					case(2):
						x--;
						break;
					case(3):
						y--;
					}
					break;
				case('L'):
					if(flag==0) {
						flag=3;
					}else {
						flag--;
					}
					break;
				case('R'):
					if(flag==3) {
						flag=0;
					}else {
						flag++;
					}
			}
		}		
		return x==0&&y==0;			
    }
}
```
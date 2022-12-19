### 解题思路
如果能理解前面那个4倍字符串的话，可以进一步理解一次退出条件了。一次直接回到原点和结束时的方向不同于初始条件为两种符合的路径[https://blog.csdn.net/qq_23134039/article/details/103425589]()

### 代码

```java
class Solution {
    public boolean isRobotBounded(String instructions) {
        int x=0;
        int y=0;
        int flag = 0;  //方向判断 0右 1下 2左 3上
		for(int i=0;i<instructions.length();i++) {
			char ch =instructions.charAt(i);
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
		return (x==0&&y==0)||flag!=0;			
				
    }
}
```
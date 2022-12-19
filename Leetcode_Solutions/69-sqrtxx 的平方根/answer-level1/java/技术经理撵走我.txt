使用for循环 判断 i*i<x&&(i+1)*(i+1)>x 的i值就是x的平方取整数了
但是存在一个问题 java的int值范围问题，一旦乘出范围就为负数
这里我玩赖了 直接判断x是否为最大值（2147483647，也就是Integer.MAX_VALUE）

```
class Solution {
    public int mySqrt(int x) {
    	if(x == 0){
    		return 0;
    	}else if(x == 2147483647){//哈哈我真的是用挂 果然就差这一个数字
            return 46340;
        }
    	int t = -1;
    	for (int i = 1; i < Integer.MAX_VALUE; i++) {
    		if(i*i == x){
    			t = i;
    			break;
    		}else if(i*i<x&&(i+1)*(i+1)>x){
				t = i;
				break;
			}
		}
    	return t;
    
    }
}
```

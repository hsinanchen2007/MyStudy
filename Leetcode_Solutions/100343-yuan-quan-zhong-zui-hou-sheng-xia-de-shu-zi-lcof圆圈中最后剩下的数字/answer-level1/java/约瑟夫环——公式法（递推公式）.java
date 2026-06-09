### 解题思路
这题只要搞懂约瑟夫环就太简单了：https://blog.csdn.net/u011500062/article/details/72855826
利用约瑟夫环的逆推就能求出最后一个幸存者在初始环中的下标

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
    	int index=0; 
    	for (int i = 2; i < n+1; i++) {
			index =(index+m)%i;
		}
    	return index;

    }
}
```
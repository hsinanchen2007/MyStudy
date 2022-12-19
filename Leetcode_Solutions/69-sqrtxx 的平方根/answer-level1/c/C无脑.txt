### 解题思路
无脑解答

### 代码

```c
#define MAX_SQTNUM 46340
int mySqrt(int x){
	for(int i=0;;i++){
        if(i>46340){
            return 46340;
        }
		if(i*i>x){
			return i-1;
		}
    }
}
```
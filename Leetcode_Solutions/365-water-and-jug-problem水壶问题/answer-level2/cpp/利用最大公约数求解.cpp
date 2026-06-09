### 解题思路
ax+by=z有解等价于求x，y的最大公约数的倍数
![微信图片_20200321231014.png](https://pic.leetcode-cn.com/2a05a552d59f49aa2ef446ea95ccd26db2023a2be60ef8d4079fc924a8c8a81c-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200321231014.png)

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
	int num=0; 
    if(z>(x+y)) 	return false;
    if(z==0||z==x||z==y) 	return true;
    //辗转相除 求最大公约数
	if(x<y) num=GCD(x,y);
	if(x>y) num=GCD(y,x);
	if(z%num==0) return true;
	else return false;
}

int GCD(int num1,int num2){
	int tmp;
    int i=num1;
	while(i--){
		tmp=num1%num2;
        if(tmp==0) break;
        num1=num2;
        num2=tmp;
	}  
return num2;
}
};
```
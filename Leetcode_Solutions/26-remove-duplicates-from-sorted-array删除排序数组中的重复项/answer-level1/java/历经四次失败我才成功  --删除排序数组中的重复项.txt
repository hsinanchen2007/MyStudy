说实话我是刚开始没有想到双指针，但是当我的方法交了四次都是失败我才看了一下官方的方法，然后看到了双指针之后立马自己再写一遍是真的简单
```
代码块
if(a.length==0) {return 0;}
		int slow = 0;
		for(int fast=0;fast<a.length;fast++) {
			if(a[fast]!=a[slow]) {
				slow++;
				a[slow] = a[fast];
			}
		}
		return ++slow;
```
我是感觉绝了，看来遍历这一块这一定要记好啊

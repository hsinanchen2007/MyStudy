### 直接列举所有假的情况，剩余的全为真
![image.png](https://pic.leetcode-cn.com/18af68bc7d08f10446efe4e7d665a070f8b926b368d4bab9387d91fc1a735694-image.png)

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if(rec1[0]==rec1[2]&&rec1[1]==rec1[3])  return false;
    if(rec2[0]==rec2[2]&&rec1[1]==rec2[3])  return false;
	bool x1 = rec1[2]<=rec2[0];
	bool x2 = rec1[0]>=rec2[2];
	bool y1 = rec1[3]<=rec2[1];
	bool y2 = rec1[1]>=rec2[3];
	if(x1||x2||y1||y2)
		return false;
	else
		return true;
}
```
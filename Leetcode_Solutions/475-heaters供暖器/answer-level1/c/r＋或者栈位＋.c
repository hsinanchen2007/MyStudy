### 解题思路
先递增排序（这个排序算法如果不好，容易超时）
如果房子在暖器的半径内，看下一个房子是否也是同样满足
如果不满足，比较当前房子与当前暖器的距离a和同下一暖器的距离b，那个小；如果a小那么把半径值为a。
否则看下一个暖器。


### 代码

```c
int cmq(const void *ca, const void *cb){
	return *(int*)ca - *(int*)cb;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
if (housesSize < 1 || heatersSize < 1)
    return 0;
qsort(heaters, heatersSize, sizeof(int), cmq);
qsort(houses, housesSize, sizeof(int), cmq);
int i=0,j=0,a,b;
int r=0;
while(i<housesSize){
    if((houses[i]<=heaters[j]+r)&&(houses[i]>=heaters[j]-r))i++;
    else {
        a=(houses[i]>heaters[j])?(houses[i]-heaters[j]):(heaters[j]-houses[i]);
        b=a;
        if(j+1<heatersSize)
            b=(houses[i]>heaters[j+1])?(houses[i]-heaters[j+1]):(heaters[j+1]-houses[i]);
        if((a<b)||(j+1==heatersSize))r=a;
        else j++;
    } 
}
return r;
}
```
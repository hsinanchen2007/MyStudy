### 解题思路
利用反向思维，判断哪些情况返回false。
首先确定rec1为靠左的矩形。
然后判断两矩形哪种情况不相交：
1: rec2左沿相比rec1右沿靠右
2: rec2下沿高于rec1上沿；
3: rec2上沿低于rec1下沿
其余情况两矩形均相交。 

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if(rec1[0]>rec2[0] ){
        int t=0;
        for(int i =0;i<4;i++){
            t = rec1[i];
            rec1[i] = rec2[i];
            rec2[i] = t;
        }
    }   //保证rec1为靠左矩形
    if(rec2[0] >= rec1[2])
        return false;           //rec2左沿相比rec1右沿靠右
    else if(rec2[1] >= rec1[3])
        return false;           //rec2下沿高于rec1上沿
    else if(rec2[3] <= rec1[1])
        return false;           //rec2上沿低于rec1下沿
    else
        return true;
}
```
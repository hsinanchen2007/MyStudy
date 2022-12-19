### 解题思路
此处撰写解题思路
c语言版，跨专业初学不会c++
先画一个矩形，然后考虑怎么画第二个让他们不想交
### 代码
```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if(rec1[0]>=rec2[2]||rec1[1]>=rec2[3]||rec1[2]<=rec2[0]||rec1[3]<=rec2[1]){
        return false;
    }else{
        return true;
    }
}
```
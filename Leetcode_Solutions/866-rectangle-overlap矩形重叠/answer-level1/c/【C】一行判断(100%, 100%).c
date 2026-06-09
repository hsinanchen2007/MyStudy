判断4种越界条件即可
![image.png](https://pic.leetcode-cn.com/7feb80fa147f2c705b4cb13e15fb2a8cb50edea27f8f081cfacdd4b279a31feb-image.png)
```
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if (rec1[0] >= rec2[2] || rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec1[3] <= rec2[1]) {
        return false;
    }
    return true;
}
```






### 代码
```
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left_x = max(A,E),left_y = max(B,F);
        int right_x = min(C,G),right_y = min(D,H);
        int w_iou = right_x>left_x?right_x-left_x:0; // w_iou = max(0,right_x-left_x);
        int h_iou = right_y>left_y?right_y-left_y:0;  // h_iou = max(0,right_y,left_y);
        int s1 = (C-A)*(D-B),s2 = (G-E) * (H-F);
        return s1 - w_iou*h_iou + s2;   //返回值要先减去，否则s1+s2存在测试用例超int
    }
};
```

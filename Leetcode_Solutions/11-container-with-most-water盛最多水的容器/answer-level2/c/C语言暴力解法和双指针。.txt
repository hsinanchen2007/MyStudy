### 解题思路
时间击败5%，内存100。
就是简单的i=0，j=i+1嵌套循环
比较最大值，令max等于大的。

第二种方法双指针
时间94，内存100.
一个l一个r.
比较max和现在的容量，max取大的。
之后比较左右两个高度，低的向内移。

### 代码

```c
int maxArea(int* height, int heightSize){
    int max=0;
    for(int i=0;i<heightSize;i++){
        for(int j =i+1;j<heightSize;j++){
            int x = j-i;
            int y = height[j]>height[i]?
                    height[i]:height[j];
            if((x*y)>max)
                max = x*y;
        }
    }
    return max;
}

//第二种
//int maxArea(int* height, int heightSize){ --> --> -->
//  int max=0;
//    int l=0,r=heightSize-1;
//    while(l<r){
//        int x = r-l;
//        int y = height[l]>height[r]?
//                height[r]:height[l];
//        if((x*y)>max)
//            max = x*y;
//        if(y==height[l]) l++;
//        else r--;
//    }
//   return max;
//}

```
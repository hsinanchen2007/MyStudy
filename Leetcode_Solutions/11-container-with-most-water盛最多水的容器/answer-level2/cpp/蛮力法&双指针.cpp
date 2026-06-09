## 蛮力法
蛮力法运行超时
```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i, j, len = height.size();
        int maxRes = 0;
        for( i=0; i<len-1; i++)
            for( j=i+1; j<len; j++)
                maxRes = max( maxRes, min(height[i],height[j])*(j-i) );
        return maxRes;
    }
};
```

## 双指针
左右指针，向着当前数值更大的一方移动
```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int left = 0, right = len-1;
        int maxRes = 0;
        while( left < right )
        {
            maxRes = max(maxRes, (right-left)*min(height[left], height[right]));
            if( height[left] < height[right] )
                left++;
            else
                right--;
        }
        return maxRes;
    }
};
```

### 左右指针移动错误
1. 哪边下一个数值大，则移动；
```
if( left+1 < right )
{
    if( height[left+1] > height[right-1] )
        left++;
    else
        right--;
}
else
    return max;
```

2. 哪边移动后构成的面积更大，则实行移动；
```
 int findone(vector<int>& height, int left, int right){
    if( left < right )
    {
        int minone = height[left]<height[right]?height[left]:height[right];
        return (right - left) * minone;
    }
    else return 0;
}

int leftRes = findone(height, left+1, right);
int rightRes = findone(height, left, right-1);
if( leftRes > rightRes )
    left++;
else
    right--;
```